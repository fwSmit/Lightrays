/** bug :
    TwoPointObject* obj = new Wall(sf::Vector2f(300, 100), sf::Vector2f(300, 700), window);
    Lightray* ray = col.createRay(sf::Vector2f(400, 500), rotation);
    dont collide
*/

#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"
#include "Project_lightrays.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    settings.majorVersion = 4;
    settings.minorVersion = 5;
    sf::RenderWindow window(sf::VideoMode(900, 800), "SFML works!", sf::Style::Default, settings);
	tgui::Gui gui{window};
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);

    Project_lightrays lightrays(window, gui);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;

                default:
                break;
            }
			// has to be in this order
			gui.handleEvent(event);
			lightrays.handleEvent(event);
		}
		window.clear();
		gui.draw();
		lightrays.loop();
		window.display();
	}
    return 0;
}
