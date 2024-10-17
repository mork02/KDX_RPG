#include "text.h"
#include "scene_enum.h"

CText::CText(std::string Showing_Text, int Size,
    bool Hoverable,
    float X, float Y,
    std::string Font_Path,
    sf::Color Color)
    : mShowing_Text(Showing_Text), mSize(Size), mHoverable(Hoverable), mX(X), mY(Y), mFont_Path(Font_Path), mColor(Color)
{
    mFont.loadFromFile(Font_Path);
    mText.setString(Showing_Text);
    mText.setFont(mFont);
    mText.setCharacterSize(Size);
    mText.setPosition(sf::Vector2f(X, Y));
    mText.setFillColor(Color);
}

auto CText::get_text() -> sf::Text&
{
    return mText;
}

auto CText::get_Global_text_Bounds() -> sf::FloatRect
{
    return mText.getGlobalBounds();
}

auto CText::get_Local_text_Bounds() -> sf::FloatRect
{
    return mText.getLocalBounds();
}

auto CText::set_text(std::string new_text) -> void
{
    mText.setString(new_text);
}

auto CText::set_position(float value_x, float value_y) -> void
{
    mText.setPosition(value_x, value_y);
}

auto CText::draw_text(sf::RenderWindow& window) -> void
{
    update_hover_state(window);
    window.draw(mText);
}

auto CText::update_hover_state(sf::RenderWindow& window) -> void
{
    if (!mHoverable) return;

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect text_bounds = get_Global_text_Bounds();

    if (text_bounds.contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        mText.setFillColor(sf::Color::Yellow);
    }
    else
    {
        mText.setFillColor(sf::Color::White);
    }
}
