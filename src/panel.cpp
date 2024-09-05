#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c)
	: window(window_c),
	// Text
	user_Health(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()), 42, window.getSize().x - 200.f, 0),
	iron_sword_frame(window_c, "assets/item_assets/old_wooden_sword_frame.png"),
	menu(window_c)
{

}

void Panel::update()
{
	// clears the screen every frame
	window.clear();

	iron_sword_frame.draw();
	menu.draw_menu();
	update_user_health();

}

// Getter

Player& Panel::get_player() { return user; }

Menu& Panel::get_menu() { return menu; }

// Setter

// Methods

void Panel::update_user_health()
{
	/*Takes the users HP and Max_HP and refreshes the string in Text. Draws the text again on window*/

	std::string new_text = std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp());

	if (user_Health.get_text().getString() != new_text) {
		user_Health.set_text(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()));
	}

	user_Health.draw_text(window);
}
