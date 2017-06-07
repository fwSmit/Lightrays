#include <SFML/Graphics.hpp>
#include "CollisionHandler.h"
//#include "Lightray.h"
#include <SFML/Config.hpp>
#include <iostream>
#define M_PI		3.14159265358979323846

#define USE_SFML_WINDOW

float degreeToRadian(float degree)
{
    return (degree) * (M_PI/180);
}

/*sf::Vector2f getIntersect(const Lightray& first, const Lightray& second, sf::Vector2f& result)
{
    float angle_first = first.angle;
    float angle_second = second.angle;

    float steepness_first = tan(angle_first);
    float steepness_second = tan(angle_second);

    // y = a(x - Px) + Py

    sf::Vector2f positionFirst = first.vertices[0].position;
    sf::Vector2f positionSecond = second.vertices[0].position;

    float xIntersect = (steepness_first*positionFirst.x - positionFirst.y - steepness_second * positionSecond.x + positionSecond.y)/(steepness_first - steepness_second);

    printf("angles are %f and %f\n", radianToDegree(angle_first), radianToDegree(angle_second));

    printf("steepness is %f and %f\n", steepness_first, steepness_second);

    printf("x intersect is %f \n", xIntersect);
    return sf::Vector2f(300, 20);
}*/



//void drawDebugCircle(sf::RenderWindow& window, sf::Vector2f position, ){

//}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::CircleShape intersect(10);
    intersect.setOrigin(sf::Vector2f(intersect.getRadius(), intersect.getRadius()));
    intersect.setFillColor(sf::Color::Green);

    CollisionHandler col(window);

    Lightray li( sf::Vector2f(0, 0),  sf::Vector2f(3, 4), sqrt(pow(window.getSize().x, 2) + pow(window.getSize().y, 2)));
    //Lightray li2(degreeToRadian(10), sf::Vector2f(0, 200), 1000);
    Wall wall(sf::Vector2f(400, 600), sf::Vector2f(230, 100));
    //li.calculateVertices();
    //Lightray* li = col.createRay(degreeToRadian(100), sf::Vector2f(0, 0));
    //Wall* wall = col.createWall(sf::Vector2f(30, 230), sf::Vector2f(230, 100));
    li.calculateVertices(col);
    sf::Vector2f temp;


    sf::VertexArray lines_array(sf::Lines);
    lines_array.append(wall.getFirst());
    lines_array.append(wall.getSecond());

    //col.draw();
    //li2.calculateVertices(vector<Wall>());

#ifdef USE_SFML_WINDOW
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(li.getDrawable());
        //window.draw(li2.getDrawable());
        window.draw(lines_array);
        window.draw(intersect);
        //wall.first = sf::Vector2f(sf::Mouse::getPosition(window));
        lines_array[0].position = wall.first;
        lines_array[1].position = wall.second;
        if(col.getIntersectWall(li.vertices[0].position, li.vertices[1].position, wall, temp)){
            intersect.setPosition(temp);
        }else{
            intersect.setPosition(0,0);
        }
        //col.draw();
        //cout << sf::Mouse::getPosition(window).x << endl;
        window.display();

    }
#endif

    return 0;
}
