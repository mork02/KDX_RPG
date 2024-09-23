#include "input.h"

CInput::CInput(sf::RenderWindow& window_c)
    : window(window_c)
{}

// Getter

auto CInput::get_mouse() const -> sf::Mouse
{
    return mouse;
}

auto CInput::get_mouse_position() const -> sf::Vector2f
{
    return window.mapPixelToCoords(mouse.getPosition(window));
}

auto CInput::get_keyboard() const -> sf::Keyboard
{
    return keyboard;
}

auto CInput::get_isKeyPressed() const -> bool
{
    return isKeyPressed;
}

auto CInput::get_isMousePressed() const -> bool
{
    return isMousePressed;
}

// Setter

auto CInput::set_isKeyPressed(bool value) -> void
{
    isKeyPressed = value;
}

auto CInput::set_isMousePressed(bool value) -> void
{
    isMousePressed = value;
}
