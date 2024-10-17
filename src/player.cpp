#include "player.h"

CPlayer::CPlayer(sf::RenderWindow& Window) 
	: CEntity(Window, "assets/character_assets/test.png", true, true, "Advanturer", 100, 100, 0, 0), CInventory()
{
}
