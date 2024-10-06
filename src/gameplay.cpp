#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& window_c) :
	window(window_c),
	tile_map("assets/tilemap/level1.png", 7, 3)
{
	loadLevel();
}

auto Gameplay::loadLevel() -> void
{
	tile_map.addLayer(ELayers::Ground, "assets/tilemap/csv/level1.csv");
}

auto Gameplay::update() -> void
{
	tile_map.draw(window);
}