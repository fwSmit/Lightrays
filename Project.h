#ifndef PROJECT_H
#define PROJECT_H

#include <Lightray.h>

class Project
{
    public:
        Project(sf::RenderWindow& _window);
        virtual ~Project();

    protected:

    private:
        sf::RenderWindow& window;
};

#endif // PROJECT_H
