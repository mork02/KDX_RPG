#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "entity.h"
#include "warrior.h"
#include "goblin.h"
#include "camera.h"

class Gameplay
{
private:
	sf::RenderWindow& mWindow;
	sf::Clock mClock;
	CCamera mCamera;

	std::unique_ptr<CWarrior> mWarrior;

	std::vector<std::unique_ptr<CEntity>> mEntities;

	auto loadLevel() -> void;
	auto loadEntities() -> void;
public:
	Gameplay(sf::RenderWindow& Window);

	auto event_mouse(sf::Event& Event) -> void;
	auto event_keyboard(sf::Event& Event) -> void;
	auto update() -> void;
};
