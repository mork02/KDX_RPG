#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "menu_manager.h"
#include "entity.h"
#include "warrior.h"
#include "goblin.h"
#include "camera.h"
#include "enums.h"
#include "state.h"
#include "tmx_loader.h"

class CGameManager;

class CGameplay : public CState
{
private:
	sf::RenderWindow& mWindow;
	CCamera mCamera;

	CMenuManager MenuManager;

	// expample for Pausing the screen
	bool mPause = false;
	bool mDebugging = false;

	std::unique_ptr<CWarrior> mWarrior;
	std::vector<std::unique_ptr<CEntity>> mEntities;

	CTmx_Loader tmx;

	auto load_Level() -> void;
	auto load_Entities() -> void;
public:
	CGameplay(sf::RenderWindow& Window);

	auto set_debugging(bool Value) -> void;
 
	auto handle_events(sf::Event& Event, CStateManager& StateManager) -> void override;
	auto render() -> void override;
	auto update(float delta_time) -> void override;
};
