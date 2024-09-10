#pragma once
#include "SFML/Graphics.hpp"
#include "text.h"
#include "asset_loader.h"
#include "player.h"
#include "menu.h"
#include "main_menu.h"
#include "input.h"
#include "scene_manager.h"

class Panel
{
private:
	sf::RenderWindow& window;
	Input& input;

	Player user;
	Scene current_scene;
	Menu menu;
	Main_menu main_menu;

public:
	Panel(sf::RenderWindow& window, Input& input);

	// Getter
	Player& get_player();
	Menu& get_menu();
	Main_menu& get_main_menu();
	Input& get_input() const;

	// Setter
	void set_scene(Scene scene);

	// Methods
	void update();
	void update_user_health();
};

