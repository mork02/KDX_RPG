#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& window_c) :
	window(window_c),
	user(),
	sword(window_c, "assets/item_assets/iron_sword_frame.png") {}

Player& Gameplay::get_player() { return user; }

void Gameplay::update() 
{
	window.draw(sword.get_sprite());
}