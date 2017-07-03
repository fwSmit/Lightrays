#ifndef WALL_H
#define WALL_H

#include<TwoPointObject.h>

class Wall : public TwoPointObject
{
    public:
    Wall(const sf::Vector2f& _first, const sf::Vector2f& _second, sf::RenderWindow& _window) : TwoPointObject(_first, _second, _window){};
    virtual Hitresult getHitResult(sf::Vector2f hitPosition) override;
    virtual sf::Color getDefaultColor() { return sf::Color::White; }
};

#endif // WALL_H
