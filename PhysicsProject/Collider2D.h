#pragma once
#include <functional>
#include <SFML/System/Vector2.hpp>

#include "CollisionData.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_world_callbacks.h"

class Scene;
class Actor;
class Collider2D;


class Collider2D
{
public:
    friend class ContactListener;
    
    Collider2D();
    ~Collider2D();

    void SetPosition(const sf::Vector2f& position);
    sf::Vector2f GetPosition() const;

    float GetAngleRad() const;
    void SetAngleRad(float angle);
    float GetAngleDeg() const;
    void SetAngleDeg(float angle);

    void SetDensity(float density);
    float GetDensity() const;

    void SetFriction(float friction);
    float GetFriction() const;

    void SetRestitution(float restitution);
    float GetRestitution() const;

    void SetLinearVelocity(const sf::Vector2f& velocity);
    sf::Vector2f GetLinearVelocity() const;

    void ApplyForce(const sf::Vector2f& force, const sf::Vector2f& point, bool wake = true);
    void ApplyForceToCenter(const sf::Vector2f& force, bool wake = true);
    void ApplyLinearImpulse(const sf::Vector2f& impulse, const sf::Vector2f& point, bool wake = true);
    void ApplyLinearImpulseToCenter(const sf::Vector2f& impulse, bool wake = true);
    void ApplyTorque(float torque, bool wake = true);
    void ApplyAngularImpulse(float impulse, bool wake = true);
    

    void SetBodyType(b2BodyType type);
    b2BodyType GetBodyType() const;
    
    void OnCollisionEnterCallback(std::function<void(CollisionData)> data)
    {
        onCollisionEnter = data;
    }
    void OnCollisionExitCallback(std::function<void(CollisionData)> data)
    {
        onCollisionExit = data;
    }

    void SetOwner(Actor* owner) { this->m_owner = owner; }
    Actor* GetOwner() { return m_owner; }
    
protected:
    void OnCollisionEnter(CollisionData data) { if (onCollisionEnter) onCollisionEnter(data); }
    void OnCollisionExit(CollisionData data) { if (onCollisionExit) onCollisionExit(data); }

    std::function <void(CollisionData)> onCollisionEnter;
    std::function<void(CollisionData)> onCollisionExit;

    b2BodyDef m_bodyDef;
    b2FixtureDef m_fixtureDef;
    b2Body* m_body = nullptr;
    b2Shape* m_shape = nullptr;
    Actor* m_owner = nullptr;
    Scene* m_scene = nullptr;
    double SCALE;
};
