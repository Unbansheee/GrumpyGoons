#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Actor.h"
#include <SFML/Graphics/Texture.hpp>

class Camera;
class Ball;

class Catapult : public Actor
{
public:
    void OnConstruct() override;
    void BeginPlay() override;
    void FixedUpdate(float deltaTime) override;
    void Update(float deltaTime) override;
    void Draw() override;
    void OnDestroy() override;
    
    Camera* cam;

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::RectangleShape m_rope;
    sf::Vector2f pivot;


    
    Ball* m_ball = nullptr;
    bool m_primed = false;
};
