#include <SFML/Graphics.hpp>
//#include "CollisionHandler.h"
#include "Lightray.h"
#include <SFML/Config.hpp>
#define M_PI		3.14159265358979323846

#define USE_SFML_WINDOW

float degreeToRadian(float degree){
	return (degree) * (M_PI/180);
}

sf::Vector2f getIntersect(Lightray first, Lightray second){
	double angle_first = first.angle;
	double angle_second = second.angle;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");


    //CollisionHandler col(window);

	Lightray li(0.785398163, sf::Vector2f(0, 0), 1000);
	Lightray li2(degreeToRadian(10), sf::Vector2f(0, 200), 1000);
	//li.calculateVertices();
    //Lightray* li = col.createRay(degreeToRadian(100), sf::Vector2f(0, 0));
    //Wall* wall = col.createWall(sf::Vector2f(30, 230), sf::Vector2f(230, 100));

	//col.draw();
	li.calculateVertices(vector<Wall>());
    li2.calculateVertices(vector<Wall>());

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
		window.draw(li.getDrawable());
		window.draw(li2.getDrawable());
		//col.draw();
        window.display();

    }
	#endif

    return 0;
}
