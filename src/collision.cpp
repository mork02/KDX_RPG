#include "collision.h"

auto CCollision::check_collision(CEntity* x, CEntity* y) -> bool
{
	if (x->get_Asset().get_Sprite().getGlobalBounds().contains(y->get_Asset().get_Sprite().getGlobalBounds().getPosition()))
	{
		return true;
	}
	return false;
}
