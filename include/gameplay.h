#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
#include "text.h"
#include "asset_loader.h"
#include "tile_map_loader.h"

class Gameplay
{
private:
	sf::RenderWindow& window;
	CTile_Map_Loader tile_map;

public:
	Gameplay(sf::RenderWindow& window);

	void update();
};
