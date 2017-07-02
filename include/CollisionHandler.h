#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Lightray.h"
#include "Wall.h"
#include "PhysicsObject.h"
#include "RayPath.h"


using namespace std;

class CollisionHandler
{
    const float maxLenght;
    vector<std::unique_ptr<Lightray>> rays;
    sf::RenderWindow& window;
    vector<std::unique_ptr<PhysicsObject>> physicsObjects;
    std::vector<RayPath> update();
    RayPath update(Lightray& ray);
    bool debugDraw = false;

    /** \brief makes sure the line between vertices a and b don't intersect any walls
     *
     * \return true if the vertices were changed, false if not
     *
     */
public:
    //bool unIntersect(sf::Vertex& a, sf::Vertex& b);
    //bool getIntersectWall(const sf::Vector2f& begin, const sf::Vector2f& end, sf::Vector2f& result, Wall& hitResult, bool debugPrint = false);
    CollisionHandler(sf::RenderWindow& _window);
    virtual ~CollisionHandler();
    Lightray* createRay(sf::Vector2f starting_position, double _direction);
    bool addPhysicsObject(PhysicsObject* obj);
    void draw();


protected:

private:
};

#endif // COLLISIONHANDLER_H
