#include "Lightray.h"
#include <iostream>
#include <assert.h>
#define M_PI		3.14159265358979323846
#include "CollisionHandler.h"
#include "vectorOperations.h"

using namespace std;

float radianToDegree(float radians)
{
    return radians/M_PI * 180;
}

float boundToTwoPi(float degrees)
{
    if(degrees > 0) {
        while (degrees >= 2*M_PI) {
            degrees -= 2*M_PI;
        }
    } else {
        while (degrees < 0) {
            degrees += 2*M_PI;
        }
    }
    return degrees;
}

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj)
{
    os << obj.x << "    " << obj.y << std::endl;

    return os;
}


/*!
* @param  direction: (in degrees) the direction of the ray
*/
Lightray::Lightray(const sf::Vector2f& _position, const float _direction, const int maxLenght) : position(_position), maxLenght(maxLenght)
{
    initialized = true;
    setDirection(_direction);
}

void Lightray::checkInitialized() const
{
    if(!initialized) {
        std::logic_error ex("Object of class Lightray was not initialized");
        throw ex;
    }
}


Lightray::~Lightray()
{
    //dtor
}

void Lightray::setColor(sf::Color color)
{
    checkInitialized();
    currColor = color;
}

void Lightray::setEnd(sf::Vector2f _end)
{
    endOfRay = _end;
    hasEnd = true;
}

bool Lightray::isInBounds(sf::Vector2f test) const
{
    // on the x-axis I distinguish 3 possibilities: Delta x = 0, delta x > 0 and delta x < 0
    // ray extends infinitely in the direction it faces
    //bool b_isVertical = isVertical();
    //if(b_isVertical) cout << "ray is vertical" << endl;
    // if the ray is vertical the intersection can't be out of bounds on the x-axis (provided test is on the line of the ray)
    //if(!b_isVertical)
    //{

    //cout << "ray points left: " << boolalpha << pointsLeft << endl;
    if(doesHaveEnd()) {
        bool isVertical = std::abs(getBegin().x - getEnd().x) < std::numeric_limits<float>::epsilon();
        if(!isVertical) {
            //cout << "is not vertical" << endl;
            if(test.x < min(getBegin().x, getEnd().x) || test.x > max(getBegin().x, getEnd().x)) {
                // out of bounds in the x-axis
                //cout << "out of bounds in the x-axis for TwoPointObject" << endl;
                return false;
            }
        } else {
            //cout << "is vertical" << endl;
            if(test.y < min(getBegin().y, getEnd().y) || test.y > max(getBegin().y, getEnd().y)) {
                // out of bounds in the y-axis
                //cout << "out of bounds in the y-axis for TwoPointObject" << endl;
                return false;
            }
        }
    }

    // the ray is infinitely long
    if(isPointingLeft()) {
        if(test.x > getBegin().x) {
            return false;
        }
    } else {
        // points right
        if(test.x < getBegin().x) {
            return false;
        }
    }
    //}

    // when horizontal test can't be out of bounds on the y-axis
    // same as for the x-axis
    //if(!isHorizontal())
    //{
    //   cout << "out of bounds on the y-axis" << endl;
    //   cout << "ray not horizontal" << endl;
    if(isPointingUp()) {
        //cout << "ray pointing up, delta y negative" << endl;
        if (test.y > getBegin().y) return false;
    } else {
        //cout << "ray pointing down, delta y positive" << endl;
        if (test.y < getBegin().y) return false;
    }
    //}

    //cout << "not out of bounds for the ray" << endl;
    return true;
}


sf::VertexArray Lightray::getDrawable() const
{
    checkInitialized();
    sf::VertexArray vertices(sf::Lines, 2);
    vertices[0].position = getBegin();
    vertices[0].color = currColor;
    vertices[1] = getEnd();
    vertices[1].color = currColor;
    return vertices;
}

void Lightray::setDirection(float _direction)
{
    checkInitialized();
    r_direction = boundToTwoPi(_direction);
    //cout << "direction =" << r_direction << endl;
}

void Lightray::setPosition(sf::Vector2f _position)
{
    checkInitialized();
    position = _position;
}


sf::Vector2f Lightray::getEnd() const
{
    checkInitialized();
    if(hasEnd) {
        //cout << "has end" << endl;
        return endOfRay;
    } else {
        //cout << "infinitely" << endl;
        sf::Vector2f result;
        result.x = getBegin().x + maxLenght * cos (r_direction);
        result.y = getBegin().y + maxLenght * sin (r_direction);
        return result;
    }
}
bool Lightray::isPointingLeft() const
{
    return getDirection() > M_PI_2 && getDirection() < 2 * M_PI - M_PI_2;
}

bool Lightray::isPointingUp() const
{
    return getDirection() < 2 * M_PI && getDirection() > M_PI;
}



