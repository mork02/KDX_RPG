#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "menu.h"
#include "asset_loader.h"

class CPanel;

class CStats_menu : public CMenu
{
private:
    const std::string background_path = "assets/menu_assets/stats_menu/stats_menu.png";
    float background_scale = 6;
    Asset_loader background_asset;

    auto center_asset(Asset_loader& asset) -> void;

public:
    CStats_menu(sf::RenderWindow& window_c);

    auto draw() -> void override;
    auto handle_click_event(CPanel& panel) -> void override;
};