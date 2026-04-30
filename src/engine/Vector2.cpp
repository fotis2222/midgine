#include <engine/Vector2.hpp>
#include <cmath>

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
    return Vector2(x / scalar, y / scalar);
}

float Vector2::dot(const Vector2& other) const {
    return x * other.x + y * other.y;
}

float Vector2::length() const {
    return std::sqrt(x * x + y * y);
}
