#ifndef HITRESULT_H
#define HITRESULT_H

#include <SFML/System/Vector2.hpp>

enum HitType{
 no_hit, block, reflect
};

struct Hitresult
{
    HitType hitType = no_hit;
    sf::Vector2f hitPosition;
    float reflectDirection;
    const class PhysicsObject* causer = nullptr;
};

#endif // HITRESULT_H
