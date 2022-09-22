#include "Catapult.h"

#include <SFML/Window/Mouse.hpp>

#include "App.h"
#include "Ball.h"
#include "Scene.h"


void Catapult::OnConstruct()
{
    m_texture.loadFromFile("Resources/Sprites/Catapult.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
    m_sprite.setPosition(GetPosition());

    pivot = GetPosition() + sf::Vector2f{ 0, -((float)m_texture.getSize().y)/2.f };

    m_rope.setSize(sf::Vector2f{ 2, 100 });
    m_rope.setFillColor(sf::Color::Red);
    m_rope.setOrigin(1, 0);
    m_rope.setPosition(pivot);
    
    
}

void Catapult::BeginPlay()
{
    
}

void Catapult::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);
}

void Catapult::Update(float deltaTime)
{
    Actor::Update(deltaTime);
    
    if (App::GetWindow()->hasFocus())
    {
    
        if (!m_ball)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_ball = m_Scene->SpawnActor<Ball>(pivot);
                m_ball->SetSimulatingPhysics(false);
            }
        }

        if (m_ball)
        {
            if (!m_ball->IsSimulatingPhysics())
            {
            
                sf::Vector2f mousePos = m_Scene->GetMousePositionWorld();
                sf::Vector2f direction = mousePos - pivot;
            
            
                float length = sqrt(direction.x * direction.x + direction.y * direction.y);
                sf::Vector2f normalizedDirection = direction / length;
                float maxDistance = 200.0f;
                if (length > maxDistance)
                {
                    length = maxDistance;
                }
            
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    m_ball->SetPosition(pivot + normalizedDirection * length);
                    m_primed = true;
                    m_rope.setSize({15.f - (0.04f * length), length});
                    m_rope.setOrigin(m_rope.getSize().x/2.f, 0);
                    m_rope.setRotation(( atan2(direction.y, direction.x) * 180 / 3.14159265) - 90);
                }
                else if (m_primed)
                {
                    m_ball->SetSimulatingPhysics(true);
                    m_ball->ApplyForce(-normalizedDirection * length * 800.0f);
                    m_primed = false;
                    m_ball = nullptr;
                }
            
            }
        }
    }



    
    
}

void Catapult::Draw()
{
    Actor::Draw();
    Renderer::Submit(m_sprite, 10);
    if (m_primed)
    {
        Renderer::Submit(m_rope, 9);
    }
}

void Catapult::OnDestroy()
{
}

