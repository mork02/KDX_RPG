#pragma once
#include "SFML/Graphics.hpp"

class CStateManager;

class CState
{
public:
	virtual ~CState() {};

	virtual auto handle_events(sf::Event& Event, CStateManager& StateManager) -> void = 0;

	virtual auto update(float delta_time) -> void = 0;
	virtual auto render() -> void = 0;
	// virtual auto clean_up() -> void = 0;
};

