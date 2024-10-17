#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "tile_map_loader.h"
#include "player.h"
#include "entity.h"

class Gameplay
{
private:
	sf::RenderWindow& mWindow;

	std::unique_ptr<CPlayer> mPlayer;
	std::unique_ptr<CPlayer> mPlayer2;

	const float mMove_Speed = 5.0f;

	std::vector<CEntity*> mShown_Entities = {};

	auto loadLevel() -> void;
	auto loadEntities() -> void;

public:
	Gameplay(sf::RenderWindow& Window);

	auto update() -> void;
};
