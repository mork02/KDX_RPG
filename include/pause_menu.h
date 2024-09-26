#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "menu.h"
#include "asset_loader.h"
#include "text.h"

class CPanel;

class CPause_menu : public CMenu
{
private:
    const std::string background_path = "assets/menu_assets/pause_menu/pause.png";
    float background_scale = 6;
    Asset_loader background_asset;
    Text title_text;
    Text continue_text;
    Text options_text;
    Text back_to_title_text;

    auto get_text_components() -> std::vector<std::reference_wrapper<Text>>;
    auto set_text_position() -> void;

public:
    CPause_menu(sf::RenderWindow& window_c);

    auto draw() -> void override;
    auto handle_click_event(CPanel& panel) -> void override;
};


