#ifndef WALL_H
#define WALL_H

#include "Lightray.h"
#include<TwoPointObject.h>

class Wall : public TwoPointObject
{
    public:
    Wall(const sf::Vector2f& _first, const sf::Vector2f& _second, sf::RenderWindow& _window, sf::Color color = sf::Color::White)
    : TwoPointObject(_first, _second, _window, color){};
    virtual Hitresult getHitResult(const sf::Vector2f& hitPosition, const Lightray& ray) const override;
    virtual sf::Color getDefaultColor() { return sf::Color::White; }
};

#endif // WALL_H
