#pragma once
#include "SFML/Graphics.hpp"

class CInput
{
private:
    sf::RenderWindow& mWindow;
    sf::Mouse mMouse;
    sf::Keyboard mKeyboard;

    bool mIs_Key_Pressed = false;
    bool mIs_Mouse_Pressed = false;

public:
    CInput(sf::RenderWindow& Window);

    // Getter
    auto get_mouse() const->sf::Mouse;
    auto get_mouse_position() const->sf::Vector2f;

    auto get_keyboard() const->sf::Keyboard;

    auto get_isKeyPressed() const -> bool;
    auto get_isMousePressed() const -> bool;

    // Setter
    auto set_isKeyPressed(bool value) -> void;
    auto set_isMousePressed(bool value) -> void;

};
