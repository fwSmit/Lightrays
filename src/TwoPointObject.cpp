#include "TwoPointObject.h"
#include <SFML/Graphics.hpp>
#include "Lightray.h"
#include "Hitresult.h"
#include <iostream>

using namespace std;

#define M_PI		3.14159265358979323846

TwoPointObject::TwoPointObject(sf::Vector2f _first, sf::Vector2f _second,  sf::RenderWindow& debugWindow) : window(debugWindow)
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

bool TwoPointObject::collide(const Lightray& ray, Hitresult& hitresult)
{
    bool isRayVertical = std::abs(ray.getDirection()) == M_PI / 4;
    bool isThisVertical = getFirstPosition().x == getSecondPosition().x;

    cout << boolalpha << "is Ray vertical " << isRayVertical << endl << "is this vertical " << isThisVertical << endl;
    // paralel lines
    if(isRayVertical && isThisVertical)
    {
        // if they are on top of each other you cant really define an intersection point
        cout << "both are vertical" << endl;
        return false;
    }

    if(isRayVertical || isThisVertical)
    {
        cout << "one of them is vertical" << endl;
        float x_vertical; // x of the vertical line
        sf::Vector2f point_normal; // point of the non-vertical line
        float steepness; // steepness of the non-vertical line

        if(isRayVertical)
        {
            // the Lightray is vertical
            x_vertical = ray.getBegin().x;
            point_normal = getFirstPosition();

            sf::Vector2f deltaPos = getRightPosition() - getLeftPosition();
            steepness = deltaPos.y/deltaPos.x;
        }
        else
        {
            // the TwoPointObject is vertical
            x_vertical = getFirstPosition().x;
            point_normal = ray.getBegin();
            steepness = std::tan(ray.getDirection());
        }

        sf::Vector2f intersection;
        intersection.x = x_vertical;
        intersection.y = steepness * (intersection.x - point_normal.x) + point_normal.y;
        cout << "intersection " << intersection << endl;
        return checkHit(intersection, ray, hitresult);
    }

    // neither of them is vertical
    float steepness_ray = std::tan(ray.getDirection());

    sf::Vector2f deltaPos = getRightPosition() - getLeftPosition();
    float steepness_this = deltaPos.y/deltaPos.x;


    sf::Vector2f positionRay = ray.getBegin();
    sf::Vector2f positionThis = getFirstPosition();

    /*if(debugPrint) {
        printf("steepness wall: %f \n ray: %f\n", steepness_first, steepness_second);
    }*/

    float steep_difference = (steepness_ray - steepness_this);

    if(steep_difference == 0) return false;


    sf::Vector2f intersection;
    intersection.x = (steepness_ray*positionRay.x - positionRay.y - steepness_this * positionThis.x + positionThis.y)/steep_difference;


    //printf("xIntersect: %f, first x %f, second x %f \n", xIntersect, second.getFirst().x, second.getSecond().x);
    intersection.y = steepness_ray * (intersection.x - positionRay.x) + positionRay.y;

    return checkHit(intersection, ray, hitresult);

    /*if(debugPrint) {
        printf("x intersect is %f \n", xIntersect);
        printf("lowest x = %f \n", min(begin.x, end.x));
        printf("highest x = %f \n", max(begin.x, end.x));
    }*/


}

bool TwoPointObject::checkHit(const sf::Vector2f& intersection, const Lightray& ray, Hitresult& hitResult)
{
    if(isInBounds(intersection, ray))
    {
        hitResult = getHitResult(intersection);
        drawDebugCircle(intersection);
        return true;
    }
    else
    {
        cout << "the hit is not in bounds" << endl;
        return false;
    }
}

void TwoPointObject::drawDebugCircle(sf::Vector2f position)
{
    sf::CircleShape debugCircle(10);
    debugCircle.setOrigin(debugCircle.getRadius(), debugCircle.getRadius());
    debugCircle.setFillColor(sf::Color::Green);
    debugCircle.setPosition(position);
    window.draw(debugCircle);
}


bool TwoPointObject::isInBounds(const sf::Vector2f& test, const Lightray& ray) const
{
    bool pointsLeft = ray.getDirection() > M_PI_2 && ray.getDirection() < 2*M_PI - M_PI_2;
    cout << "points left " << boolalpha << pointsLeft << endl;
    bool outOfBoundsRayX = pointsLeft ? /* points left */test.x > ray.getBegin().x
    : test.x < ray.getBegin().x;/* points right */
    if(test.x < getLeftPosition().x || test.x > getRightPosition().x || outOfBoundsRayX)
    {
        // out of bounds in the x-axis
        cout << "out of bounds in the x-axis" << endl;
        return false;
    }

    cout << "out of bounds in the y-axis" << endl;

    // check bound in the y-axis


    if(ray.getDirection() == 0 || ray.getDirection() == M_PI){
        cout << "ray delta y = 0" << endl;
        return test.y == ray.getBegin().y;
    }

    if(std::sin(ray.getDirection()) < 0)
    {
        /// ray pointing up, delta y is negative, so only check if test is below it
        cout << "ray pointing up, delta y negative" << endl;
        if (test.y > ray.getBegin().y) return false;
    }else{
        cout << "ray pointing down, delta y positive" << endl;
        if (test.y < ray.getBegin().y) return false;
    }
    return (test.y < getTop().y && test.y > getBottom().y);
}

