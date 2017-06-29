#ifndef WALL_H
#define WALL_H

#include<SFML/Graphics.hpp>

class Wall
{
    sf::Vertex first, second;
public:
    const static sf::Color defaultColor;
    Wall(sf::Vector2f _first, sf::Vector2f _second);
    virtual ~Wall();
    //sf::Vector2f getFirst()     const   { return first;}
    //sf::Vector2f getSecond()    const   { return second;}


    // returns the left vertex (lowest x-coordinate
    sf::Vector2f getLeftPosition()          const;

    // returns the right vertex (highest x-coordinate)
    sf::Vector2f getRightPosition()         const;


    // returns the highest vertex (highest y-coordinate)
    sf::Vector2f getTop()           const;

    // returns the lowest vertex (lowest y-coordinate)
    sf::Vector2f getBottom()        const;

    void setFirst(sf::Vector2f _first) { first.position = _first; }

    void setSecond(sf::Vector2f _second) { second.position = _second; }

    void setColor (sf::Color color);

    sf::Vertex getFirstVertex() const { return first; }
    sf::Vertex getSecondVertex() const { return second; }

protected:

private:
};

#endif // WALL_H
