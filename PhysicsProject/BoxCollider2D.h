#pragma once
#include <SFML/System/Vector2.hpp>


#include "Collider2D.h"

class Scene;

class BoxCollider2D : public Collider2D
{
public:
    BoxCollider2D(const sf::Vector2f& position, const sf::Vector2f& size, Scene* scene, double SCALE);

    void SetSize(const sf::Vector2f& size);
    sf::Vector2f GetSize() const;

private:
    sf::Vector2f m_size;
};
