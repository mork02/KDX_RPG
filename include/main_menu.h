#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"
#include "controller.h"

class Main_menu
{
private:
	sf::RenderWindow& window;
	Mouse_controller& mouse_ctrl;

	void update_assets();

	Asset_loader background_asset;

	Text title_text;
	Text new_game_text;
	Text options_text;
	Text quit_text;

	Asset_loader new_game_asset;
	Asset_loader options_asset;
	Asset_loader quit_asset;

	float x_Pos = 0;
	float y_Pos = 0;

protected:
	void center_menu(Asset_loader& asset, int x = 0, int y = 0);
	void center_text_in_asset(Asset_loader& asset, Text& text);
	void scale_background(Asset_loader& asset);
	void update_text_hover();

public:
	Main_menu(sf::RenderWindow& window, Mouse_controller& mouse_ctrl);
	void draw();
	sf::FloatRect get_text_bounds(Text text);
	void animate_title();

};
