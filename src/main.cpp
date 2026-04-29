#include <SDL3/SDL.h>
#include <engine/Engine.hpp>
#include <engine/Game.hpp>
#include <memory>

int main(int argc, char* argv[]) {
  std::unique_ptr<Engine> engine = std::make_unique<Game>();
  
  engine->set_title("i love cookies lol");

  if (!engine->init()) return -1;
  
  engine->run();

  return 0;
}
