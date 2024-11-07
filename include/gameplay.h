#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "pause_menu.h"
#include "option_menu.h"
#include "stats_menu.h"
#include "entity.h"
#include "warrior.h"
#include "goblin.h"
#include "camera.h"

class CGameplay
{
private:
	sf::RenderWindow& mWindow;
	sf::Clock mClock;
	CCamera mCamera;

	// TODO: add menu icons on screen to point to click open menu
	// no keyboard input anymore
	std::unique_ptr<CPause_menu> mPause_Menu;
	std::unique_ptr<COption_menu> mOption_Menu;
	std::unique_ptr<CStats_menu> mStats_Menu;

	CMenu* mCurrent_Menu = nullptr;

	std::unique_ptr<CWarrior> mWarrior;
	std::vector<std::unique_ptr<CEntity>> mEntities;

	auto load_Level() -> void;
	auto load_Entities() -> void;
public:
	CGameplay(sf::RenderWindow& Window);

	auto get_menu_options() -> COption_menu&;
	auto get_menu_pause() -> CPause_menu&;
	auto get_menu_stats() -> CStats_menu&;

	auto set_current_menu(CMenu* new_menu) -> void;

	auto event_mouse(sf::Event& Event, CPanel* Panel) -> void;
	auto event_keyboard(sf::Event& Event) -> void;
	auto update(float delta_time) -> void;
};
