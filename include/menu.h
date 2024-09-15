#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "text.h"
#include "input.h"

class Panel;

class Menu
{
private:
	sf::RenderWindow& window;
	Input& input;
	Panel& panel;

	sf::Texture texture;
	sf::Sprite sprite;
	Text menu_title_text;
	Text menu_continue_text;
	Text menu_option_text;
	Text menu_quit_text;

	std::string path = "assets/menu_assets/menu/menu.png";

	float xPos = 0;
	float yPos = 0;
	int scale = 6;
	bool visable;

private:
	std::vector<std::reference_wrapper<Text>> get_menu_texts();
	void process_hover(const sf::Vector2f& mousePosF);
	void process_click(const sf::Vector2f& mousePosF);

protected:
	void center_menu(); 
	void update_text_hover();

public:
	Menu(sf::RenderWindow& window, Panel& panel, Input& input);
	bool get_visable() const;
	sf::FloatRect get_text_bounds(Text text);

	void set_visable(bool value);
	void draw();

	void check_text_click();
};