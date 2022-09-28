#pragma once
#include "Ball.h"

class BombBall : public Ball
{
public:
    void OnConstruct() override;
    void Fire(const sf::Vector2f& force, Catapult* catapult, Camera* camera) override;
};
