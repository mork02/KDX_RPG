#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c, Input& input_c)
	: window(window_c), input(input_c), current_scene(Scene::Main_Menu),
	main_menu(window_c, *this, input_c), menu(window_c, *this, input_c), gameplay(window_c), stats_menu(window_c, *this, input_c)
{

}

void Panel::update()
{
	// clears the screen every frame
	window.clear();

	switch (current_scene)
	{
	case Scene::Main_Menu:
		main_menu.draw();
		break;
	case Scene::Option_Menu:
		break;
	case Scene::Game_Over:
		break;
	case Scene::Gameplay:
		gameplay.update();
		stats_menu.draw();
		menu.draw();
		break;
	}

}

// Getter

Menu& Panel::get_menu() { return menu; }

Stats_menu& Panel::get_stats_menu() { return stats_menu; }

Main_menu& Panel::get_main_menu() { return main_menu; }

Gameplay& Panel::get_gameplay() { return gameplay; }

Input& Panel::get_input() const { return input; }

Scene& Panel::get_scene() { return current_scene; }


// Setter

void Panel::set_scene(Scene scene)
{
	current_scene = scene;
}

// Methods
