#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"

class CTitle_Screen
{
private:
    sf::RenderWindow& window;

    std::string background_path = "assets/menu_assets/main_menu/background_new.png";
    std::string sign1_path = "assets/menu_assets/main_menu/main_menu_sign_1.png";
    std::string sign2_path = "assets/menu_assets/main_menu/main_menu_sign_2.png";
    std::string sign3_path = "assets/menu_assets/main_menu/main_menu_sign_3.png";

    Asset_loader background_asset;

    Text title_text;
    Text new_game_text;
    Text options_text;
    Text quit_text;

    float fade_alpha = 0.0f;
    float fade_increment = 2.0f;
    bool increasing = true;

    /*

    Asset_loader new_game_asset;
    Asset_loader options_asset;
    Asset_loader quit_asset;
*/
private:
    auto scale_background(Asset_loader& asset) -> void;
    auto position_texts() -> void;

    auto animate_title_text() -> void;

    auto get_asset_components() -> std::vector<std::reference_wrapper<Asset_loader>>;
    auto get_text_components() -> std::vector<std::reference_wrapper<Text>>;

public:
    CTitle_Screen(sf::RenderWindow& window);

    auto draw() -> void;

};
