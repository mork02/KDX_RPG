#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum class ECharacter_Size
{
    VERY_SMALL = 25,
    SMALL = 50,
    MEDIUM = 100,
    LARGE = 150,
    VERY_LARGE = 200
};

class CText
{
private:
    sf::RenderWindow& mWindow;
    sf::Color mColor = sf::Color::White;
    sf::Font mFont;
    sf::Text mText;

    float mStandard_Size;
    bool mHoverable;

private:
    auto update_hover_state() -> void;
    auto init_Standard_Size() -> void;

public:
    CText(
        sf::RenderWindow& Window,
        std::string Showing_Text, ECharacter_Size Character_Size = ECharacter_Size::MEDIUM,
        bool Hoverable = false);

    auto get_Global_text_Bounds() -> const sf::FloatRect&;
    auto get_color() -> const sf::Color&;

    auto configure(float x, float y, ECharacter_Size Character_Size = ECharacter_Size::MEDIUM) -> void;
    auto set_size(ECharacter_Size Character_Size) -> void;
    auto set_color(sf::Color Color) -> void;
    auto set_font(std::string Font_Path) -> void;
    auto set_text(std::string new_text) -> void;
    auto set_position(float value_x, float value_y) -> void;

    auto render() -> void;
};
