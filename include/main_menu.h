#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"
#include "input.h"

class Panel;

class Main_menu
{
private:
    sf::RenderWindow& window;
    Input& input;
    Panel& panel;

    std::string background_path = "assets/menu_assets/main_menu/background_new.png";
    std::string sign1_path = "assets/menu_assets/main_menu/main_menu_sign_1.png";
    std::string sign2_path = "assets/menu_assets/main_menu/main_menu_sign_2.png";
    std::string sign3_path = "assets/menu_assets/main_menu/main_menu_sign_3.png";

    Asset_loader background_asset;

    Text title_text;
    Text new_game_text;
    Text options_text;
    Text quit_text;

    Asset_loader new_game_asset;
    Asset_loader options_asset;
    Asset_loader quit_asset;

    float x_Pos = 0;
    float y_Pos = 0;

private:
    auto update_assets() -> void;
    auto center_menu(Asset_loader& asset, int x = 0, int y = 0) -> void;
    auto center_text_in_asset(Asset_loader& asset, Text& text) -> void;
    auto scale_background(Asset_loader& asset) -> void;
    auto process_hover(const sf::Vector2f& mousePosF) -> void;
    auto get_text_components() -> std::vector<std::pair<std::reference_wrapper<Asset_loader>, std::reference_wrapper<Text>>>;
    auto process_click(const sf::Vector2f& mousePosF) -> void;

public:
    Main_menu(sf::RenderWindow& window, Panel& panel, Input& input);

    auto draw() -> void;
    auto get_text_bounds(Text text) -> sf::FloatRect;
    auto animate_title() -> void;
    auto update_text_hover() -> void;
    auto check_text_click() -> void;
};
