#include <SDL3/SDL.h>

void process(bool &running) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT) running = false;
  }
}

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow(
    "what",
    800, 600,
    0
  );

  bool running = true;

  while (running) {
    process(running);
    SDL_Delay(16);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}
