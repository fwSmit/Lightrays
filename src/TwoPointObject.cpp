#include "TwoPointObject.h"
#include <SFML/Graphics.hpp>

#define M_PI		3.14159265358979323846

TwoPointObject::TwoPointObject(sf::Vector2f _first, sf::Vector2f _second)
{
    first.position = _first;
    first.color = getDefaultColor();
    second.position = _second;
    second.color = getDefaultColor();

}

TwoPointObject::~TwoPointObject()
{
    //dtor
}

sf::Vector2f TwoPointObject::getLeftPosition() const
{
    if (first.position.x < second.position.x)
    {
        return first.position;
    }
    else
    {
        return second.position;
    }
}

sf::Vector2f TwoPointObject::getRightPosition() const
{
    if (first.position.x < second.position.x)
    {
        return second.position;
    }
    else
    {
        return first.position;
    }
}

sf::Vector2f TwoPointObject::getTop() const
{
    if (first.position.y < second.position.y)
    {
        return second.position;
    }
    else
    {
        return first.position;
    }
}

sf::Vector2f TwoPointObject::getBottom() const
{
    if (first.position.y < second.position.y)
    {
        return first.position;
    }
    else
    {
        return second.position;
    }
}

void TwoPointObject::setColor (sf::Color color)
{
    first.color = color;
    second.color = color;
}

sf::VertexArray TwoPointObject::getDrawable()
{
    sf::VertexArray vertices(sf::Lines, 2);
    vertices[0] = getFirstVertex();
    vertices[1] = getSecondVertex();
    return vertices;
}

void TwoPointObject::collide(const class Lightray& ray, const class Hitresult& hitresult)
{
    sf::Vector2f deltaPos_first = end - begin;
    sf::Vector2f deltaPos_second = second.getRightPosition() - second.getLeftPosition();

    bool isRayVertical = std::abs(ray.getDirection()) == M_PI / 4;
    bool isThisVertical = getFirstPosition().x == getSecondPosition().x;
    // paralel lines
    if(isRayVertical && isThisVertical)
    {
        // if they are on top of each other you cant really define an intersection point
        return false;
    }

    if(isRayVertical)
    {
        // the Lightray is vertical
        float x_vertical = ray.getBegin().x; // x of the vertical line
        sf::Vector2f point_normal; // point of the normal line
        sf::Vector2f deltaPos = getRightPosition() - getLeftPosition();
        float steepness = deltaPos.y/deltaPos.x; // steepness of the normal line
        point_normal = getFirstPosition(); // a point on the non-vertical line
        sf::Vector2f intersection;
        intersection.x = x_vertical;
        intersection.y = steepness * (xIntersect - point_normal.x) + point_normal.y;
    }

    if (isThisVertical)
    {

    }

}

bool TwoPointObject::isInBounds(const sf::Vector2f& test , const Lightray& ray) const
{
    /**warning: not tested yet*/
    if(test.x < ray.getBegin().x || test.x > ray.getBegin().x || test.x < getLeftPosition().x || test.x > getRightPosition().x){
        // out of bounds in the x-axis
        return false;
    }

    if(std::abs(ray.getDirection()) < M_PI){
        /// ray pointing down, delta y is positive, I think

    }
    return !(test.x < min(begin.x, end.x) || test.x > max(begin.x, end.x) /*don't know if the last part is needed*/ || test.y < min (begin.y, end.y) || test.y > max(begin.y, end.y));

}

