#include "Wall.h"

Wall::Wall(sf::Vector2f _first, sf::Vector2f _second)
{
    // make sure the points are defined from left to right
    //if(_first.x > _second.x){
        first = _first;
        second = _second;
    //}else{
    //    first = _first;
     //   second = _second;
   // }

}

Wall::~Wall()
{
    //dtor
}

sf::Vector2f Wall::getLeft() const
{
    if (first.x < second.x){
        return first;
    }else{
        return second;
    }
}

sf::Vector2f Wall::getRight() const
{
    if (first.x < second.x){
        return second;
    }else{
        return first;
    }
}

sf::Vector2f Wall::getTop() const
{
    if (first.y < second.y){
        return second;
    }else{
        return first;
    }
}

sf::Vector2f Wall::getBottom() const
{
    if (first.y < second.y){
        return first;
    }else{
        return second;
    }
}


