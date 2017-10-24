#ifndef PROJECT_H
#define PROJECT_H

#include <SFML/Graphics.hpp>
#include <CollisionHandler.h>

class CollisionHandler;

class Project
{
    public:
        Project(sf::RenderWindow& _window);
        virtual ~Project();
        void loop();

    protected:

    private:
		sf::RenderWindow& window;

};

#endif // PROJECT_H
