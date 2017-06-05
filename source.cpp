#include <SFML/Graphics.hpp>
#include "CollisionHandler.h"
//#include "Lightray.h"
#include <SFML/Config.hpp>
#include <math.h>

#define USE_SFML_WINDOW

float degreeToRadian(float degree){
	return (degree-90) * (M_PI/180);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!"); 
	

    CollisionHandler col(window);

	//Lightray li(0.785398163, sf::Vector2f(0, 0), 1000);
	//li.calculateVertices();
    Lightray* li = col.createRay(degreeToRadian(100), sf::Vector2f(0, 0));
    Wall* wall = col.createWall(sf::Vector2f(30, 230), sf::Vector2f(230, 100));

	col.draw();
    
	#ifdef USE_SFML_WINDOW
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
	#endif

    return 0;
}
