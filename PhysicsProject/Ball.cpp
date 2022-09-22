#include "Ball.h"
#include <iostream>
#include "Scene.h"

#include "Log.h"
#include <future>

void Ball::OnConstruct()
{


    m_collider = new CircleCollider2D(GetPosition(), 25, m_Scene, SCALE);
    m_collider->SetOwner(this);
    
    m_collider->OnCollisionEnterCallback([](CollisionData data)
    {

    });
    
    m_Texture.loadFromFile("Resources/Sprites/Ball.png");
    m_sprite.setTexture(m_Texture);

    AddTag("Ball");
    
}

void Ball::BeginPlay()
{
    m_startDestroyTimer.Begin([&](){isDying = true;}, 4);
}

void Ball::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);

}

void Ball::Update(float deltaTime)
{
    Actor::Update(deltaTime);
    

    m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.f, m_sprite.getTextureRect().height / 2.f);

    if (!IsSimulatingPhysics())
    {
        m_collider->SetPosition(GetPosition());
        m_collider->SetAngleDeg(GetRotation());
        
    }

    
    
    SetPosition(m_collider->GetPosition());
    SetRotation(m_collider->GetAngleDeg());

    
    m_sprite.setPosition(GetPosition());
    m_sprite.setRotation(GetRotation());

    if (isDying)
    {
        float scaleX = b2Clamp(m_sprite.getScale().x - 10.f * deltaTime, 0.f, 2.f);
        m_sprite.setScale(scaleX, scaleX);
        if (scaleX <= 0.1f) Destroy();
    }

}

void Ball::Draw()
{
    Actor::Draw();
    Renderer::Submit(m_sprite, 5);
}

void Ball::OnDestroy()
{
    delete m_collider;
}

void Ball::SetSimulatingPhysics(bool simulatingPhysics)
{
    m_simulatingPhysics = simulatingPhysics;
    if (m_simulatingPhysics)
    {
        m_collider->SetBodyType(b2_dynamicBody);
    }
    else
    {
        m_collider->SetBodyType(b2_staticBody);
    }
}

bool Ball::IsSimulatingPhysics() const
{
    return m_simulatingPhysics;
}

void Ball::ApplyForce(const sf::Vector2f& force)
{
    m_collider->ApplyForceToCenter(force);
}


