#include "stats_menu.h"

CStats_menu::CStats_menu(sf::RenderWindow& window_c) : CMenu(window_c, EMenuType::Stats),
background_asset(window_c, background_path)
{
    background_asset.set_scale(background_scale);
    center_asset(background_asset);
}

auto CStats_menu::get_visible() const -> bool
{
    return visible;
}

auto CStats_menu::set_visible(bool value) -> void
{
    visible = value;
}

auto CStats_menu::draw() -> void
{

    if (visible)
    {
        window.draw(background_asset.get_sprite());
    }
}

auto CStats_menu::center_asset(Asset_loader& asset) -> void
{
    sf::Vector2u texture_size = asset.get_texture().getSize();
    sf::Vector2u window_size = window.getSize();

    asset.get_sprite().setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    asset.get_sprite().setPosition(window_size.x / 2.0f, window_size.y / 2.0f);

}