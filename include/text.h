#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class CText
{
private:
    std::string mShowing_Text;
    int mSize;
    float mX;
    float mY;
    std::string mFont_Path;
    sf::Color mColor;
    sf::Text mText;
    sf::Font mFont;

    bool mHoverable;

private:
    auto update_hover_state(sf::RenderWindow& window) -> void;

public:
    CText(std::string Showing_Text, int Size, 
        bool Hoverable = false,
        float X = 0.f, float Y = 0.f,
        std::string Font_Path = "assets/font/Minecraft.ttf",
        sf::Color Color = sf::Color::White);

    auto get_text() -> sf::Text&;
    auto get_Global_text_Bounds() -> sf::FloatRect;
    auto get_Local_text_Bounds() -> sf::FloatRect;

    auto set_text(std::string new_text) -> void;
    auto set_position(float value_x, float value_y) -> void;

    auto draw_text(sf::RenderWindow& window) -> void;
};
