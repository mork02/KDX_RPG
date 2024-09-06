#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"
#include "player.h"
#include "menu.h"
#include "controller.h"

class Panel
{
private:
	sf::RenderWindow& window;
	Mouse_controller& mouse_ctrl;
	Keyboard_controller& keyboard_ctrl;

	Player user;

	Text user_Health;
	Asset_loader iron_sword_frame;
	Menu menu;

public:
	Panel(sf::RenderWindow& window, Mouse_controller& mouse_ctrl, Keyboard_controller& keyboard_ctrl);

	// Getter
	Player& get_player();
	Menu& get_menu();
	Mouse_controller& get_mouse_ctrl() const;
	Keyboard_controller& get_keyboard_ctrl() const;
	// Setter

	// Methods
	void update();
	void update_user_health();
};

