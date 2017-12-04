#include "Project_lightrays.h"

Project_lightrays::Project_lightrays(sf::RenderWindow& _window, tgui::Gui& _gui) : Project(_window), col(window), gui(_gui)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("/home/friso/tgui-git/src/TGUI/widgets/Black.txt");
	tgui::Button::Ptr button = theme->load("button");
	button->setText("add mirror");
	button->setSize(sf::Vector2f(100, 100));
	button->connect("pressed", &Project_lightrays::mirrorAdd, this);
	button->setPosition(100, 300);
	gui.add(button, "mirrorAdd");

	obj = new Mirror(sf::Vector2f(400, 100), sf::Vector2f(300, 700), window);
	obj2 = new Mirror(sf::Vector2f(500, 100), sf::Vector2f(800, 10), window);
	//Lightray* ray = col.createRay(sf::Vector2f(200 ,500), 0.3);
	int n_rays = 0;
	std::vector<Lightray*> rays;
	for(double i = 0; i < 2 * M_PI; i+= (2 * M_PI)/n_rays) {
		//rays.push_back(col.createRay(sf::Vector2f(300, 40), i));
	}
	ray = col.createRay(sf::Vector2f(500, 700), M_PI);

	col.addPhysicsObject(obj);
	col.addPhysicsObject(obj2);
}

Project_lightrays::~Project_lightrays()
{
	//dtor
}

void Project_lightrays::loop()
{
	sf::Vector2f deltaPos = sf::Vector2f (sf::Mouse::getPosition(window)) - ray->getBegin();
	ray->setDirection(atan2(deltaPos.y, deltaPos.x));

	if(tempMirr != nullptr){
		tempMirr->setSecond(sf::Vector2f(sf::Mouse::getPosition(window))); 
	}
	////window.draw(ray.getDrawable());
	////obj->setFirst(sf::Vector2f(500 + 60*sin(i), 200 + 330*cos(i)));
	////obj->setSecond(sf::Vector2f(30 + 59*sin(i), 800 + 12*cos(i)));
	////window.draw(obj->getDrawable());
	col.draw();
}

void Project_lightrays::handleEvent(sf::Event event){
	if(isPlacingMirror){
		if(event.type == sf::Event::MouseButtonPressed){
			if(event.mouseButton.button == sf::Mouse::Left){
				if(mirror_side_number == 0){
					std::cout << "added first point of the mirror" << std::endl;
					firstPointPos = sf::Mouse::getPosition();
					tempMirr = new Mirror(sf::Vector2f(sf::Mouse::getPosition(window)), sf::Vector2f( sf::Mouse::getPosition(window)), window);
					col.addPhysicsObject(tempMirr);	
					mirror_side_number++;
				}
				else{ // second point of the mirror
					std::cout << "added second point of the mirror" << std::endl;
					tempMirr = nullptr;
					mirror_side_number = 0;
					isPlacingMirror = false;
				}
			}
		}
	}
}

void Project_lightrays::start(){
	const tgui::Widget::Ptr button = gui.get("mirrorAdd");
	button->show();
}

void Project_lightrays::stop(){
	const tgui::Widget::Ptr button = gui.get("mirrorAdd");
	button->hide();
}
