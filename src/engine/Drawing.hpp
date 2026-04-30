#pragma once
#include <SDL3/SDL.h>
#include <array>
#include <engine/Vector2.hpp>
#include <math.h>

#define PI 3.14159f
#define RED {255, 0, 0, SDL_ALPHA_OPAQUE}
#define GREEN {0, 255, 0, 255}
#define BLUE {0, 0, 255, 255}

typedef std::array<int, 4> Color;

class Drawing {
public:
    Drawing(SDL_Renderer* renderer);
    void DrawRectangle(float x, float y, float w, float h, Color color);
    void DrawTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, Color color);
    void DrawCircle(float radius, float x, float y, Color color);
    void EndDrawing();
private:
    SDL_Renderer* renderer;
};
