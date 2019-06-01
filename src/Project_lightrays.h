#ifndef PROJECT_LIGHTRAYS_H
#define PROJECT_LIGHTRAYS_H

#include "Project.h"
#include "CollisionHandler.h"
#include "TGUI/TGUI.hpp"
#include <iostream>
#include "Mirror.h"

class CollisionHandler;

class Project_lightrays : Project
{
    public:
        Project_lightrays(sf::RenderWindow& _window, tgui::Gui& _gui);
        virtual ~Project_lightrays();
        void loop();
		void mirrorAdd(){
			std::cout << "add a mirror" << std::endl;
			isPlacingMirror = true;
		}
		void handleEvent(sf::Event event);
		void stop();
		void start();
    protected:

    private:
		bool isPlacingMirror = false;
		int mirror_side_number = 0;
		sf::Vector2i firstPointPos;
		Mirror* tempMirr = nullptr;

        class TwoPointObject* obj;
        class TwoPointObject* obj2;
        int a;
        CollisionHandler col;
        class Lightray* ray;
		tgui::Gui& gui;
		tgui::Theme blackTheme;
		tgui::Widget::Ptr button;
};

#endif // PROJECT_LIGHTRAYS_H
