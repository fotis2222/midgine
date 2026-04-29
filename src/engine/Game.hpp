#pragma once
#include <SDL3/SDL.h>
#include <engine/Engine.hpp>

class Game : public Engine {
    protected:
        void update(float dt) override;
        void render() override;
};