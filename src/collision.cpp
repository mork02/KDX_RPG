#include "collision.h"

auto CCollision::check_collision(CEntity* x, CEntity* y) -> bool
{
	if (x->get_Asset().get_Sprite().getGlobalBounds().intersects(y->get_Asset().get_Sprite().getGlobalBounds()))
	{
		return true;
	}
	return false;
}