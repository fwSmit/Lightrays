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
    int maxLenght;
    double r_direction;
    sf::Vector2f position;
    sf::Color currColor = sf::Color::Yellow;
public:
    sf::Vector2f getBegin() const
    {
        return position;
    }
    sf::Vector2f getEnd() const;

    // direction in radians.
    /**0 is pointing to the right*/
    void setDirection (double direction);

    void setPosition (sf::Vector2f direction);

    void setColor (sf::Color color);

    sf::VertexArray getDrawable() const;

    Lightray(const sf::Vector2f& position, const double _direction, const int maxLenght);
    virtual ~Lightray();

protected:

private:
};

#endif // LIGHTRAY_H
