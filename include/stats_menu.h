#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "text.h"
#include "input.h"
#include "asset_loader.h"

class Panel;

class Stats_menu
{
private:
	sf::RenderWindow& window;
	Input& input;
	Panel& panel;

	std::string menu_path = "assets/menu_assets/stats_menu/stats_menu.png";
	std::string warrior_UL_path = "assets/character_assets/warrior/warrior_UL.png";
	std::string warrior_UR_path = "assets/character_assets/warrior/warrior_UR.png";
	std::string warrior_OL_path = "assets/character_assets/warrior/warrior_OL.png";
	std::string warrior_OR_path = "assets/character_assets/warrior/warrior_OR.png";

	Asset_loader stats_asset;

	float char_xPos = 0;
	float char_yPos = 0;


	int scale = 6;
	bool visable;

private:
	void process_hover(const sf::Vector2f& mousePosF);
	void process_click(const sf::Vector2f& mousePosF);

protected:
	void center_menu();
	void update_text_hover();

public:
	Stats_menu(sf::RenderWindow& window, Panel& panel, Input& input);
	bool get_visable() const;
	sf::FloatRect get_text_bounds(Text text);

	void set_visable(bool value);
	void draw();

	void check_text_click();
};