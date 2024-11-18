#include "entity.h"

#pragma once
class CGoblin : public CEntity
{
private:
	auto init_asset() -> void override;

public:
	CGoblin(sf::RenderWindow& Window);

	auto render() -> void override;
	auto handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void override;
	auto update(float delta_time) -> void override;
};

