#ifndef WALL_H
#define WALL_H

#include<SFML/Graphics.hpp>

class Wall
{
public:
    sf::Vector2f first, second;
    Wall(sf::Vector2f _first, sf::Vector2f _second);
    virtual ~Wall();
    sf::Vector2f getFirst()     const   { return first;}
    sf::Vector2f getSecond()    const   { return second;}
protected:

private:
};

#endif // WALL_H
