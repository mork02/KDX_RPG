#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "menu.h"
#include "text.h"

class CPause_menu : public CMenu
{
private:
    const std::string mPath = "./assets/menus/pause/pause.png";

    CText mTitle_Text;
    CText mContinue_Text;
    CText mOptions_Text;
    CText mBack_To_Title_Text;

    auto get_text_components() -> std::vector<std::reference_wrapper<CText>>;
    auto set_text_position(sf::RenderWindow& Window) -> void;

public:
    CPause_menu(sf::RenderWindow& Window);

    auto render(sf::RenderWindow& Window) -> void override;
    auto handle_events(sf::Event& Event, sf::RenderWindow& Window, CMenuManager& MenuManager, CStateManager* StateManager) -> void override;
};


