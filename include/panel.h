#pragma once
#include "SFML/Graphics.hpp"
#include "rect.h"
#include "text.h"
#include "player.h"

class Panel
{
private:
	sf::RenderWindow& window;

	Rect rect; 
	Player user;

	Text user_Health;

public:
	Panel(sf::RenderWindow& window);

	// Getter

	// Setter

	// Methods
	void update();
	void update_user_health();
};

