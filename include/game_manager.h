#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
#include "utility"
#include "fps.h"
#include "state_manager.h"
#include "enums.h"

class CGameManager
{
private:
	const std::string WINDOW_TITLE = "KDX_RPG";
	const int FPS_Value = 60;

	std::vector<std::pair<unsigned, unsigned>> Resolution = 
	{  
		{1280, 720},
		{1920, 1080},
		{2560, 1440},
		{3840, 2160}
	};
	unsigned Resolution_Index = 1;
	sf::RenderWindow Window;
	sf::Event Event;
	CFPS FPS;
	sf::Clock Clock;

	CStateManager StateManager;

	auto handle_events() -> void;
	auto configure_resolution() -> void;
	auto resize_window() -> void;
	auto render() -> void;
	auto update(float delta_time) -> void;

public:
	CGameManager();
	auto Run() -> void;

};
