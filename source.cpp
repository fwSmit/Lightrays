#include <SFML/Graphics.hpp>
#include "CollisionHandler.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

    CollisionHandler col(window);

    col.createRay(0.785398163, sf::Vector2f(0, 0));
    //Lightray test(0.785398163, sf::Vector2f(0, 0), maxLenght);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }

    return 0;
}
