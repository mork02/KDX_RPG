#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"
#include "player.h"
#include "menu.h"

class Panel
{
private:
	sf::RenderWindow& window;

	Player user;

	Text user_Health;
	Asset_loader iron_sword_frame;
	Menu menu;

public:
	Panel(sf::RenderWindow& window);

	// Getter
	Player& get_player();
	Menu& get_menu();

	// Setter

	// Methods
	void update();
	void update_user_health();
};

