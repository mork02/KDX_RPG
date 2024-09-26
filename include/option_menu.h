#pragma once
#include "SFML/Graphics.hpp"
#include "asset_loader.h"
#include "text.h"
#include "menu.h"

class CPanel;

class COption_menu : public CMenu
{
private:
	const std::string background_path = "assets/menu_assets/pause_menu/pause.png";
	float background_scale = 6;
	Asset_loader background_asset;
	Text title_text;
	Text back_text;

	auto get_text_components() -> std::vector<std::reference_wrapper<Text>>;
	auto set_text_position() -> void;

public:
	COption_menu(sf::RenderWindow& window);

	auto draw() -> void override;
	auto handle_click_event(CPanel& panel) -> void override;
};

