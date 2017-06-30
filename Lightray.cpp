#include "Lightray.h"
#include <iostream>
#include <assert.h>
#define M_PI		3.14159265358979323846
#include "CollisionHandler.h"
#include "vectorOperations.h"

float radianToDegree(float radians)
{
    return radians/M_PI * 180;
}

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj)
{
    os << obj.x << "    " << obj.y << std::endl;

    return os;
}


/*!
* @param  direction: (in degrees) the direction of the ray
*/
Lightray::Lightray(const sf::Vector2f& _position, const double _direction, const int maxLenght) : position(_position), r_direction(_direction), maxLenght(maxLenght)
{

}

Lightray::~Lightray()
{
    //dtor
}

void Lightray::setColor(sf::Color color)
{
    currColor = color;
}

sf::VertexArray Lightray::getDrawable() const
{
    sf::VertexArray vertices(sf::Lines, 2);
    vertices[0].position = getBegin();
    vertices[0].color = currColor;
    vertices[1] = getEnd();
    vertices[1].color = currColor;
    return vertices;
}



void Lightray::setDirection(double _direction)
{
    r_direction = _direction;
}

void Lightray::setPosition(sf::Vector2f _position)
{
    position = _position;
}


sf::Vector2f Lightray::getEnd() const
{
    sf::Vector2f result;
    result.x = getBegin().x + maxLenght * cos (r_direction);
    result.y = getBegin().y + maxLenght * sin (r_direction);
    return result;
}
