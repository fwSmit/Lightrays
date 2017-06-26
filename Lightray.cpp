#include "Lightray.h"
#include <iostream>
#include <assert.h>
#define M_PI		3.14159265358979323846
#include "CollisionHandler.h"
#include <cmath>

float radianToDegree(float radians){
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
Lightray::Lightray(sf::Vector2f starting_position, sf::Vector2f _direction, const int maxLenght) : direction(_direction), vertices(sf::Lines, 2), defaultLenght(maxLenght)
{
    vertices[0] = starting_position;
}

Lightray::~Lightray()
{
    //dtor
}





void Lightray::calculateVertices(CollisionHandler& col){
    /**< WARNING: This could get out of bounds */
    assert(vertices.getVertexCount() > 0);

    sf::Vector2f deltaPos = direction - vertices[0].position;

    float lenght = sqrt(pow(deltaPos.x, 2) + pow(deltaPos.y, 2));

    deltaPos *= defaultLenght / lenght;

    vertices[1].position = vertices[0].position + deltaPos;

    //sf::Vertex newPosition = vertices[0];
    //newPosition.position.x += defaultLenght * cos (angle);
    // newPosition.position.y += defaultLenght * sin (angle);
    //std::cout << newPosition.position;
}



float Lightray::makeFunction(sf::Vector2f first, sf::Vector2f second)
{
	sf::Vector2f deltaPos = second - first;
	//cout << deltaPos;
	sf::Vector2f result;
	result.x = deltaPos.y/deltaPos.x;
	result.y = first.y - result.x * first.x;
	return result.x;
}
