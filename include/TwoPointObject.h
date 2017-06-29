#ifndef TWOPOINTOBJECT_H
#define TWOPOINTOBJECT_H

#include <SFML/Graphics.hpp>


class TwoPointObject
{
    sf::Vertex first, second;

public:
    inline virtual sf::Color getDefaultColor() { return sf::Color::Red; }

    TwoPointObject(sf::Vector2f _first, sf::Vector2f _second);
    virtual ~TwoPointObject();

    // returns the left vertex (lowest x-coordinate
    sf::Vector2f getLeftPosition()          const;

    // returns the right vertex (highest x-coordinate)
    sf::Vector2f getRightPosition()         const;


    // returns the highest vertex (highest y-coordinate)
    sf::Vector2f getTop()           const;

    // returns the lowest vertex (lowest y-coordinate)
    sf::Vector2f getBottom()        const;

    sf::Vertex getFirstVertex() const { return first; }
    sf::Vertex getSecondVertex() const { return second; }

    void setFirst(sf::Vector2f _first) { first.position = _first; }

    void setSecond(sf::Vector2f _second) { second.position = _second; }

    void setColor (sf::Color color);


};

#endif // TWOPOINTOBJECT_H
