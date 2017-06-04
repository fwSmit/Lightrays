#include "Lightray.h"
#include <iostream>

/*!
* Copies bytes from a source memory area to a destination memory area,
* where both areas may not overlap.
* @param  direction: (in degrees) the direction of the ray
*/

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj)
{
    os << obj.x << "    " << obj.y << std::endl;

    return os;
}



Lightray::Lightray(double _angle, sf::Vector2f starting_position, const int maxLenght) : vertices(sf::LineStrip), defaultLenght(maxLenght)
{
    setStartingPosition(starting_position);
    angle = _angle;
    calculateVertices();
    cout << cos (angle) << endl << sin (angle) << endl;
}

Lightray::~Lightray()
{
    //dtor
}

void Lightray::setStartingPosition(sf::Vector2f position){
    if(vertices.getVertexCount() == 0){
        vertices.append(sf::Vertex(position, sf::Color::Red));
    }else{
        vertices[0].position = position;
    }
}

void Lightray::calculateVertices(){
    /**< WARNING: This could get out of bounds */
    sf::Vertex newPosition = vertices[0];
    newPosition.position.x += defaultLenght * cos (angle);
    newPosition.position.y += defaultLenght * sin (angle);
    vertices.append(newPosition);
    std::cout << newPosition.position;
}
