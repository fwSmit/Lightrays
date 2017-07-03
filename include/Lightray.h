#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "mathDefines.h"
#include <limits>

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj);

using namespace std;

float radianToDegree(float radians);

class Lightray
{
    sf::Vector2f position;

    // this is only valid when hasEnd is true
    sf::Vector2f endOfRay;

    // direction in radians.
    /**0 is pointing to the right*/
    float r_direction;
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

    float getDirection() const { return r_direction; }

    // direction in radians.
    /**0 is pointing to the right*/
    void setDirection (float direction);

    void setPosition (sf::Vector2f direction);

    void setColor (sf::Color color);

    void setEnd (sf::Vector2f _end);

    void resetEnd() { hasEnd = false; }

    sf::VertexArray getDrawable() const;

    Lightray(const sf::Vector2f& position, const float _direction, const int maxLenght);

    virtual ~Lightray();

    Lightray(){ initialized = false; }

    bool isInBounds(sf::Vector2f test) const;

    // this doesn't work well because of floating point precision;
    bool isVertical() const {
        float absDifference1 = fabs(getDirection() - M_PI_2);
        float absDifference2 = fabs(getDirection() -  (2 * M_PI - M_PI_2));
        return absDifference1 < std::numeric_limits<float>::epsilon() || absDifference2 < std::numeric_limits<float>::epsilon();
    }

    // this ignores that the ray can sometimes be vertical
    // if the ray is vertical this returns true
    bool isPointingLeft() const;

    // this ignores that the ray can sometimes be horizontal
    // if the ray is horizontal this returns false
    bool isPointingUp() const;

    //bool isHorizontal() const { return getDirection() == M_PI || getDirection() == 0; }

protected:

private:
};

#endif // LIGHTRAY_H
