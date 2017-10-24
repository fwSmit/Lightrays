#ifndef RAYPATH_H
#define RAYPATH_H

#include "Lightray.h"


class RayPath
{
    class Lightray lastRay;
    bool isLastrayValid = false;
    sf::VertexArray vertices;
    sf::Color currColor = sf::Color::Yellow;
    public:
        RayPath();
        virtual ~RayPath();
        void addRay(const Lightray& ray);
        void addRayPath(const RayPath rayPath);
        Lightray getLastRay() const { return lastRay; }

        // dont use this for drawing, use getDrawable()
        sf::VertexArray getVertices() const { return vertices; }
        sf::VertexArray getDrawable() const;
        void setColor (const sf::Color& color) { currColor = color; }

    protected:

    private:
};

#endif // RAYPATH_H
