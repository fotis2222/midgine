#include <engine/Engine.hpp>

Engine::Engine() {}

Engine::~Engine() {
    shutdown();
}

bool Engine::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) return false;
    
    window = SDL_CreateWindow(title.c_str(), resolution[0], resolution[1], 0);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) return false;
    
    running = true;
    return true;
}

void Engine::run() {
    while (running) {
        render();
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }
        update(0.016f);
        SDL_Delay(16);
    }
}

void Engine::shutdown() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::set_resolution(const std::array<int, 2>& res) {
    resolution = res;
}

void Engine::set_title(const std::string& t) {
    title = t;
}

void Engine::update(float dt) { }
void Engine::render() { }