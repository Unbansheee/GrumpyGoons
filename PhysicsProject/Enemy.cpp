#include "Enemy.h"

#include "Log.h"
#include "PopAnimation.h"
#include "Scene.h"

void Enemy::OnConstruct()
{
    m_collider = new CircleCollider2D(GetPosition(), 25, m_Scene, SCALE);
    m_collider->SetOwner(this);
    
    m_collider->OnCollisionEnterCallback([&](CollisionData data){
    this->OnCollisionEnter(data);
    });
    
    m_Texture.loadFromFile("Resources/Sprites/Goon2.png");
    m_sprite.setTexture(m_Texture);
    m_sprite.setOrigin(m_Texture.getSize().x/2.f, m_Texture.getSize().y/2.f);

    AddTag("Enemy");
    
}

void Enemy::OnCollisionEnter(CollisionData data)
{
    Log::Print(data.otherActor->GetTagsString(), LogType::INFO);
    if (abs(data.otherVelocity.x) > 10 || abs(data.otherVelocity.y) > 5)
    {
        Destroy();
    }
}

void Enemy::BeginPlay()
{
}

void Enemy::OnDestroy()
{
    delete m_collider;
    auto pop = m_Scene->SpawnActor<PopAnimation>(GetPosition());
    pop->Play(sf::Color::White, 0.5f);
}

Enemy::~Enemy()
{
}

void Enemy::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);
}

void Enemy::Update(float deltaTime)
{
    Actor::Update(deltaTime);
    SetPosition(m_collider->GetPosition());
    SetRotation(m_collider->GetAngleDeg());

    
    m_sprite.setPosition(GetPosition());
    m_sprite.setRotation(GetRotation());
}

void Enemy::Draw()
{
    Actor::Draw();
    Renderer::Submit(m_sprite);
}
