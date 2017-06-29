#ifndef WALL_H
#define WALL_H

#include<SFML/Graphics.hpp>

class Wall
{
public:
    sf::Vector2f first, second;
    Wall(sf::Vector2f _first, sf::Vector2f _second);
    virtual ~Wall();
    //sf::Vector2f getFirst()     const   { return first;}
    //sf::Vector2f getSecond()    const   { return second;}


    // returns the left vertex (lowest x-coordinate
    sf::Vector2f getLeft()          const;

    // returns the right vertex (highest x-coordinate)
    sf::Vector2f getRight()         const;


    // returns the highest vertex (highest y-coordinate)
    sf::Vector2f getTop()           const;

    // returns the lowest vertex (lowest y-coordinate)
    sf::Vector2f getBottom()        const;
protected:

private:
};

#endif // WALL_H
