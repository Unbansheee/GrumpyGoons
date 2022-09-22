#include "Collider2D.h"
#include "Scene.h"


Collider2D::Collider2D()
{
    m_fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
}

Collider2D::~Collider2D()
{
    m_body->DestroyFixture(m_body->GetFixtureList());
    if (m_scene)
        m_scene->DestroyBody(m_body);
    delete m_shape;
    m_shape = nullptr;
    m_body = nullptr;
    
}

void Collider2D::SetPosition(const sf::Vector2f& position)
{
    m_body->SetTransform(b2Vec2(position.x / SCALE, position.y / SCALE), m_body->GetAngle());
}

sf::Vector2f Collider2D::GetPosition() const
{
    return sf::Vector2f(m_body->GetPosition().x * SCALE, m_body->GetPosition().y * SCALE);
}

float Collider2D::GetAngleRad() const
{
    return m_body->GetAngle();
}

void Collider2D::SetAngleRad(float angle)
{
    m_body->SetTransform(m_body->GetPosition(), angle);
}

float Collider2D::GetAngleDeg() const
{
    return m_body->GetAngle() * 180 / b2_pi;
}

void Collider2D::SetAngleDeg(float angle)
{
    m_body->SetTransform(m_body->GetPosition(), angle * b2_pi / 180);

}

void Collider2D::SetDensity(float density)
{
    m_fixtureDef.density = density;
    m_body->DestroyFixture(m_body->GetFixtureList());
    m_body->CreateFixture(&m_fixtureDef);
}

float Collider2D::GetDensity() const
{
    return m_fixtureDef.density;
}

void Collider2D::SetFriction(float friction)
{
    m_fixtureDef.friction = friction;
    m_body->DestroyFixture(m_body->GetFixtureList());
    m_body->CreateFixture(&m_fixtureDef);
}

float Collider2D::GetFriction() const
{
    return m_fixtureDef.friction;
}

void Collider2D::SetRestitution(float restitution)
{
    m_fixtureDef.restitution = restitution;
    m_body->DestroyFixture(m_body->GetFixtureList());
    m_body->CreateFixture(&m_fixtureDef);
}

float Collider2D::GetRestitution() const
{
    return m_fixtureDef.restitution;
}

void Collider2D::SetLinearVelocity(const sf::Vector2f& velocity)
{
    m_body->SetLinearVelocity(b2Vec2(velocity.x / SCALE, velocity.y / SCALE));
}

sf::Vector2f Collider2D::GetLinearVelocity() const
{
    return sf::Vector2f(m_body->GetLinearVelocity().x * SCALE, m_body->GetLinearVelocity().y * SCALE);
    
}

void Collider2D::ApplyForce(const sf::Vector2f& force, const sf::Vector2f& point, bool wake)
{
    m_body->ApplyForce(b2Vec2(force.x / SCALE, force.y / SCALE), b2Vec2(point.x / SCALE, point.y / SCALE), wake);
    
}

void Collider2D::ApplyForceToCenter(const sf::Vector2f& force, bool wake)
{
    m_body->ApplyForceToCenter(b2Vec2(force.x / SCALE, force.y / SCALE), wake);
    
}

void Collider2D::ApplyLinearImpulse(const sf::Vector2f& impulse, const sf::Vector2f& point, bool wake)
{
    m_body->ApplyLinearImpulse(b2Vec2(impulse.x / SCALE, impulse.y / SCALE), b2Vec2(point.x / SCALE, point.y / SCALE), wake);
    
}

void Collider2D::ApplyLinearImpulseToCenter(const sf::Vector2f& impulse, bool wake)
{
    m_body->ApplyLinearImpulseToCenter(b2Vec2(impulse.x / SCALE, impulse.y / SCALE), wake);
    
}

void Collider2D::ApplyTorque(float torque, bool wake)
{
    m_body->ApplyTorque(torque, wake);
    
}

void Collider2D::ApplyAngularImpulse(float impulse, bool wake)
{
    m_body->ApplyAngularImpulse(impulse, wake);
    
}

void Collider2D::SetBodyType(b2BodyType type)
{
    m_bodyDef.type = type;
    m_body->SetType(type);
}

b2BodyType Collider2D::GetBodyType() const
{
    return m_bodyDef.type;
}
