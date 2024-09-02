#include "panel.h"

Panel::Panel() {

}

void Panel::update(sf::RenderWindow& window)
{
	rect.draw_rect(window);
}

