#include "FallingBlock.h"

#include "Ball.h"
#include "PopAnimation.h"
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
    collider->OnCollisionEnterCallback([&](CollisionData data)
    {
        if (!data.otherActor->HasTag("Enemy") && VectorLength(data.otherVelocity) > 13 && HasTag("Destructible"))
        {
            Destroy();
        }
       
    });

    AddTag("Block");
}

void FallingBlock::SetSize(sf::Vector2f size)
{
    shape.setSize(size);
    collider->SetSize(size);
}

void FallingBlock::SetWeight(float weight)
{
    collider->SetDensity(weight);
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

    if (HasTag("Destructible"))
    {
        shape.setFillColor(sf::Color(164,116,73));
    }
    else
    {
        shape.setFillColor(sf::Color(128,128,128));
    }
    
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

    m_Scene->SpawnActor<PopAnimation>(GetPosition())->Play(shape.getFillColor(), 0.5f);
    delete collider;
}


