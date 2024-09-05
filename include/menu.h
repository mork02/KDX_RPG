#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "text.h"

class Menu
{
private:
	sf::RenderWindow& window;
	sf::Texture texture;
	sf::Sprite sprite;
	Text menu_text;

	std::string path = "assets/menu_assets/menu.png";

	float xPos = 0;
	float yPos = 0;
	int scale = 6;

	bool visable = false;

public:
	Menu(sf::RenderWindow& window);
	bool get_visable();

	void set_visable(bool value);
	void draw_menu();
	void center_menu(); 
};