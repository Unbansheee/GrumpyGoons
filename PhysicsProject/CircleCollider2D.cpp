#include "CircleCollider2D.h"
#include "Scene.h"



CircleCollider2D::CircleCollider2D(sf::Vector2f position, float radius, Scene* scene, double SCALE)
{
    
    this->SCALE = SCALE;
    m_scene = scene;
    m_shape = new b2CircleShape();
    m_bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
    m_bodyDef.type = b2_dynamicBody;
    m_body = scene->CreateBody(&m_bodyDef);

    m_shape->m_radius = radius / SCALE;
    m_fixtureDef.shape = m_shape;
    m_fixtureDef.density = 1;
    m_fixtureDef.restitution = 0.5;
    m_body->CreateFixture(&m_fixtureDef);
}

void CircleCollider2D::SetRadius(float radius)
{
    m_shape->m_radius = radius / SCALE;
}

float CircleCollider2D::GetRadius() const
{
    return m_shape->m_radius * SCALE;
}
