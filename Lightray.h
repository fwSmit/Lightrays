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
    friend class CollisionHandler;
    int defaultLenght;
    sf::Vector2f direction;
    sf::VertexArray vertices;
public:
    sf::VertexArray getVertices() const { return vertices; }
    void calculateVertices(class CollisionHandler& col);
    sf::Vector2f getDeltaPos();
    inline size_t getVertexCount() const { return vertices.getVertexCount(); }
    sf::Vector2f getPosition () const;
    // the ray will point at the target direction
    void setDirection (sf::Vector2f direction);
    void setPosition (sf::Vector2f position);

    void setColor (sf::Color color);
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
