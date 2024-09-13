#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& window_c) : window(window_c), sword(window_c, "assets/item_assets/iron_sword_frame.png") {}

void Gameplay::update() 
{
	window.draw(sword.get_sprite());
}