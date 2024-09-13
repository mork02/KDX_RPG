#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"
#include "input.h"

class Panel;

class Main_menu
{
private:
	sf::RenderWindow& window;
	Input& input;
	Panel& panel;

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

private:
	void center_menu(Asset_loader& asset, int x = 0, int y = 0);
	void center_text_in_asset(Asset_loader& asset, Text& text);
	void scale_background(Asset_loader& asset);
	void process_hover(const sf::Vector2f& mousePosF);
	std::vector<std::pair<std::reference_wrapper<Asset_loader>, std::reference_wrapper<Text>>> get_text_components();
	void process_click(const sf::Vector2f& mousePosF);

public:
	Main_menu(sf::RenderWindow& window, Panel& panel, Input& input);
	void draw();
	sf::FloatRect get_text_bounds(Text text);
	void animate_title();
	void update_text_hover();
	void check_text_click();

};
