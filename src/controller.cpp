#include "controller.h"

// Mouse //
Mouse_controller::Mouse_controller(Player& player_c) : user(player_c) {}

// Getter

sf::Mouse& Mouse_controller::get_mouse() { return mouse; }

Player& Mouse_controller::get_player() { return user; }

// Keyboard // 

Keyboard_controller::Keyboard_controller(Player& player_c) : user(player_c) {}

// Getter

sf::Keyboard& Keyboard_controller::get_keyboard() { return keyboard; }

Player& Keyboard_controller::get_player() { return user; }
