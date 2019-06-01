#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML/Graphics/VertexArray.hpp>

class PhysicsObject
{
    public:
        PhysicsObject(){};
        virtual ~PhysicsObject(){};
        virtual bool collide (const class Lightray& ray, class Hitresult& hitresult, bool debugDraw = false) = 0;
        virtual class sf::VertexArray getDrawable() = 0;
    protected:

    private:
};

#endif // PHYSICSOBJECT_H
