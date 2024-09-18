#include "text.h"

Text::Text(std::string showing_text_c, int size_c, float xPos_c, float yPos_c, std::string font_path_c, sf::Color color_c)
    : showing_text(showing_text_c), size(size_c), xPos(xPos_c), yPos(yPos_c), font_path(font_path_c), color(color_c)
{
    font.loadFromFile(font_path_c);
    text.setString(showing_text_c);
    text.setFont(font);
    text.setCharacterSize(size_c);
    text.setPosition(sf::Vector2f(xPos_c, yPos_c));
    text.setFillColor(color_c);
}

// Getter

auto Text::get_text() -> sf::Text&
{
    return text;
}

// Setter

auto Text::set_text(std::string new_text) -> void
{
    text.setString(new_text);
}

auto Text::set_position(int value_x, int value_y) -> void
{
    text.setPosition(static_cast<float>(value_x), static_cast<float>(value_y));
}

// Methods

auto Text::draw_text(sf::RenderWindow& window) -> void
{
    window.draw(text);
}
