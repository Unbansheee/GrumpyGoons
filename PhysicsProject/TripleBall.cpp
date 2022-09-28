#include "TripleBall.h"

#include "Input.h"
#include "Scene.h"

void TripleBall::OnConstruct()
{
    Ball::OnConstruct();
    m_Texture.loadFromFile("Resources/Sprites/Goon6.png");
    dropTimer = 0.3f;
    m_deathTicker = 3.f;
}

void TripleBall::Update(float deltaTime)
{
    Ball::Update(deltaTime);
    
    if (dropTimer.Update(deltaTime)) canDrop = true;
    
    if (fired)
    {
        
        if (Input::WasKeyPressed(sf::Keyboard::Space) && canDrop && m_isParent)
        {
            SpawnChild();
            canDrop = false;
        }
    }
}

void TripleBall::SpawnChild()
{
    auto child = m_Scene->SpawnActor<TripleBall>(GetPosition() + sf::Vector2f{0.f, m_collider->GetRadius() * 2.f});
    child->m_isParent = false;
    child->fired = true;
    child->m_collider->SetDensity(3);
    child->m_collider->ApplyLinearImpulseToCenter({0, 2000});
}
