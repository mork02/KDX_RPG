#pragma once
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "gameplay.h"
#include "title_screen.h"
#include "enums.h"

class CGameManager
{
private:
	unsigned WINDOW_WIDTH = 1920;
	unsigned WINDOW_HEIGHT = 1080;
	const std::string WINDOW_TITLE = "KDX_RPG";
	const int FPS_Value = 60;

	sf::RenderWindow Window;
	sf::Event Event;
	CFPS FPS;
	sf::Clock Clock;

	CTitle_Screen Title_Screen;
	CGameplay Gameplay;

	EGameState GameState = EGameState::TITLE_SCREEN;

	auto handle_events() -> void;
	auto render() -> void;
	auto update(float delta_time) -> void;

public:
	auto set_GameState(EGameState NewGameState) -> void;

	CGameManager();
	auto Run() -> void;
};
