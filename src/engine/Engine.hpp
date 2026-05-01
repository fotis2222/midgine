#pragma once
#include <SDL3/SDL.h>
#include <array>
#include <memory>
#include <string>
#include <engine/Drawing.hpp>
#include <engine/Engine.hpp>
#include <memory>

class Engine {
    public:
        Engine();
        ~Engine();
        void run();
        bool init();
        void shutdown();
        void set_resolution(const std::array<int, 2>& resolution);
        void set_title(const std::string& t);
        std::unique_ptr<Drawing> draw = nullptr;
    protected:
        virtual void update(float dt);
        virtual void render();
    private:
        std::string title = "Window";
        std::array<int, 2> resolution = {800, 600};
        bool running;
        SDL_Window *window;
        SDL_Renderer *renderer;
};
