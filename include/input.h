#pragma once
#include "SFML/Graphics.hpp"

class CInput
{
private:
    sf::Mouse mMouse;
    sf::Keyboard mKeyboard;

    float mMovement_Speed = 50.0f;

    bool mIs_Key_Pressed = false;
    bool mIs_Mouse_Pressed = false;

public:
    CInput();

    // Getter
    auto get_mouse() const->sf::Mouse;
    auto get_mouse_position(sf::RenderWindow& Window) const->sf::Vector2f;

    auto get_keyboard() const->sf::Keyboard;

    auto get_isKeyPressed() const -> bool;
    auto get_isMousePressed() const -> bool;

    auto get_Movement_Speed() const -> float;

    // Setter
    auto set_isKeyPressed(bool value) -> void;
    auto set_isMousePressed(bool value) -> void;

};
