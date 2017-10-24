#include "Mirror.h"
#include "vectorOperations.h"
#include <iostream>
#include "Lightray.h"


Mirror::~Mirror()
{
    //dtor
}

Hitresult Mirror::getHitResult(const sf::Vector2f& hitPosition, const Lightray& ray) const
{
    Hitresult hitresult;
    hitresult.hitPosition = hitPosition;
    hitresult.hitType = HitType::reflect;
    hitresult.causer = this;
    // split up ray into components parallel and perpendicular to mirror
    sf::Vector2f rayVector(ray.getBegin() - ray.getEnd());
    sf::Vector2f mirrorVector(op::normalize(getRightPosition()-getLeftPosition()));
    sf::Vector2f paralel = op::dot(mirrorVector, rayVector) * mirrorVector; // parallel to mirror
    sf::Vector2f perpendicular = rayVector - paralel;// perpendicular to mirror
    sf::Vector2f newRay = perpendicular - paralel;
    //std::cout << "paralel " << paralel << std::endl;
    //std::cout << "perpendicular " << perpendicular << std::endl;
    float angle = std::atan2(newRay.y, newRay.x);
    //std::cout << "angle of reflection " << angle << std::endl;
    hitresult.reflectDirection =  angle;
    return hitresult;
}
