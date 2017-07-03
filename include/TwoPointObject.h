#ifndef TWOPOINTOBJECT_H
#define TWOPOINTOBJECT_H

#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Hitresult.h"



class TwoPointObject : public PhysicsObject
{
    sf::Vertex first, second;
    sf::RenderWindow& window;
    bool isInBounds(const sf::Vector2f& test , const Lightray& ray) const;

public:
    sf::RenderWindow& getWindow() { return window; }

    inline virtual sf::Color getDefaultColor() { return sf::Color::Red; }

    TwoPointObject(sf::Vector2f _first, sf::Vector2f _second, sf::RenderWindow& debugWindow);

    // so no instance of TwoPointObject can be made
    virtual ~TwoPointObject() = 0;

    // returns the left vertex (lowest x-coordinate
    sf::Vector2f getLeftPosition()          const;

    // returns the right vertex (highest x-coordinate)
    sf::Vector2f getRightPosition()         const;


    // returns the highest vertex (highest y-coordinate)
    sf::Vector2f getTop()           const;

    // returns the lowest vertex (lowest y-coordinate)
    sf::Vector2f getBottom()        const;

    // this is faster than the get top, bottom, left, right
    sf::Vector2f getFirstPosition()        const { return first.position; };

    // this is faster than the get top, bottom, left, right
    sf::Vector2f getSecondPosition()        const { return second.position; };

    sf::Vertex getFirstVertex() const { return first; }
    sf::Vertex getSecondVertex() const { return second; }

    void setFirst(sf::Vector2f _first) { first.position = _first; }

    void setSecond(sf::Vector2f _second) { second.position = _second; }

    void setColor (sf::Color color);

    virtual sf::VertexArray getDrawable() override;

    virtual bool collide (const class Lightray& ray, class Hitresult& hitresult, bool debugDraw = false) override;

    virtual Hitresult getHitResult(sf::Vector2f hitPosition);

    bool checkHit(const sf::Vector2f& intersection, const Lightray& ray, Hitresult& hitResult, bool debugDraw);

    void drawDebugCircle(sf::Vector2f position, bool debugDraw);
};

#endif // TWOPOINTOBJECT_H
