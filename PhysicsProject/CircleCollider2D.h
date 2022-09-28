#pragma once
#include <SFML/System/Vector2.hpp>

#include "Collider2D.h"

class Scene;
class CircleCollider2D : public Collider2D
{
public:
    CircleCollider2D(sf::Vector2f position, float radius, Scene* scene, double SCALE);

    void SetRadius(float radius);
    float GetRadius() const;

    
private:
    
};
