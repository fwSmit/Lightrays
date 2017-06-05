#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Lightray.h"
#include "Wall.h"

using namespace std;

class CollisionHandler
{
    const float maxLenght;
    vector<Lightray> rays;
    sf::RenderWindow& window;
    vector<Wall> walls;

    public:
        CollisionHandler(sf::RenderWindow& _window);
        virtual ~CollisionHandler();
        Lightray* createRay(double angle, sf::Vector2f starting_position);
        Wall* createWall(sf::Vector2f _first, sf::Vector2f _second);
        void draw();
    protected:

    private:
};

#endif // COLLISIONHANDLER_H
