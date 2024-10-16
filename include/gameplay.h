#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
#include <memory>
#include "asset_loader.h"
#include "tile_map_loader.h"
#include <iostream>

class Gameplay
{
private:
	sf::RenderWindow& window;

	std::unique_ptr<CPlayer> player;

	auto loadLevel() -> void;

public:
	Gameplay(sf::RenderWindow& window);

	auto update() -> void;
};
