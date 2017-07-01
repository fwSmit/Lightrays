#include "Lightray.h"
#include "RayPath.h"
#include <iostream>


RayPath::RayPath() : vertices(sf::LinesStrip, 0)
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
    for(int i = 0; i < vertices_result.getVertexCount(); i++){
            vertices_result[i].color = currColor;
    }
    return vertices_result;
}
