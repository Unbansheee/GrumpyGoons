#pragma once


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Actor.h"
#include "CircleCollider2D.h"
#include <future>

#include "Camera.h"
#include "TimedCallback.h"

class Catapult;

class Ball : public Actor
{
public:
    void OnConstruct() override;
    void BeginPlay() override;
    void FixedUpdate(float deltaTime) override;
    void Update(float deltaTime) override;
    void Draw() override;
    void OnDestroy() override;

    void SetSimulatingPhysics(bool simulatingPhysics);
    bool IsSimulatingPhysics() const;

    void ApplyForce(const sf::Vector2f& force);

    virtual void Fire(const sf::Vector2f& force, Catapult* catapult, Camera* camera);
protected:
    CircleCollider2D* m_collider = nullptr;
    sf::CircleShape m_circle;
    sf::Sprite m_sprite;
    bool m_simulatingPhysics = true;
    sf::Texture m_Texture;
    bool isDying = false;
    std::unique_ptr<TimedCallback> m_startDestroyTimer;
    Camera* cam;
    Catapult* cat;
    bool fired = false;
};
