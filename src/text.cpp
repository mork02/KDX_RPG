#include "text.h"

Text::Text(std::string showing_text_c, int size_c, float pos_x_c, float pos_y_c, std::string font_path_c, sf::Color color_c)
    : showing_text(showing_text_c), size(size_c), pos_x(pos_x_c), pos_y(pos_y_c), font_path(font_path_c), color(color_c), text(), font()
{
    font.loadFromFile(font_path_c);
    text.setString(showing_text_c);
    text.setFont(font);
    text.setCharacterSize(size_c);
    text.setPosition(sf::Vector2f(pos_x_c, pos_y_c));
    text.setFillColor(color_c);
}

// Getter

sf::Text& Text::get_text() { return text; }

// Setter

void Text::set_text(std::string new_text)
{
    text.setString(new_text);
}

// Methods

void Text::draw_text(sf::RenderWindow& window)
{
    window.draw(text);
}
