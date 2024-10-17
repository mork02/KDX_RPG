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
    const std::string mBackground_Path = "assets/menu_assets/pause_menu/pause.png";
    float mBackground_Scale = 6;
    CAsset_loader mBackground_Asset;
    CText mTitle_Text;
    CText mContinue_Text;
    CText mOptions_Text;
    CText mBack_To_Title_Text;

    auto get_text_components() -> std::vector<std::reference_wrapper<CText>>;
    auto set_text_position() -> void;

public:
    CPause_menu(sf::RenderWindow& Window);

    auto draw() -> void override;
    auto handle_click_event(CPanel& panel) -> void override;
};


