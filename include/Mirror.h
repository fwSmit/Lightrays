#ifndef MIRROR_H
#define MIRROR_H

#include "Lightray.h"
#include <TwoPointObject.h>


class Mirror : public TwoPointObject
{
    public:
        Mirror(const sf::Vector2f& _first, const sf::Vector2f& _second, sf::RenderWindow& _window) : TwoPointObject(_first, _second, _window){};
        virtual Hitresult getHitResult(const sf::Vector2f& hitPosition, const Lightray& ray) const override;
        virtual ~Mirror();
        inline sf::Color getDefaultColor() override { return sf::Color::Blue; }

    protected:

    private:
};

#endif // MIRROR_H
