#include "entity.h"
#include "input.h"
#include "animation_enum.h"

#pragma once
class CWarrior : public CEntity
{
private:

public:
	CWarrior(sf::RenderWindow& Window, std::string Asset_Path = "assets/character_assets/AnimationSheet_Character.png", bool Is_Animated = true);

	auto handle_movement(float delta_time, CInput& Input) -> void override;
};

