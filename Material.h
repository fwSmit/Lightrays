#ifndef MATERIAL_H
#define MATERIAL_H

#include <PhysicsObject.h>


class Material : public PhysicsObject
{
    // properties:
    // velocity of light through this material

public:
    Material();
    virtual ~Material();
    virtual bool collide (const class Lightray& ray, class Hitresult& hitresult, bool debugDraw = false) = 0;
    virtual class sf::VertexArray getDrawable() = 0;
protected:

private:
};

#endif // MATERIAL_H
