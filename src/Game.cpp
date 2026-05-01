#include <engine/Game.hpp>

float x = 400;

void Game::update(float dt) {
    x += 100 * dt;
}

void Game::render() {
    draw->ClearBG(BLACK);
    draw->DrawRectangle(200, 200, 200, 200, ORANGE);
    draw->DrawTriangle(
        {0, 0},
        {100, 100},
        {0, 100},
        MAGENTA
    );

    draw->DrawCircle(100, x, 400, YELLOW);
    draw->EndDrawing();
}
