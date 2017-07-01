#ifndef WALL_H
#define WALL_H

#include<TwoPointObject.h>

class Wall : public TwoPointObject
{
    public:
    Wall(sf::Vector2f _first, sf::Vector2f _second); //: TwoPointObject(_first, _second){};

    virtual sf::Color getDefaultColor() { return sf::Color::White; }
};

#endif // WALL_H
