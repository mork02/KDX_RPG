#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "tile_map_loader.h"
#include "player.h"
#include "warrior.h"
#include "entity.h"
#include "input.h"

class Gameplay
{
private:
	sf::RenderWindow& mWindow;
	sf::Clock mClock;
	CInput& mInput;

	std::unique_ptr<CPlayer> mPlayer;
	std::unique_ptr<CWarrior> mWarrior;

	std::vector<CEntity*> mShown_Entities = {};

	auto loadLevel() -> void;
	auto loadEntities() -> void;

public:
	Gameplay(sf::RenderWindow& Window, CInput& Input);

	auto handle_mouse_input(sf::Event* current_event) -> void;
	auto update() -> void;
};
