# midgine
This is a small game engine that I created built using SDL3. This is a project that I am using to improve my C++ skills, so expect rough edges and extremely frequent updates.

## installation
midgine requires SDL3. It is a submodule of this repo, so you can get it as well using:
```sh
git clone --recursive https://github.com/fotis2222/midgine
```
Then, build normally with CMake.

## usage
The main functionality of the engine comes from the `src/engine/game.cpp` file. You will find a setup that looks like this:
```cpp
#include <engine/Game.hpp>

void Game::update(float dt) {
    // your code here
}

void Game::render() {
    // your code here
}
```
These two functions are called once every every frame (targeting ~60 FPS), so you can write your code in there. You can call raw SDL3 functions, but you can also use my shorthands. The `window` and `renderer` pointers are private variables of the `Game` class, so you can use them at will.
