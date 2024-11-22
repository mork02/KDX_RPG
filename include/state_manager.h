#pragma once
#include <iostream>
#include "gameplay_state.h"
#include "title_screen_state.h"
#include "state.h"
#include "enums.h"

class CStateManager
{
private:
	CState* mState;
	std::unique_ptr<CGameplay> mGameplay;
	std::unique_ptr<CTitle_Screen> mTitle_Screen;

public:
	CStateManager(sf::RenderWindow& Window);
	auto set_state(CState* State) -> void;
	auto get_gameplay() -> CGameplay*;
	auto get_title_screen() -> CTitle_Screen*;

	auto handle_events(sf::Event& Event) -> void;
	auto update(float delta_time) -> void;
	auto render() -> void;

};

