#include "Project_lightrays.h"

Project_lightrays::Project_lightrays(sf::RenderWindow& _window) : Project(_window), col(window)
{
    obj = new Mirror(sf::Vector2f(400, 100), sf::Vector2f(300, 700), window);
    obj2 = new Mirror(sf::Vector2f(500, 100), sf::Vector2f(800, 10), window);
    //Lightray* ray = col.createRay(sf::Vector2f(200 ,500), 0.3);
    int n_rays = 0;
    std::vector<Lightray*> rays;
    for(double i = 0; i < 2 * M_PI; i+= (2 * M_PI)/n_rays) {
        //rays.push_back(col.createRay(sf::Vector2f(300, 40), i));
    }
    ray = col.createRay(sf::Vector2f(500, 700), M_PI);

    col.addPhysicsObject(obj);
    col.addPhysicsObject(obj2);
}

Project_lightrays::~Project_lightrays()
{
    //dtor
}

Project_lightrays::loop()
{
    sf::Vector2f deltaPos = sf::Vector2f (sf::Mouse::getPosition(window)) - ray->getBegin();
    ray->setDirection(atan2(deltaPos.y, deltaPos.x));
    ////window.draw(ray.getDrawable());
    ////obj->setFirst(sf::Vector2f(500 + 60*sin(i), 200 + 330*cos(i)));
    ////obj->setSecond(sf::Vector2f(30 + 59*sin(i), 800 + 12*cos(i)));
    ////window.draw(obj->getDrawable());
    col.draw();
}
