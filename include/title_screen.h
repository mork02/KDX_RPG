#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"

class CPanel;
class CInput;

class CTitle_Screen
{
private:
    sf::RenderWindow& window;
    CInput& input;

    std::string background_path = "assets/menu_assets/main_menu/background_new.png";

    CAsset_loader background_asset;

    Text title_text;
    Text new_game_text;
    Text options_text;
    Text quit_text;

    // title animation
    float fade_alpha = 0.0f;
    float fade_increment = 2.0f;
    bool increasing = true;

private:
    auto scale_background(CAsset_loader& asset) -> void;
    auto position_texts() -> void;

    auto animate_title_text() -> void;

    auto get_asset_components() -> std::vector<std::reference_wrapper<CAsset_loader>>;
    auto get_text_components() -> std::vector<std::reference_wrapper<Text>>;

public:
    CTitle_Screen(sf::RenderWindow& window, CInput& input);

    auto handle_click_event(CPanel& panel) -> void;
    auto draw(CPanel& panel) -> void;

};
