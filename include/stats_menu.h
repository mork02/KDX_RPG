#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "menu.h"
#include "asset_loader.h"

class CPanel;

class CStats_menu : public CMenu
{
private:
    const std::string mBackground_Path = "assets/menu_assets/stats_menu/stats_menu.png";
    float mBackground_Scale = 6;
    CAsset_loader mBackground_Asset;

public:
    CStats_menu(sf::RenderWindow& Window);

    auto draw() -> void override;
    auto handle_click_event(CPanel& panel) -> void override;
};