#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c, Input& input_c)
	: window(window_c), input(input_c), current_scene(Scene::Main_Menu),
	//user_Health(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()), 42, window.getSize().x - 200.f, 0),
	menu(window_c, *this, input_c), main_menu(window_c, *this, input_c)
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
		// draw gameplay
		menu.draw();
		break;
	}

}

// Getter

Player& Panel::get_player() { return user; }

Menu& Panel::get_menu() { return menu; }

Main_menu& Panel::get_main_menu() { return main_menu; }

Input& Panel::get_input() const { return input; }


// Setter

void Panel::set_scene(Scene scene)
{
	current_scene = scene;
}

// Methods

void Panel::update_user_health()
{
	/*Takes the users HP and Max_HP and refreshes the string in Text. Draws the text again on window*/

	/*
	std::string new_text = std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp());

	if (user_Health.get_text().getString() != new_text) {
		user_Health.set_text(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()));
	}

	user_Health.draw_text(window);
	*/
}
