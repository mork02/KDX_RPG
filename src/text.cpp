#include "text.h"
#include "scene_enum.h"
#include <iostream>

CText::CText(
    sf::RenderWindow& Window,
    std::string Showing_Text, ECharacter_Size Character_Size,
    bool Hoverable) : 
    mWindow(Window),
    mHoverable(Hoverable)
{
    if (!mFont.loadFromFile("assets/font/Minecraft.ttf"))
    {
        std::cout << mFont.getInfo().family << std::endl;
    }

    init_Standard_Size();

    mText.setString(Showing_Text);
    mText.setFont(mFont);
    mText.setPosition(sf::Vector2f(0, 0));
    mText.setFillColor(sf::Color::White);

    set_size(Character_Size);
}

auto CText::get_Global_text_Bounds() -> const sf::FloatRect&
{
    return mText.getGlobalBounds();
}

auto CText::get_color() -> const sf::Color&
{
    return mText.getFillColor();
}

auto CText::configure(float x, float y, ECharacter_Size Character_Size) -> void
{
    mText.setPosition(sf::Vector2f(x, y));
    set_size(Character_Size);
}

auto CText::set_size(ECharacter_Size Character_Size) -> void
{
    mText.setCharacterSize(mStandard_Size * static_cast<int>(Character_Size));
}

auto CText::set_color(sf::Color Color) -> void
{
    mText.setFillColor(Color);
}

auto CText::set_font(std::string Font_Path) -> void
{
    if (!mFont.loadFromFile(Font_Path))
    {
        std::cout << mFont.getInfo().family << std::endl;
    }
    mText.setFont(mFont);
}

auto CText::set_text(std::string new_text) -> void
{
    mText.setString(new_text);
}

auto CText::set_position(float value_x, float value_y) -> void
{
    mText.setPosition(value_x, value_y);
}

auto CText::update() -> void
{
    update_hover_state();
    mWindow.draw(mText);
}

auto CText::update_hover_state() -> void
{
    if (!mHoverable) return;

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(mWindow);
    sf::FloatRect text_bounds = get_Global_text_Bounds();

    if (text_bounds.contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        mText.setFillColor(sf::Color::Yellow);
    }
    else
    {
        mText.setFillColor(mColor);
    }
}

auto CText::init_Standard_Size() -> void
{
    sf::Vector2u baseResolution(1920, 1080);
    sf::Vector2u windowSize = mWindow.getSize();

    float scaleX = static_cast<float>(windowSize.x) / baseResolution.x;
    float scaleY = static_cast<float>(windowSize.y) / baseResolution.y;

    mStandard_Size = std::min(scaleX, scaleY);
}
