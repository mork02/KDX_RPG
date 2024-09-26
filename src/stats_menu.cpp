#include "stats_menu.h"
#include "panel.h"

CStats_menu::CStats_menu(sf::RenderWindow& window_c) : CMenu(window_c, EMenuType::Stats),
background_asset(window_c, background_path)
{
    background_asset.set_scale(background_scale);
    background_asset.center_asset();
}

auto CStats_menu::draw() -> void
{

    if (visible)
    {
        window.draw(background_asset.get_sprite());
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