#include "Lightray.h"
#include <iostream>
#define M_PI		3.14159265358979323846

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
Lightray::Lightray(double _angle, sf::Vector2f starting_position, const int maxLenght) : vertices(sf::LinesStrip), defaultLenght(maxLenght)
{
    setStartingPosition(starting_position);
    angle = _angle;
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



void Lightray::calculateVertices(vector<Wall> walls){
    /**< WARNING: This could get out of bounds */
	float wallFunction, lineFuntion = sin(angle);
	cout << "lineFunction: " << lineFuntion << endl;
	for(int i = 0; i < walls.size(); i++){
		// y = ax + b

		wallFunction = makeFunction(walls[i].getFirst(), walls[i].getSecond());
		cout << wallFunction << endl;
		sf::Vector2f temp = (vertices[0].position - walls[i].getFirst())/(wallFunction-lineFuntion);
		float xIntersect = temp.x + temp.y;
		float yIntersect = wallFunction * (xIntersect - walls[i].getFirst().x) + walls[i].getFirst().y;
		cout << "X intersect = " << xIntersect << endl;
		cout << "Y intersect = " << xIntersect << endl;
	}

    sf::Vertex newPosition = vertices[0];
    newPosition.position.x += defaultLenght * cos (angle);
    newPosition.position.y += defaultLenght * sin (angle);
    vertices.append(newPosition);
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
