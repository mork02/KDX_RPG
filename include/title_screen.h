#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"

class CPanel;
class CInput;

class CTitle_Screen
{
private:
    sf::RenderWindow& mWindow;
    CInput& mInput;

    std::string mBackground_Path = "assets/menu_assets/main_menu/background_new.png";

    CAsset_loader mBackground_Asset;

    CText mTitle_Text;
    CText mNew_Game_Text;
    CText mOptions_Text;
    CText mQuit_Text;

    // title animation
    float mFade_Alpha = 0.0f;
    float mFade_Increment = 2.0f;
    bool mIncreasing = true;

private:
    auto scale_background(CAsset_loader& asset) -> void;
    auto position_texts() -> void;

    auto animate_title_text() -> void;

    auto get_asset_components() -> std::vector<std::reference_wrapper<CAsset_loader>>;
    auto get_text_components() -> std::vector<std::reference_wrapper<CText>>;

public:
    CTitle_Screen(sf::RenderWindow& Window, CInput& Input);

    auto handle_click_event(CPanel& panel) -> void;
    auto draw(CPanel& panel) -> void;

};
