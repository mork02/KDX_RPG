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
	Text title_text;

	std::string path = "assets/menu_assets/main_menu.png";


	float xPos = 0;
	float yPos = 0;
	int scale = 6;

protected:
protected:
	void center_menu();
	void update_text_hover();

public:
	Main_menu(sf::RenderWindow& window, Mouse_controller& mouse_ctrl);
	sf::FloatRect get_text_bounds(Text text);
	void draw();
	void animate_title();

};
