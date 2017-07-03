#include "Wall.h"

Hitresult Wall::getHitResult(const sf::Vector2f& hitPosition, const Lightray& ray) const
{
    Hitresult hitresult;
    hitresult.hitPosition = hitPosition;
    hitresult.hitType = HitType::block;
    return hitresult;
}
