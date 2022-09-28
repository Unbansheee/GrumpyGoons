#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Actor.h"
#include "BoxCollider2D.h"

class FallingBlock : public Actor
{
public:
    void BeginPlay() override;
    void FixedUpdate(float deltaTime) override;
    void Update(float deltaTime) override;
    void Draw() override;
    void OnDestroy() override;
    void OnConstruct() override;
    void SetSize(sf::Vector2f size);
    void SetWeight(float weight);

private:
    sf::RectangleShape shape;
    BoxCollider2D* collider = nullptr;
};
