#include <SFML/Graphics.hpp>
#include "CollisionHandler.h"
//#include "Lightray.h"
#include <SFML/Config.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

    CollisionHandler col(window);

	//Lightray li(0.785398163, sf::Vector2f(0, 0), 1000);
	//li.calculateVertices();
    Lightray* li = col.createRay(0.785398163, sf::Vector2f(0, 0));
    Wall* wall = col.createWall(sf::Vector2f(300, 20), sf::Vector2f(0, 100));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
		//window.draw(li.getDrawable());
		col.draw();
        window.display();

    }

    return 0;
}
