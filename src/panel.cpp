#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c)
	: window(window_c),
	// Text
	user_Health(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()), 42, window.getSize().x - 200.f, 0),
	iron_sword_frame(window_c, "assets/item_assets/old_wooden_sword_frame.png")
{

}

void Panel::update()
{
	// clears the screen every frame
	window.clear();

	iron_sword_frame.draw();

	update_user_health();




}

// Getter

Player& Panel::get_player() { return user; }

// Setter

// Methods

void Panel::update_user_health()
{
	/*Takes the users HP and Max_HP and refreshes the string in Text. Draws the text again on window*/
	user_Health.draw_text(window);
	user_Health.set_text(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()));
}
