#pragma once
#include "Actor.h"

class Camera : public Actor
{
public:
    void OnConstruct() override;
    void BeginPlay() override;
    void OnDestroy() override;
    void FixedUpdate(float deltaTime) override;
    void Update(float deltaTime) override;
    void Draw() override;
    
    void SetActiveCamera();
    void SetParent(Actor* parent);
    void DetachFromParent();

    void BlinkTransition(float duration, const sf::Color& color);
    void UpdateTransition(float deltaTime);
    void DrawTransition();

    void SetOffset(const sf::Vector2f& offset) {m_offset = offset;}
    Actor* GetParent() {return m_parent;}
private:
    sf::View m_view;
    float m_zoom = 1.0f;
    Actor* m_parent = nullptr;
    sf::Vector2f m_offset;
    sf::Color m_transitionColor;
    float m_transitionTimer;
    float m_transitionDuration;
    sf::RectangleShape shape;
};
