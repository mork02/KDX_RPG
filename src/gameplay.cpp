#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& window_c) :
	window(window_c),
	user(),
	sword(window_c, "assets/item_assets/iron_sword_frame.png") {}

Player& Gameplay::get_player() { return user; }

void Gameplay::update() 
{
	window.draw(sword.get_sprite());
	map.loadFromCSV("assets/Sprite-0001.png", sf::Vector2u(32, 32), "assets/csv/x.csv", 16, 16, sf::Vector2f(4, 3));
	window.draw(map);
}