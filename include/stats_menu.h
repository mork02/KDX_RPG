#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "menu.h"

class CPanel;

class CStats_menu : public CMenu
{
private:
    const std::string mPath = "./assets/menus/stats/stats_menu.png";

public:
    CStats_menu(sf::RenderWindow& Window);

    auto draw() -> void override;
    auto handle_events(CGameplay& Gameplay, CGameManager* GameManager) -> void override;
};