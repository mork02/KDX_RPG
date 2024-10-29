#include "stats_menu.h"
#include "panel.h"

CStats_menu::CStats_menu(sf::RenderWindow& Window) : 
    CMenu(Window, EMenuType::Stats)
{
    mAsset.init(mPath);
    mAsset.center_asset();
}

auto CStats_menu::draw() -> void
{

    if (get_visible())
    {
        mWindow.draw(mAsset.get_Sprite());
    }
}

auto CStats_menu::handle_click_event(CPanel& panel) -> void
{

}