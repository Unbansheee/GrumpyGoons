#include "Ball.h"
#include <iostream>
#include "Scene.h"

#include "Log.h"
#include <future>
#include "Catapult.h"

void Ball::OnConstruct()
{

    SetUpdatePriority(0);
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
}

void Ball::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);

}

void Ball::Update(float deltaTime)
{
    Actor::Update(deltaTime);

    if (cam)
    {
        if (cam->GetParent() == this)
        {
            cam->SetOffset({0, 0});
        }
    }

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
    if (cam)
    {
        if (cam->GetParent() == this)
        {
            cam->SetParent(cat);
        }
        
    }
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

void Ball::Fire(const sf::Vector2f& force, Catapult* catapult, Camera* camera)
{
    fired = true;
    m_startDestroyTimer.reset(new TimedCallback);
    m_startDestroyTimer->Begin([&](){isDying = true;}, 4);

    SetSimulatingPhysics(true);
    ApplyForce(force);
    
    camera->SetParent(this);
    cam = camera;
    cat = catapult;
}


