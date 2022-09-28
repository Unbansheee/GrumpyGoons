#include "TripleBall.h"

#include "Scene.h"

void TripleBall::OnConstruct()
{
    Ball::OnConstruct();
    m_Texture.loadFromFile("Resources/Sprites/Goon6.png");
    dropTimer = 0.4f;
    m_deathTicker = 2.f;
}

void TripleBall::Update(float deltaTime)
{
    Ball::Update(deltaTime);

    if (fired)
    {
        
        if (dropTimer.Update(deltaTime) && m_isParent)
        {
            SpawnChild();
        }
    }
}

void TripleBall::SpawnChild()
{
    auto child = m_Scene->SpawnActor<TripleBall>(GetPosition() + sf::Vector2f{0.f, m_collider->GetRadius()});
    child->m_isParent = false;
    child->fired = true;
}
