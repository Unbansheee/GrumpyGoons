#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Actor.h"
#include "BoxCollider2D.h"


class Ground : public Actor
{
public:
    void OnConstruct() override;
    void BeginPlay() override;
    void FixedUpdate(float deltaTime) override;
    void Update(float deltaTime) override;
    void Draw() override;
    void OnDestroy() override;

private:
    sf::RectangleShape shape;
    BoxCollider2D* collider;
};
