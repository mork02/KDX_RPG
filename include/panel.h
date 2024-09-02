#pragma once
#include "SFML/Graphics.hpp"
#include "rect.h"

class Panel
{
private:
	Rect rect;

public:
	Panel();
	void update(sf::RenderWindow& window);
};

