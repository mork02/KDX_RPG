#include "entity.h"
#include "input.h"
#include "animation_enum.h"

#pragma once
class CWarrior : public CEntity
{
private:

public:
	CWarrior(sf::RenderWindow& Window);

	auto handle_movement(float delta_time, CInput& Input) -> void override;
};

