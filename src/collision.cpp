#include "collision.h"
#include "enums.h"

auto CCollision::entity_check(CEntity* x, CEntity* y) -> bool
{
	if (x->get_Asset().get_Sprite().getGlobalBounds().intersects(y->get_Asset().get_Sprite().getGlobalBounds()))
	{
		std::cout << "Collision between: " << "\033[1;31m " << x->get_name() << " \033[0m" << " and " << "\033[1;31m " << y->get_name() << " \033[0m" << std::endl;
		return true;
	}
	return false;
}