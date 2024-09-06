#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"

class Mouse_controller
{
private:
    Player& user;
    sf::RenderWindow& window;

public:
    Mouse_controller(Player& player, sf::RenderWindow& wnd);

    // Getter
    sf::RenderWindow& get_window();
    Player& get_player();

    // Methods
    sf::Vector2f get_mouse_position() const;

    bool is_mouse_button_pressed(sf::Mouse::Button button) const;
 
};

class Keyboard_controller
{
private:
	Player& user;
	sf::Keyboard keyboard;

public:
	Keyboard_controller(Player& player);
	// Getter
	sf::Keyboard& get_keyboard();
	Player& get_player();
};
