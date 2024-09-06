#include "controller.h"

// Mouse //
Mouse_controller::Mouse_controller(Player& player_c, sf::RenderWindow& window_c) : user(player_c), window(window_c) {}

// Getter


sf::RenderWindow& Mouse_controller::get_window() { return window; }

Player& Mouse_controller::get_player() { return user; }

sf::Vector2f Mouse_controller::get_mouse_position() const
{
	return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

bool Mouse_controller::is_mouse_button_pressed(sf::Mouse::Button button) const 
{
    return sf::Mouse::isButtonPressed(button);
}

// Keyboard // 

Keyboard_controller::Keyboard_controller(Player& player_c) : user(player_c) {}

// Getter

sf::Keyboard& Keyboard_controller::get_keyboard() { return keyboard; }

Player& Keyboard_controller::get_player() { return user; }
