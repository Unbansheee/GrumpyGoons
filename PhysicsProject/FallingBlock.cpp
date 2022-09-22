#include "FallingBlock.h"

#include "Ball.h"
#include "Scene.h"

void FallingBlock::OnConstruct()
{
    shape.setSize(sf::Vector2f(30, 100));
    shape.setFillColor(sf::Color(164,116,73));
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(-5.f);
    collider = new BoxCollider2D(GetPosition(), shape.getSize(), m_Scene, SCALE);
    collider->SetAngleDeg(GetRotation());
    collider->SetOwner(this);
    collider->OnCollisionEnterCallback([](CollisionData data)
    {

       
    });

    AddTag("Block");
}

void FallingBlock::BeginPlay()
{
}

void FallingBlock::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);
    
}

void FallingBlock::Update(float deltaTime)
{
    Actor::Update(deltaTime);
    shape.setOrigin(shape.getSize().x/2, shape.getSize().y/2);
    
    SetPosition(collider->GetPosition());
    SetRotation(collider->GetAngleDeg());

    shape.setRotation(GetRotation());
    shape.setPosition(GetPosition());
    
}

void FallingBlock::Draw()
{
    Actor::Draw();
    Renderer::Submit(shape, m_DrawPriority);
}

void FallingBlock::OnDestroy()
{
    delete collider;
}


