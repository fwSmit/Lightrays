#include "Wall.h"

const sf::Color Wall::defaultColor = sf::Color::White;

Wall::Wall(sf::Vector2f _first, sf::Vector2f _second)
{
    // make sure the points are defined from left to right
    //if(_first.x > _second.x){
        first.position = _first;
        first.color = Wall::defaultColor;
        second.position = _second;
        second.color = Wall::defaultColor;
    //}else{
    //    first = _first;
     //   second = _second;
   // }

}

Wall::~Wall()
{
    //dtor
}

sf::Vector2f Wall::getLeftPosition() const
{
    if (first.position.x < second.position.x){
        return first.position;
    }else{
        return second.position;
    }
}

sf::Vector2f Wall::getRightPosition() const
{
    if (first.position.x < second.position.x){
        return second.position;
    }else{
        return first.position;
    }
}

sf::Vector2f Wall::getTop() const
{
    if (first.position.y < second.position.y){
        return second.position;
    }else{
        return first.position;
    }
}

sf::Vector2f Wall::getBottom() const
{
    if (first.position.y < second.position.y){
        return first.position;
    }else{
        return second.position;
    }
}

void Wall::setColor (sf::Color color){
    first.color = color;
    second.color = color;
}

