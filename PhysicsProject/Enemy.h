#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Actor.h"
#include "CircleCollider2D.h"

class Enemy : public Actor
{
public:
    void OnConstruct() override;
    void BeginPlay() override;
    void OnDestroy() override;
    ~Enemy() override;
    void FixedUpdate(float deltaTime) override;
    void Update(float deltaTime) override;
    void Draw() override;
    void OnCollisionEnter(CollisionData data);

    inline static int enemyCount;
private:
    CircleCollider2D* m_collider = nullptr;
    sf::Sprite m_sprite;
    bool m_simulatingPhysics = true;
    sf::Texture m_Texture;
};
