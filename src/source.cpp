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
    TwoPointObject* obj = new Mirror(sf::Vector2f(400, 100), sf::Vector2f(300, 700), window);
    TwoPointObject* obj2 = new Mirror(sf::Vector2f(500, 100), sf::Vector2f(800, 10), window);
    CollisionHandler col(window);
    //Lightray* ray = col.createRay(sf::Vector2f(200 ,500), 0.3);
    int n_rays = 0;
    std::vector<Lightray*> rays;
    for(double i = 0; i < 2 * M_PI; i+= (2 * M_PI)/n_rays){
        //rays.push_back(col.createRay(sf::Vector2f(300, 40), i));
    }
    Lightray* ray = col.createRay(sf::Vector2f(500, 700), M_PI);
    /*cout << "ray direction is set well " << boolalpha << (ray->getDirection() == M_PI_2) << endl;
    cout << "difference " << fabs(ray->getDirection() - M_PI_2) << endl;
    cout << "is vertical " << ray->isVertical() << endl;*/
    col.addPhysicsObject(obj);
    col.addPhysicsObject(obj2);
    /*rays.push_back(col.createRay(sf::Vector2f(0,0), sf::Vector2f(100,100)));
    rays.push_back(col.createRay(sf::Vector2f (100, 550), sf::Vector2f(3,4)));
    //Wall* wall = col.createWall(sf::Vector2f(400, 600), sf::Vector2f(300, 100));
    walls.push_back(col.createWall(sf::Vector2f(400, 600), sf::Vector2f(230, 100)));*/
    //walls.push_back(col.createWall(sf::Vector2f(400, 600), sf::Vector2f(400, 100)));
    //walls.push_back(col.createWall(sf::Vector2f(10, 600), sf::Vector2f(40, 1000)));
    /*
        Lightray li(sf::Vector2f(300 ,100), sf::Vector2f(300, 400), sqrt(pow(window.getSize().x, 2) + pow(window.getSize().y, 2)));
        Lightray li2( sf::Vector2f(405, 300), sf::Vector2f(300, 400), sqrt(pow(window.getSize().x, 2) + pow(window.getSize().y, 2)));
        Lightray liBounce(sf::Vector2f(300 ,400), sf::Vector2f(30, 0), sqrt(pow(window.getSize().x, 2) + pow(window.getSize().y, 2)));
        //Wall wall(sf::Vector2f(400, 600), sf::Vector2f(230, 100));
        //li.calculateVertices();
        //Lightray* li = col.createRay(degreeToRadian(100), sf::Vector2f(0, 0));
        //Wall* wall = col.createWall(sf::Vector2f(30, 230), sf::Vector2f(230, 100));
        //li.calculateVertices(col);
        //sf::Vector2f temp;


        //sf::VertexArray lines_array(sf::Lines);
        //lines_array.append(wall.getFirst());
        //lines_array.append(wall.getSecond());

        //col.draw();

        li.calculateVertices(col);
        li2.calculateVertices(col);

        float angle = op::angle(li.getDeltaPos(), li2.getDeltaPos());
        //cout << radianToDegree(angle) << endl;


        liBounce.vertices[1] = liBounce.vertices[0].position + newDeltaPos;


        li.vertices[0].color = sf::Color::Red;
        li.vertices[1].color = sf::Color::Green;
        liBounce.vertices[0].color = sf::Color::Red;
        liBounce.vertices[1].color = sf::Color::Blue;
        cout << li.getDeltaPos() << endl << li2.getDeltaPos() << endl;


        //liBounce.calculateVertices(col);
    */
    //cin.get();

    //cout << col.unIntersect(ray->vertices[0], ray->vertices[1], *wall) << endl;

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
        for(size_t i = 0; i < rays.size(); i++){
            rays[i]->setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
        }
        sf::Vector2f deltaPos = sf::Vector2f (sf::Mouse::getPosition(window)) - ray->getBegin();
        ray->setDirection(atan2(deltaPos.y, deltaPos.x));
        //window.draw(ray.getDrawable());
        //obj->setFirst(sf::Vector2f(500 + 60*sin(i), 200 + 330*cos(i)));
        //obj->setSecond(sf::Vector2f(30 + 59*sin(i), 800 + 12*cos(i)));
        //window.draw(obj->getDrawable());
        col.draw();
        //cout << sf::Mouse::getPosition(window).x << "   " << sf::Mouse::getPosition(window).y << endl;
        window.display();
        i+= 0.03;
        //cin.get();
    }
#endif

    return 0;
}

