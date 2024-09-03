#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Text {
private:
    std::string showing_text;
    int size;
    float pos_x;
    float pos_y;
    std::string font_path;
    sf::Color color;
    sf::Text text;
    sf::Font font;

public:
    // Constructor declaration with default arguments
    Text(std::string showing_text_c, int size_c, float pos_x_c, float pos_y_c,
        std::string font_path_c = "../assets/font/DarkXShadowSkyrim.ttf",
        sf::Color color_c = sf::Color::White);

    // Getter
    sf::Text& get_text();

    // Setter
    void set_text(std::string new_text);

    // Methods
    void draw_text(sf::RenderWindow& window);

};
