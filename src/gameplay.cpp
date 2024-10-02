#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& window_c) :
	window(window_c),
	tile_map("assets/test.png", 3, 2)
{
	tile_map.addLayer(ELayers::Ground, "assets/csv/test.csv");
	tile_map.addLayer(ELayers::Player, "assets/csv/test2.csv");
}

void Gameplay::update() 
{
	tile_map.draw(window);
}