#include "input.h"

CInput::CInput() {}

// Getter

auto CInput::get_mouse() const -> sf::Mouse
{
    return mMouse;
}

auto CInput::get_mouse_position(sf::RenderWindow& Window) const -> sf::Vector2f
{
    return Window.mapPixelToCoords(mMouse.getPosition(Window));
}

auto CInput::get_keyboard() const -> sf::Keyboard
{
    return mKeyboard;
}

auto CInput::get_isKeyPressed() const -> bool
{
    return mIs_Key_Pressed;
}

auto CInput::get_isMousePressed() const -> bool
{
    return mIs_Mouse_Pressed;
}

auto CInput::get_Movement_Speed() const -> float
{
    return mMovement_Speed;
}

// Setter

auto CInput::set_isKeyPressed(bool value) -> void
{
    mIs_Key_Pressed = value;
}

auto CInput::set_isMousePressed(bool value) -> void
{
    mIs_Mouse_Pressed = value;
}
