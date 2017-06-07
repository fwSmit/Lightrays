#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <SFML/Graphics.hpp>
#include "Wall.h"
//#include <math.h>

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj);

using namespace std;

float radianToDegree(float radians);

class Lightray
{
    int defaultLenght;
    sf::Vector2f direction;
public:
    sf::VertexArray vertices;
    sf::VertexArray getVertices() const { return vertices; }
    void calculateVertices(class CollisionHandler& col);


	/**
 * @brief gives the value of a for the function y = ax + b
 * @param first point on the funtion line
 * @param second point on the funtion line
 * @return slope of the line
 * @warning negative slope is pointing up
 */
	float makeFunction(sf::Vector2f first, sf::Vector2f second);
    Lightray(sf::Vector2f starting_position, sf::Vector2f _direction, const int maxLenght);
    virtual ~Lightray();
    sf::VertexArray getDrawable() const
    {
        return vertices;
    }
protected:

private:
};

#endif // LIGHTRAY_H
