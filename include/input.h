#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"

class Input
{
private:
    sf::RenderWindow& window;
    sf::Mouse mouse;
    sf::Keyboard keyboard;
    Player& user;

    bool isKeyPressed = false;
    bool isMousePressed = false;

public:
    Input(sf::RenderWindow& window, Player& user);

    // Getter
    auto get_mouse() const->sf::Mouse;
    auto get_mouse_position() const->sf::Vector2f;
    auto get_keyboard() const->sf::Keyboard;
    auto get_isKeyPressed() const -> bool;
    auto get_isMousePressed() const -> bool;

    // Setter
    auto set_isKeyPressed(bool value) -> void;
    auto set_isMousePressed(bool value) -> void;

    // Methods
    auto is_mouse_button_pressed(sf::Mouse::Button button) const -> bool;
};
