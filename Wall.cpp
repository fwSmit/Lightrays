#include "Wall.h"

Wall::Wall(sf::Vector2f _first, sf::Vector2f _second)
{
    // make sure the points are defined from left to right
    if(_first.x > _second.x){
        first = _second;
        second = _first;
    }else{
        first = _first;
        second = _second;
    }

}

Wall::~Wall()
{
    //dtor
}
