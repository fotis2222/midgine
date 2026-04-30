#include <engine/Game.hpp>

void Game::update(float dt) {
    // your code here
}

void Game::render() {
    draw.DrawRectangle(200, 200, 200, 200, RED);
    draw.DrawTriangle(
        {0, 0},
        {100, 100},
        {0, 100},
        BLUE
    );

    draw.DrawCircle(100, 400, 400, GREEN);
    draw.EndDrawing();
}
