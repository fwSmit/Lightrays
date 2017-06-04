#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Lightray.h"

using namespace std;

class CollisionHandler
{
    const float maxLenght;
    vector<Lightray> rays_changed;
    vector<Lightray> rays_unchanged;
    const sf::Window& window;
    //vector<Lightray> mirrors_changed;
    //vector<Lightray> mirrors_unchanged;

    public:
        CollisionHandler(const sf::Window& _window);
        virtual ~CollisionHandler();
        Lightray* createRay(double angle, sf::Vector2f starting_position);//
        void draw();
    protected:

    private:
};

#endif // COLLISIONHANDLER_H
