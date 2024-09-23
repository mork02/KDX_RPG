#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Text
{
private:
    std::string showing_text;
    int size;
    float x;
    float y;
    std::string font_path;
    sf::Color color;
    sf::Text text;
    sf::Font font;

    bool hoverable;

private:
    auto update_hover_state(sf::RenderWindow& window) -> void;

public:
    Text(std::string showing_text_c, int size_c, 
        bool hoverable_c = false,
        float pos_x_c = 0.f, float pos_y_c = 0.f,
        std::string font_path_c = "assets/font/Minecraft.ttf",
        sf::Color color_c = sf::Color::White);

    // Getter
    auto get_text() -> sf::Text&;
    auto get_text_Bounds() -> sf::FloatRect;

    // Setter
    auto set_text(std::string new_text) -> void;
    auto set_position(int value_x, int value_y) -> void;

    // Methods
    auto draw_text(sf::RenderWindow& window) -> void;
};
