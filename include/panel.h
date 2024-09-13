#pragma once
#include "SFML/Graphics.hpp"
#include "input.h"
#include "gameplay.h"
#include "main_menu.h"
#include "menu.h"
#include "scene_manager.h"

class Panel
{
private:
	sf::RenderWindow& window;
	Input& input;

	Scene current_scene;
	Main_menu main_menu;
	Menu menu;
	Gameplay gameplay;

public:
	Panel(sf::RenderWindow& window, Input& input);

	// Getter
	Menu& get_menu();
	Main_menu& get_main_menu();
	Gameplay& get_gameplay();
	Input& get_input() const;

	// Setter
	void set_scene(Scene scene);

	// Methods
	void update();
};

