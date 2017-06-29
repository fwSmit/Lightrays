#include "TwoPointObject.h"
#include <SFML/Graphics.hpp>


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
//dtor

