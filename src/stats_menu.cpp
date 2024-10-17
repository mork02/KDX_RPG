#include "stats_menu.h"
#include "panel.h"

CStats_menu::CStats_menu(sf::RenderWindow& Window) : CMenu(Window, EMenuType::Stats),
mBackground_Asset(Window, mBackground_Path)
{
    mBackground_Asset.set_scale(mBackground_Scale);
    mBackground_Asset.center_asset();
}

auto CStats_menu::draw() -> void
{

    if (mVisible)
    {
        mWindow.draw(mBackground_Asset.get_sprite());
    }
}

auto CStats_menu::handle_click_event(CPanel& panel) -> void
{
    /*
    // placeholder
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    if (continue_text.get_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
    }
    */
}