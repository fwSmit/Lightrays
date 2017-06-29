#include "Lightray.h"
#include <iostream>
#include <assert.h>
#define M_PI		3.14159265358979323846
#include "CollisionHandler.h"
#include "vectorOperations.h"

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
    vertices[0].position = starting_position;
    vertices[0].color = sf::Color::Yellow;
    vertices[1].color = sf::Color::Yellow;
}

Lightray::~Lightray()
{
    //dtor
}

sf::Vector2f Lightray::getDeltaPos()
{
    return op::deltaPos(vertices[0].position, vertices[1].position);
}

void Lightray::setColor(sf::Color color)
{
    for(int i = 0; i< vertices.getVertexCount(); i++){
        vertices[i].color = color;
    }
}


void Lightray::setDirection(sf::Vector2f _direction)
{
    direction = _direction;
}

void Lightray::setPosition(sf::Vector2f _position)
{
    assert (getVertexCount() > 0);
    vertices[0].position = _position;
}

sf::Vector2f Lightray::getPosition() const
{
    assert (getVertexCount() > 0);
    return vertices[0].position;
}


void Lightray::calculateVertices(CollisionHandler& col){
    /**< WARNING: This could get out of bounds */
    assert(vertices.getVertexCount() > 0);

    sf::Vector2f deltaPos = direction - vertices[0].position;

    float lenght = sqrt(pow(deltaPos.x, 2) + pow(deltaPos.y, 2));

    deltaPos *= defaultLenght / lenght;

    vertices[1].position = vertices[0].position + deltaPos;
    //vertices[1].color = sf::Color::Yellow;

    //sf::Vector2f result;
    //if(col.getIntersectWall(vertices[0], vertices[1], result)){

    //}

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
