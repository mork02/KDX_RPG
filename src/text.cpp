#include "text.h"

Text::Text(std::string showing_text_c, int size_c, float xPos_c, float yPos_c, std::string font_path_c, sf::Color color_c)
    : showing_text(showing_text_c), size(size_c), xPos(xPos_c), yPos(yPos_c), font_path(font_path_c), color(color_c), text(), font()
{
    font.loadFromFile(font_path_c);
    text.setString(showing_text_c);
    text.setFont(font);
    text.setCharacterSize(size_c);
    text.setPosition(sf::Vector2f(xPos_c, yPos_c));
    text.setFillColor(color_c);
}

// Getter

sf::Text& Text::get_text() { return text; }

// Setter

void Text::set_text(std::string new_text)
{
    text.setString(new_text);
}

void Text::set_position(int value_x, int value_y)
{
    text.setPosition(value_x, value_y);
}

// Methods

void Text::draw_text(sf::RenderWindow& window)
{
    window.draw(text);
}
