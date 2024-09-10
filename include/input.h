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
	sf::Mouse get_mouse() const;
	sf::Vector2f get_mouse_position() const;
	sf::Keyboard get_keyboard() const;
	bool get_isKeyPressed() const;
	bool get_isMousePressed() const;

	// Setter
	void set_isKeyPressed(bool value);
	void set_isMousePressed(bool value);

	// Methods
	bool is_mouse_button_pressed(sf::Mouse::Button button) const;
};
