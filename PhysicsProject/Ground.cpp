#include "Ground.h"
#include "Scene.h"

void Ground::OnConstruct()
{
    shape.setSize(sf::Vector2f(2000, 100));
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(-6.f);
    
    collider = new BoxCollider2D(GetPosition(), shape.getSize(), m_Scene, SCALE);
    collider->SetBodyType(b2_staticBody);
    collider->SetAngleDeg(GetRotation());
    collider->SetOwner(this);
}


void Ground::BeginPlay()
{
}

void Ground::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);
}

void Ground::Update(float deltaTime)
{
    Actor::Update(deltaTime);
    shape.setOrigin(shape.getSize().x/2, shape.getSize().y/2);
    
    SetPosition(collider->GetPosition());
    SetRotation(collider->GetAngleDeg());

    shape.setRotation(GetRotation());
    shape.setPosition(GetPosition());
}

void Ground::Draw()
{
    Actor::Draw();
    Renderer::Submit(shape, m_DrawPriority);
}

void Ground::OnDestroy()
{
}
