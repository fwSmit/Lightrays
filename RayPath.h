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
        sf::VertexArray getDrawable() const;
        void setColor (const sf::Color& color) { currColor = color; }

    protected:

    private:
};

#endif // RAYPATH_H
