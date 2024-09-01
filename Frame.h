#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "Panel.h"

class Frame
{
private:
	void open_window();

	sf::RenderWindow window;
	Panel panel;

public:
	Frame();

};

