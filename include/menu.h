#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "text.h"
#include "controller.h"

class Menu
{
private:
	sf::RenderWindow& window;
	Mouse_controller& mouse_ctrl;
	sf::Texture texture;
	sf::Sprite sprite;
	Text menu_title_text;
	Text menu_continue_text;
	Text menu_option_text;
	Text menu_quit_text;

	std::string path = "assets/menu_assets/menu.png";

	float xPos = 0;
	float yPos = 0;
	int scale = 6;
	bool visable = false;

public:
	Menu(sf::RenderWindow& window, Mouse_controller& mouse_ctrl);
	bool get_visable() const;
	sf::FloatRect get_text_bounds(Text text);

	void set_visable(bool value);
	void draw_menu();
	void center_menu(); 
	void update_text_hover();
};