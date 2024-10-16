#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& cWindow) :
	window(cWindow)
{
	player = std::make_unique<CPlayer>();
	loadLevel();
}

auto Gameplay::loadLevel() -> void
{

}

auto Gameplay::update() -> void
{

}