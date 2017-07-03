#include "Wall.h"

Hitresult Wall::getHitResult(sf::Vector2f hitPosition)
{
    Hitresult hitresult;
    hitresult.hitPosition = hitPosition;
    hitresult.hitType = HitType::block;
    return hitresult;
}
