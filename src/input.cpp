#include "input.h"

Input::Input(sf::RenderWindow& window_c, Player& user_c)
    : window(window_c), user(user_c)
{}

// Getter

auto Input::get_mouse() const -> sf::Mouse
{
    return mouse;
}

auto Input::get_mouse_position() const -> sf::Vector2f
{
    return window.mapPixelToCoords(mouse.getPosition(window));
}

auto Input::get_keyboard() const -> sf::Keyboard
{
    return keyboard;
}

auto Input::get_isKeyPressed() const -> bool
{
    return isKeyPressed;
}

auto Input::get_isMousePressed() const -> bool
{
    return isMousePressed;
}

// Setter

auto Input::set_isKeyPressed(bool value) -> void
{
    isKeyPressed = value;
}

auto Input::set_isMousePressed(bool value) -> void
{
    isMousePressed = value;
}

// Methods

auto Input::is_mouse_button_pressed(sf::Mouse::Button button) const -> bool
{
    return mouse.isButtonPressed(button);
}
