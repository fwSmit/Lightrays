#include "CollisionHandler.h"

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
    rays.push_back(Lightray(angle, starting_position, maxLenght));
    return &rays[rays.size()-1];
}

Wall* CollisionHandler::createWall(sf::Vector2f _first, sf::Vector2f _second)
{
    walls.push_back(Wall(_first, _second));
    return &walls[walls.size()-1];

}

void CollisionHandler::draw()
{
    sf::VertexArray lines_array(sf::Lines);
    for(auto i : walls){
        lines_array.append(i.getFirst());
        lines_array.append(i.getSecond());
    }
    for(auto& i : rays){
        i.calculateVertices();
        window.draw(i.getDrawable());
    }
    window.draw(lines_array);
}
