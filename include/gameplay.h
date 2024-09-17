#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
#include "text.h"
#include "asset_loader.h"
#include "tile_map.h"

class Gameplay
{
private:
	sf::RenderWindow& window;
	Player user;
	TileMap map;

	Asset_loader sword;
public:
	Gameplay(sf::RenderWindow& window);

	Player& get_player();

	void update();
};
