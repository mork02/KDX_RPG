#include "text.h"
#include "scene_enum.h"

Text::Text(std::string showing_text_c, int size_c, bool hoverable_c, float x_c, float y_c, std::string font_path_c, sf::Color color_c)
    : showing_text(showing_text_c), size(size_c), hoverable(hoverable_c), x(x_c), y(y_c), font_path(font_path_c), color(color_c)
{
    font.loadFromFile(font_path_c);
    text.setString(showing_text_c);
    text.setFont(font);
    text.setCharacterSize(size_c);
    text.setPosition(sf::Vector2f(x_c, y_c));
    text.setFillColor(color_c);
}

// Getter
auto Text::get_text() -> sf::Text&
{
    return text;
}

auto Text::get_Global_text_Bounds() -> sf::FloatRect
{
    return text.getGlobalBounds();
}

auto Text::get_Local_text_Bounds() -> sf::FloatRect
{
    return text.getLocalBounds();
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
    update_hover_state(window);
    window.draw(text);
}

// Method to check hover state and update color
auto Text::update_hover_state(sf::RenderWindow& window) -> void
{
    if (!hoverable) return;

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect text_bounds = get_Global_text_Bounds();

    if (text_bounds.contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        text.setFillColor(sf::Color::Yellow);
    }
    else
    {
        text.setFillColor(sf::Color::White);
    }
}
