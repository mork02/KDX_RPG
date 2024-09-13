#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"

class Gameplay
{
private:
	sf::RenderWindow& window;
	Asset_loader sword;
public:
	Gameplay(sf::RenderWindow& window);

	void update();
};
