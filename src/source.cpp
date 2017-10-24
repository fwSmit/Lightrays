/** bug :
    TwoPointObject* obj = new Wall(sf::Vector2f(300, 100), sf::Vector2f(300, 700), window);
    Lightray* ray = col.createRay(sf::Vector2f(400, 500), rotation);
    dont collide
*/

#include <SFML/Graphics.hpp>
#include "CollisionHandler.h"
//#include "Lightray.h"
#include <SFML/Config.hpp>
#include <iostream>
#include "vectorOperations.h"
#include <SFML/Window/ContextSettings.hpp>
#include <assert.h>
#include "RayPath.h"
#include "mathDefines.h"
#include "Mirror.h"
#include "Project_lightrays.h"
//#include "Project.h"

#define USE_SFML_WINDOW
using namespace std;


float degreeToRadian(float degree)
{
    return (degree) * (M_PI/180);
}

/*
class A {
public:
    virtual void print(){
        cout << "class a" << endl;
    }
};

class B : public A{
public:
    virtual void print(){
        cout << "class  B" << endl;
    }
};
*/
int main()
{
    //int currentRay = -1;
    //int currentWall = 0;
    //std::vector <Lightray* > rays;
    //std::vector <Wall* > walls;
    //cout << op::rotate(sf::Vector2f(1,0), degreeToRadian(180));
    //cin.get();
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    settings.majorVersion = 4;
    settings.minorVersion = 5;
    sf::RenderWindow window(sf::VideoMode(900, 800), "SFML works!", sf::Style::Default, settings);
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);

    Project_lightrays lightrays(window);

#ifdef USE_SFML_WINDOW
double i = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
            case sf::Event::KeyReleased:
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    break;
                }
                /*if(event.key.code == sf::Keyboard::L){
                    currentRay++;
                    break;
                }
                if(event.key.code == sf::Keyboard::K){
                    currentRay--;
                    break;
                }
                if(event.key.code == sf::Keyboard::O){
                    currentWall--;
                    break;
                }
                if(event.key.code == sf::Keyboard::P){
                    currentWall++;
                    break;
                }*/
                break;
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::JoystickButtonReleased:
                if(event.joystickButton.button == 1) {
                    window.close();
                }
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left){
                    /*sf::Vector2f pos = sf::Vector2f(event.mouseButton.x - 1, event.mouseButton.y - 1);
                    if(rays.size() > 0 && currentRay >= 0){
                        rays[currentRay]->setPosition(pos);
                    }*/
                }
                //cout << "ray vertices size" << ray->vertices.getVertexCount() << endl;
                //cout << ray->getVertices()[0].position.x << endl;
                    //ray->vertices[0] = /*sf::Vector2f(sf::Mouse::getPosition(window)) -*/sf::Vector2f (100 , 10);
                    //ray->calculateVertices(col);
                break;

                default:
                break;
            }
        }


        /*if(rays.size() > 0 && currentRay >= 0){
            for(int i = 0; i < rays.size(); i++){
                rays[i]->setColor(sf::Color::Yellow);
            }
            if(currentRay > rays.size() -1){
                currentRay = 0;
            }
            rays[currentRay]->setColor(sf::Color::Green);
            rays[currentRay]->setDirection(sf::Vector2f(sf::Mouse::getPosition(window)));
        }

        if(walls.size() > 0 && currentWall >= 0){
            for(int i = 0; i < walls.size(); i++){
                walls[i]->setColor(sf::Color::White);
            }
            if(currentWall > walls.size() - 1){
                currentWall = 0;
            }
            walls[currentWall]->setColor(sf::Color::Green);
            walls[currentWall]->setFirst(sf::Vector2f(sf::Mouse::getPosition(window)));
        }*/



        //ray2->setDirection(sf::Vector2f(sf::Mouse::getPosition(window)));
        window.clear();
        //for(size_t i = 0; i < rays.size(); i++){
        //    rays[i]->setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
       //}
       lightrays.loop();

        //cout << sf::Mouse::getPosition(window).x << "   " << sf::Mouse::getPosition(window).y << endl;
        window.display();
        i+= 0.03;
        //cin.get();
    }
#endif

    return 0;
}

