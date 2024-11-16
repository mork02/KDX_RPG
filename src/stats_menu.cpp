#include "stats_menu.h"
#include "panel.h"

CStats_menu::CStats_menu(sf::RenderWindow& Window) : 
    CMenu(Window, EMenuState::STATS)
{
    init_asset(mPath);
    get_Sprite().setScale(6, 6);
    center_asset();
}

auto CStats_menu::draw() -> void
{

    if (get_visible())
    {
        mWindow.draw(get_Sprite());
    }
}

auto CStats_menu::handle_events(CGameplay& Gameplay, CGameManager* GameManager) -> void
{

}