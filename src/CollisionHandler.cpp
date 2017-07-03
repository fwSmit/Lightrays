#include "CollisionHandler.h"
//#include <cmath>
#include <assert.h>
#include "vectorOperations.h"
#include <iostream>


CollisionHandler::CollisionHandler(sf::RenderWindow& _window) :  maxLenght (op::length(_window.getSize())), window(_window)
{
    //ctor
}
CollisionHandler::~CollisionHandler()
{
    //dtor
}

Lightray* CollisionHandler::createRay(sf::Vector2f starting_position, float _direction)
{
    std::unique_ptr<Lightray> ray(new Lightray(starting_position, _direction, maxLenght));
    rays.push_back(std::move(ray));
    std::cout << "created a ray" << std::endl;
    return rays.back().get();
}

bool CollisionHandler::addPhysicsObject(PhysicsObject* obj)
{
    physicsObjects.push_back(std::unique_ptr<PhysicsObject>(obj));
    std::cout << "created a physics object" << std::endl;
    return true;
}


void CollisionHandler::draw()
{
    std::vector<RayPath> rayPaths = update();

    for(size_t i = 0; i < rayPaths.size(); i++) {
        window.draw(rayPaths[i].getDrawable());
    }

    for(size_t i = 0; i < physicsObjects.size(); i++) {
        window.draw(physicsObjects[i]->getDrawable());
    }

    for(size_t i = 0; i < rays.size(); i++) {
        //rays[i].calculateVertices(walls);
        rays[i]->resetEnd();
        //window.draw((*rays[i]).getDrawable());
    }
}

/*bool CollisionHandler::getIntersectWall(const sf::Vector2f& begin, const sf::Vector2f& end, sf::Vector2f& result, Wall& hitResult, bool debugPrint)
{
    for(int i = 0; i < walls.size(); i++) {
        if(getIntersectWall(begin, end, walls[i], result, debugPrint)) {
            hitResult = walls[i];
            return true;
        }
    }
    return false;
}*/


std::vector<RayPath> CollisionHandler::update()
{
    std::vector<RayPath> result(rays.size());
    for(size_t i = 0; i < rays.size(); i++) {
        result[i] = update(*rays[i]);
    }
    return result;
}


RayPath CollisionHandler::update(Lightray& ray)
{
    RayPath result;

    Hitresult hitresult;
    bool isHit = false;
    for(auto& i : physicsObjects) {
        Hitresult hitTemp;
        if((*i).collide(ray, hitTemp, debugDraw)) {
            switch (hitTemp.hitType) {
            case HitType::block:
                hitresult = hitTemp;
                isHit = true;
                break;
            default:
                break;
            }
        }
    }
    if(isHit) {
        ray.setEnd(hitresult.hitPosition);
    }
    result.addRay(ray);
    return result;
}

/*bool CollisionHandler::unIntersect(sf::Vertex& a, sf::Vertex& b)
{
    sf::Vector2f result;
    bool changed = false;
    //std::cout << "wall size " << walls.size() << std::endl;
    for(auto& currWall : walls) {
        //std::cout << "in unintersect b.position = " <<  b.position << std::endl;
        if(getIntersectWall(a.position, b.position, *currWall, result, false, false)) {
            b.position = result;
            changed = true;
        }
    }
    return changed;
}*/


