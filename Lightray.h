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
    double angle;
    sf::VertexArray vertices;
public:
    void calculateVertices(vector<Wall> walls);
	
    void setAngle(double angle);
    void setStartingPosition(sf::Vector2f position);
	
	/**
 * @brief gives the value of a for the function y = ax + b 
 * @param first point on the funtion line
 * @param second point on the funtion line
 * @return slope of the line
 * @warning negative slope is pointing up
 */
	float makeFunction(sf::Vector2f first, sf::Vector2f second); 
    Lightray(double angle, sf::Vector2f starting_position, const int maxLenght);
    virtual ~Lightray();
    sf::VertexArray getDrawable() const
    {
        return vertices;
    }
protected:

private:
};

#endif // LIGHTRAY_H
