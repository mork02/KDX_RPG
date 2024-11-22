#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "pause_menu.h"
#include "option_menu.h"
#include "stats_menu.h"

class CMenuManager
{
private:
	sf::RenderWindow& mWindow;

	std::unique_ptr<CPause_menu> mPause_Menu = std::make_unique<CPause_menu>(mWindow);
	std::unique_ptr<COption_menu> mOption_Menu = std::make_unique<COption_menu>(mWindow);
	std::unique_ptr<CStats_menu> mStats_Menu = std::make_unique<CStats_menu>(mWindow);

	CMenu* mCurrent_Menu = nullptr;

public:
	CMenuManager(sf::RenderWindow& Window);

	auto set_menu(CMenu* new_Menu) -> void;
	auto get_pause_menu() -> CPause_menu*;
	auto get_option_menu() -> COption_menu*;
	auto get_stats_menu() -> CStats_menu*;

	auto handle_events(sf::Event& Event, CStateManager* StateManager) -> void;
	auto update(float delta_time) -> void;
	auto render() -> void;
};

