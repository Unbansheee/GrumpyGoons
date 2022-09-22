#pragma once
#include <SFML/System/Vector2.hpp>

#include "box2d/b2_body.h"


class Actor;

struct CollisionData
{
    CollisionData() {}
    
    Actor* actor;
    Actor* otherActor;
    sf::Vector2f location;
    sf::Vector2f normal;
    sf::Vector2f velocity;
    sf::Vector2f otherVelocity;
    b2BodyType otherType;
    
};
