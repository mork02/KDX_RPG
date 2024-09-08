#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "controller.h"

class Main_menu
{
private:
	sf::RenderWindow& window;
	Mouse_controller& mouse_ctrl;
	sf::Texture texture;
	sf::Sprite sprite;

	std::string path = "assets/menu_assets/menu.png";

	float xPos = 0;
	float yPos = 0;
	int scale = 6;

protected:
	void center_menu();

public:
	Main_menu(sf::RenderWindow& window, Mouse_controller& mouse_ctrl);

};
