#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "text.h"
#include "input.h"
#include "asset_loader.h"

class Panel;

class Menu
{
private:
    sf::RenderWindow& window;
    Input& input;
    Panel& panel;

    Text menu_title_text;
    Text menu_continue_text;
    Text menu_option_text;
    Text menu_quit_text;

    std::string path = "assets/menu_assets/menu/menu.png";
    Asset_loader menu_asset;

    float xPos = 0;
    float yPos = 0;
    const int scale = 6;
    const int vertical_padding = 75;
    const sf::Color hover_color = sf::Color(210, 170, 109);
    const sf::Color default_color = sf::Color::White;
    bool visable;

private:
    auto get_menu_texts() -> std::vector<std::reference_wrapper<Text>>;
    auto process_hover(const sf::Vector2f& mousePosF) -> void;
    auto process_click(const sf::Vector2f& mousePosF) -> void;
    auto center_menu() -> void;
    auto position_menu_items() -> void;
    auto update_text_hover() -> void;

public:
    Menu(sf::RenderWindow& window, Panel& panel, Input& input);
    auto get_visable() const -> bool;
    auto get_text_bounds(Text& text) -> sf::FloatRect;  // Pass by reference

    auto set_visable(bool value) -> void;
    auto draw() -> void;
    auto check_text_click() -> void;
};
