#include "CollisionHandler.h"
#include <cmath>

CollisionHandler::CollisionHandler(sf::RenderWindow& _window) :  maxLenght (sqrt(pow(_window.getSize().x, 2) + pow(_window.getSize().y, 2))), window(_window)
{
    //ctor
}

CollisionHandler::~CollisionHandler()
{
    //dtor
}

Lightray* CollisionHandler::createRay(double angle, sf::Vector2f starting_position)
{
	Lightray ray(angle, starting_position, maxLenght);
	
    rays.push_back(ray);
    //return &rays[rays.size()-1];
}

Wall* CollisionHandler::createWall(sf::Vector2f _first, sf::Vector2f _second)
{
    walls.push_back(Wall(_first, _second));
    return &walls[walls.size()-1];

}

void CollisionHandler::draw()
{
    sf::VertexArray lines_array(sf::Lines);
    for(int i = 0; i < walls.size(); i++){
        lines_array.append(walls[i].getFirst());
        lines_array.append(walls[i].getSecond());
    }
	
	for(int i = 0; i < rays.size(); i++){
		rays[i].calculateVertices(walls);
        window.draw(rays[i].getDrawable());
	}
    window.draw(lines_array);
}
