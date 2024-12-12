#include "text.h"
#include <iostream>

CText::CText(
    sf::RenderWindow& Window,
    std::string Showing_Text, ECharacter_Size Character_Size,
    bool Hoverable) : 
    mHoverable(Hoverable)
{
    if (!mFont.loadFromFile("assets/font/Minecraft.ttf"))
    {
        std::cout << mFont.getInfo().family << std::endl;
    }

    init_Standard_Size(Window);

    mText.setString(Showing_Text);
    mText.setFont(mFont);
    mText.setPosition(sf::Vector2f(0, 0));
    mText.setFillColor(sf::Color::White);

    set_size(Character_Size);
}

auto CText::get_Global_text_Bounds() -> const sf::FloatRect
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
    mText.setCharacterSize(static_cast<unsigned>(mStandard_Size) * static_cast<unsigned>(Character_Size));
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

auto CText::render(sf::RenderWindow& Window) -> void
{
    update_hover_state(Window);
    Window.draw(mText);
}

auto CText::update_hover_state(sf::RenderWindow& Window) -> void
{
    if (!mHoverable) return;

    sf::Vector2f mouse_pos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
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

auto CText::init_Standard_Size(sf::RenderWindow& Window) -> void
{
    sf::Vector2u baseResolution(Window.getSize().x, Window.getSize().y);
    sf::Vector2u windowSize = Window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / baseResolution.x;
    float scaleY = static_cast<float>(windowSize.y) / baseResolution.y;

    mStandard_Size = std::min(scaleX, scaleY);
}
