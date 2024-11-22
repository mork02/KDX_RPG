#include "statusbar.h"
#include "entity.h"

CStatusBar::CStatusBar(sf::RenderWindow& Window) :
	mAsset(Window)
{
	// mAsset.init_asset()
}

auto CStatusBar::update(CEntity* entity) -> void
{
	if (entity->get_hp() % 25 == 0 && entity->get_hp() <= entity->get_max_hp())
	{
		
	}
}

auto CStatusBar::render() -> void
{

}
