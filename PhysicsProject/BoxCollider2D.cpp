#include "BoxCollider2D.h"
#include "Scene.h"

BoxCollider2D::BoxCollider2D(const sf::Vector2f& position, const sf::Vector2f& size, Scene* scene, double SCALE)
{
    this->SCALE = SCALE;
    m_size = size;
    m_scene = scene;

    m_shape = new b2PolygonShape();
    
    m_bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
    m_bodyDef.type = b2_dynamicBody;
    m_body = scene->CreateBody(&m_bodyDef);

    static_cast<b2PolygonShape*>(m_shape)->SetAsBox((size.x/2.f) / SCALE, (size.y/2.f) / SCALE);
    
    m_fixtureDef.shape = m_shape;
    m_fixtureDef.density = 1;
    m_fixtureDef.restitution = 0.5;
    
    m_body->CreateFixture(&m_fixtureDef);
    
}

void BoxCollider2D::SetSize(const sf::Vector2f& size)
{
    m_size = size;
    static_cast<b2PolygonShape*>(m_shape)->SetAsBox((m_size.x/2.f) / SCALE, (m_size.y/2.f) / SCALE);
    m_fixtureDef.shape = m_shape;
    m_body->DestroyFixture(m_body->GetFixtureList());
    m_body->CreateFixture(&m_fixtureDef);
    
}

sf::Vector2f BoxCollider2D::GetSize() const
{
    return m_size;
}

