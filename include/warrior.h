#include "entity.h"
#include "input.h"

#pragma once
class CWarrior : public CEntity
{
private:

public:
	CWarrior(sf::RenderWindow& Window, 
		std::string Asset_Path = "assets/placeholder.png", bool Is_Animated = false, bool Debug_Mode = true);

	auto handle_movement(float delta_time, CInput& Input) -> void override;
};

