#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"
#include "input.h"

class Main_menu;
class Menu;

class Frame
{
private:
	void gameloop();

	const unsigned WINDOW_WIDTH = 1920;
	const unsigned WINDOW_HEIGHT = 1080;
	const std::string WINDOW_TITLE = "KDX_RPG";

	FPS fps_class;
	const int fps_value = 60;

	sf::RenderWindow window;
	sf::Event event;
	Panel panel;
	Input input;
	Main_menu main_menu;
	Menu menu;

private:
	void handle_window_close_event();
	void handle_mouse_click();
	void handle_keyboard_input();
	void handle_main_menu_click_event();
	void handle_menu_click_event();
	void toggle_menu_visibility();

public:
	Frame();

};

