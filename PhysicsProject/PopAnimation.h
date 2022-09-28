#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Actor.h"
#include "Ticker.h"

class PopAnimation : public Actor
{
public:
    PopAnimation();
    void Update(float deltaTime) override;
    void OnConstruct() override;
    void Play(sf::Color color = sf::Color::White, float duration = 1.f, float scale = 1.f, float speed = 200.f);
    void BeginPlay() override;
    void OnDestroy() override;
    void Draw() override;
    std::vector<sf::RectangleShape> shapes;
    Ticker deathTimer;
    float m_scale = 1.f;
    float m_speed = 200.f;
};
