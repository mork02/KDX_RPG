#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"

class Frame
{
private:
	void gameloop();

	const unsigned WINDOW_WIDTH = 1920;
	const unsigned WiNDOW_HEIGHT = 1080;
	const std::string WINDOW_TITLE = "KDX_RPG";

	FPS fps_class;
	const int fps_value = 60;

	sf::RenderWindow window;
	Panel panel;


public:
	Frame();

};

