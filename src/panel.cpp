#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c)
	: window(window_c),
	// Text
	user_Health(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()), 42, 100, 100)

{

}

void Panel::update()
{
	// clears the screen every frame
	window.clear();

	rect.draw_rect(window);
	update_user_health();

	user.get_stats().set_hp(-1);
 
}

void Panel::update_user_health()
{
	/*Takes the users HP and Max_HP and refreshes the string in Text. Draws the text again on window*/
	user_Health.draw_text(window);
	user.get_stats().set_hp(-1);
	user_Health.set_text(std::to_string(user.get_stats().get_hp()) + " / " + std::to_string(user.get_stats().get_max_hp()));
}