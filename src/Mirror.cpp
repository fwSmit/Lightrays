#include "Mirror.h"
#include "vectorOperations.h"



Mirror::~Mirror()
{
    //dtor
}

Hitresult Mirror::getHitResult(const sf::Vector2f& hitPosition, const Lightray& ray) const
{
    Hitresult hitresult;
    hitresult.hitPosition = hitPosition;
    hitresult.hitType = HitType::reflect;
    sf::Vector2f this_deltaPos = getFirstPosition() - getSecondPosition();
    float this_rotation = op::angle(this_deltaPos, sf::Vector2f(1,0)); //std::atan2(this_deltaPos.y, this_deltaPos.x);

    hitresult.reflectDirection =  this_rotation;
    return hitresult;
}
