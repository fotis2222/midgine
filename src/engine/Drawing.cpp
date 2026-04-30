#include <engine/Drawing.hpp>

Drawing::Drawing(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

void Drawing::DrawRectangle(float x, float y, float w, float h, Color color) {
    SDL_FRect rect {x, y, w, h};

    SDL_SetRenderDrawColor(
        renderer,
        static_cast<Uint8>(color[0]),
        static_cast<Uint8>(color[1]),
        static_cast<Uint8>(color[2]),
        static_cast<Uint8>(color[3])
    );

    SDL_RenderFillRect(renderer, &rect);
}

void Drawing::DrawTriangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, Color color) {
    std::array<SDL_Vertex, 3> verts;

    verts[0].position = {p1.x, p1.y};
    verts[1].position = {p2.x, p2.y};
    verts[2].position = {p3.x, p3.y};

    SDL_FColor fcolor = {
        color[0] / 255.0f,
        color[1] / 255.0f,
        color[2] / 255.0f,
        color[3] / 255.0f
    };

    for (auto& i : verts) {
        i.color = fcolor;
    }

    SDL_RenderGeometry(renderer, nullptr, verts.data(), 3, nullptr, 0);
}

void Drawing::DrawCircle(float radius, float x, float y, Color color) {
    int segments = 50;
    float step = 2 * PI / segments;

    for (int i = 0; i < segments; ++i) {
        float theta = i * step;
        float thetaNext = (i + 1) * step;

        float x1 = x + radius * cos(theta);
        float y1 = y + radius * sin(theta);

        float x2 = x + radius * cos(thetaNext);
        float y2 = y + radius * sin(thetaNext);

        DrawTriangle(
            {x, y},
            {x1, y1},
            {x2, y2},
            color
        );
    }
}

void Drawing::EndDrawing() {
    SDL_RenderPresent(renderer);
}
