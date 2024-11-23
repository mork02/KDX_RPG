#pragma once
#include "SFML/Graphics.hpp"

class CEntity;

class CDebugManager
{
private:
	static auto Hitbox(sf::RenderWindow& Window, CEntity* Entity) -> void;
	static auto MousePosition(sf::RenderWindow& Window) -> void;
public:
	static auto render(sf::RenderWindow& Window, CEntity* Entity) -> void;
};

