#include "ContactListener.h"

#include <iostream>

#include "Ball.h"
#include "box2d/b2_contact.h"
#include "CollisionData.h"

void ContactListener::BeginContact(b2Contact* contact)
{
    b2ContactListener::BeginContact(contact);
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2FixtureUserData userDataA = (b2FixtureUserData)fixtureA->GetUserData();
    b2FixtureUserData userDataB = (b2FixtureUserData)fixtureB->GetUserData();

    Collider2D* colliderA = (Collider2D*)userDataA.pointer;
    Collider2D* colliderB = (Collider2D*)userDataB.pointer;

    
    //get location of collision
    b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);
    b2Vec2 point = worldManifold.points[0];

    //get velocity of collision
    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();
    b2Vec2 velocityA = bodyA->GetLinearVelocityFromWorldPoint(point);
    b2Vec2 velocityB = bodyB->GetLinearVelocityFromWorldPoint(point);
    
    sf::Vector2f normal = sf::Vector2f(worldManifold.normal.x, worldManifold.normal.y);
    
    if (colliderA)
    {
        CollisionData data;
        data.location = {point.x, point.y};
        data.velocity = {velocityA.x, velocityA.y};
        data.otherVelocity = {velocityB.x, velocityB.y};
        data.actor = colliderA->GetOwner();
        data.otherActor = colliderB->GetOwner();
        data.normal = normal;
        data.otherType = bodyB->GetType();
        colliderA->OnCollisionEnter(data);
    }
    if (colliderB)
    {
        CollisionData data;
        data.location = {point.x, point.y};
        data.velocity = {velocityB.x, velocityB.y};
        data.otherVelocity = {velocityA.x, velocityA.y};
        data.actor = colliderB->GetOwner();
        data.otherActor = colliderA->GetOwner();
        data.normal = normal;
        data.otherType = bodyA->GetType();
        colliderB->OnCollisionEnter(data);

    }

}

void ContactListener::EndContact(b2Contact* contact)
{
    b2ContactListener::EndContact(contact);
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2FixtureUserData userDataA = (b2FixtureUserData)fixtureA->GetUserData();
    b2FixtureUserData userDataB = (b2FixtureUserData)fixtureB->GetUserData();

    Collider2D* colliderA = (Collider2D*)userDataA.pointer;
    Collider2D* colliderB = (Collider2D*)userDataB.pointer;

    
    //get location of collision
    b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);
    b2Vec2 point = worldManifold.points[0];

    //get velocity of collision
    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();
    b2Vec2 velocityA = bodyA->GetLinearVelocityFromWorldPoint(point);
    b2Vec2 velocityB = bodyB->GetLinearVelocityFromWorldPoint(point);
    
    sf::Vector2f normal = sf::Vector2f(worldManifold.normal.x, worldManifold.normal.y);
    
    if (colliderA)
    {
        CollisionData data;
        data.location = {point.x, point.y};
        data.velocity = {velocityA.x, velocityA.y};
        data.otherVelocity = {velocityB.x, velocityB.y};
        data.actor = colliderA->GetOwner();
        data.otherActor = colliderB->GetOwner();
        data.normal = normal;
        data.otherType = bodyB->GetType();
        colliderA->OnCollisionExit(data);
    }
    if (colliderB)
    {
        CollisionData data;
        data.location = {point.x, point.y};
        data.velocity = {velocityB.x, velocityB.y};
        data.otherVelocity = {velocityA.x, velocityA.y};
        data.actor = colliderB->GetOwner();
        data.otherActor = colliderA->GetOwner();
        data.normal = normal;
        data.otherType = bodyA->GetType();
        colliderB->OnCollisionExit(data);

    }
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    b2ContactListener::PreSolve(contact, oldManifold);
}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
    b2ContactListener::PostSolve(contact, impulse);
}
