#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(const sf::Window& _window) :  maxLenght (sqrt(pow(_window.getSize().x, 2) + pow(_window.getSize().y, 2))), window(_window)
{
    //ctor
}

CollisionHandler::~CollisionHandler()
{
    //dtor
}

Lightray* CollisionHandler::createRay(double angle, sf::Vector2f starting_position)
{
    rays_changed.push_back(Lightray(angle, starting_position, maxLenght));
    return &rays_changed[rays_changed.size()-1];
}
