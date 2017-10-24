#ifndef PROJECT_LIGHTRAYS_H
#define PROJECT_LIGHTRAYS_H

#include "Project.h"

class Project_lightrays : Project
{
    public:
        Project_lightrays(sf::RenderWindow& _window);
        virtual ~Project_lightrays();
        void loop();

    protected:

    private:
        sf::RenderWindow& window;
        class TwoPointObject* obj;
        class TwoPointObject* obj2;
        int a;
        CollisionHandler col;
        class Lightray* ray;
};

#endif // PROJECT_LIGHTRAYS_H
