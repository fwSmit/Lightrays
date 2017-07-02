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
    sf::Vector2f position;

    // this is only valid when hasEnd is true
    sf::Vector2f endOfRay;
    double r_direction;
    int maxLenght;
    sf::Color currColor = sf::Color::Yellow;
    bool initialized;
    bool hasEnd;
    void checkInitialized() const;
public:

    sf::Vector2f getBegin() const
    {
        checkInitialized();
        return position;
    }
    sf::Vector2f getEnd() const;

    double getDirection() const { return r_direction; }
    // direction in radians.
    /**0 is pointing to the right*/
    void setDirection (double direction);

    void setPosition (sf::Vector2f direction);

    void setColor (sf::Color color);

    void setEnd (sf::Vector2f _end);

    void resetEnd() { hasEnd = false; }

    sf::VertexArray getDrawable() const;

    Lightray(const sf::Vector2f& position, const double _direction, const int maxLenght);
    virtual ~Lightray();

    Lightray(){ initialized = false; }

protected:

private:
};

#endif // LIGHTRAY_H
