#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"

class Mouse_controller
{
private:
	Player& user;
	sf::Mouse mouse;

public:
	Mouse_controller(Player& player);
	// Getter
	sf::Mouse& get_mouse(); 
	Player& get_player();

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
