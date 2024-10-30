#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "warrior.h"
#include "entity.h"
#include "input.h"
#include "camera.h"

class Gameplay
{
private:
	sf::RenderWindow& mWindow;
	sf::Clock mClock;
	CInput& mInput;
	CCamera mCamera;
	CAsset_loader mBackground;

	std::unique_ptr<CWarrior> mWarrior;

	std::vector<CEntity*> mEntities;

	auto loadLevel() -> void;
	auto loadEntities() -> void;

public:
	Gameplay(sf::RenderWindow& Window, CInput& Input);

	auto handle_mouse_input() -> void;
	auto update() -> void;
};
