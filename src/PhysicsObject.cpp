#include "Hitresult.h"
#include "Lightray.h"
#include "PhysicsObject.h"
#include <SFML/Graphics/VertexArray.hpp>

bool PhysicsObject::collide(const class Lightray& ray, class Hitresult& hitresult, bool debugDraw)
{
    // pure virtual
}

sf::VertexArray PhysicsObject::getDrawable()
{
    // pure virtual
}
