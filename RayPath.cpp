#include "Lightray.h"
#include "RayPath.h"


RayPath::RayPath() : vertices(sf::Lines, 0)
{
    //ctor
}

RayPath::~RayPath()
{
    //dtor
}

void RayPath::addRay(const Lightray& ray)
{
    if(!isLastrayValid)
    {
        isLastrayValid = true;
    }
    lastRay = ray;
    vertices.append(lastRay.getBegin());
}


sf::VertexArray RayPath::getDrawable() const
{
    sf::VertexArray vertices_result = vertices;
    if(isLastrayValid)
    {
        vertices_result.append(lastRay.getEnd());
    }
    return vertices_result;
}
