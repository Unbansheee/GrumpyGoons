#include "Camera.h"

#include "Catapult.h"
#include "Input.h"
#include "Ball.h"

void Camera::OnConstruct()
{
    SetUpdatePriority(10);
}

void Camera::BeginPlay()
{
}

void Camera::OnDestroy()
{
}

void Camera::FixedUpdate(float deltaTime)
{
    Actor::FixedUpdate(deltaTime);
}

void Camera::Update(float deltaTime)
{
    Actor::Update(deltaTime);

    UpdateTransition(deltaTime);
    
    if (m_parent) SetPosition(m_parent->GetPosition());
    
    m_zoom += Input::GetMouseScrollDelta() * -0.1f;

    m_view.setCenter(GetPosition() + m_offset);
    m_view.setSize(Renderer::GetWindowSize().x * m_zoom, Renderer::GetWindowSize().y * m_zoom);
    
    
    
}

void Camera::Draw()
{
    Actor::Draw();
    DrawTransition();
}

void Camera::SetActiveCamera()
{
    Renderer::SetViewport(m_view);
}

void Camera::SetParent(Actor* parent)
{
    m_parent = parent;
    BlinkTransition(0.2f, sf::Color::Black);
}

void Camera::DetachFromParent()
{
    m_parent = nullptr;
}

void Camera::BlinkTransition(float duration, const sf::Color& color)
{
    m_transitionColor = color;
    m_transitionTimer = duration;
    m_transitionDuration = duration;
    
}

void Camera::UpdateTransition(float deltaTime)
{
    if (m_transitionTimer > 0)
    {
        m_transitionTimer -= deltaTime;
        float progress = m_transitionTimer / m_transitionDuration;
        m_transitionColor.a = 255 * progress;
        //m_transitionColor.a = 255 * progress;
    }
    else
    {
        m_transitionTimer = 0;
        m_transitionColor = sf::Color::Transparent;
    }
}

void Camera::DrawTransition()
{
    if (m_transitionTimer > 0)
    {
        shape.setSize(sf::Vector2f(Renderer::GetWindowSize().x * m_zoom, Renderer::GetWindowSize().y * m_zoom));
        shape.setFillColor(m_transitionColor);
        shape.setOrigin(shape.getSize() / 2.0f);
        shape.setPosition(GetPosition() + m_offset);
        Renderer::Submit(shape, 1000);
    }


    
}
