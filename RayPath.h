#ifndef RAYPATH_H
#define RAYPATH_H

#include "Lightray.h"


class RayPath
{
    class Lightray lastRay;
    bool isLastrayValid = false;
    sf::VertexArray vertices;
    public:
        RayPath();
        virtual ~RayPath();
        void addRay(const Lightray& ray);
        sf::VertexArray getDrawable() const;

    protected:

    private:
};

#endif // RAYPATH_H
