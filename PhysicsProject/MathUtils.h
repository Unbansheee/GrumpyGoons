#pragma once
#include <SFML/System/Vector2.hpp>
#include <cmath>

inline float VectorLength(const sf::Vector2f& v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

inline float Ease(float a, float b, float alpha)
{
    return a + (b - a) * alpha;
}

inline float Lerp(float a, float b, float alpha)
{
    return a + (b - a) * alpha;
}