#include "goblin.h"


CGoblin::CGoblin(sf::RenderWindow& Window) : 
    CEntity(Window, "Goblin", 15, 15, 3, 1)
{
    init_asset();
}

auto CGoblin::init_asset() -> void
{
    // TODO: add different spawn system
    // TODO: add goblin texture
    // TODO: add ai movement
    mAsset.init("assets/character_assets/wolf_tailwag_tf-shadow.png", true, EAnimation_Goblin::A_SIT_FRONT, EAnimation_Goblin::L_SIT_FRONT);
    mAsset.set_debug(true);
    mAsset.set_origin_center();
    mAsset.get_Sprite().setPosition(500, 500);
}