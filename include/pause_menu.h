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
    auto set_text_position() -> void;

public:
    CPause_menu(sf::RenderWindow& Window);

    auto draw() -> void override;
    auto handle_events(CGameplay& Gameplay, CGameManager* GameManager) -> void override;
};


