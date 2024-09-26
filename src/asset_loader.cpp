#include "asset_loader.h"

Asset_loader::Asset_loader(sf::RenderWindow& window_c, const std::string& path_c, int x_c, int y_c, int width_c, int height_c, float scale_c)
    : window(window_c), path(path_c), x(x_c), y(y_c), scale(scale_c)
{
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    sprite.setScale(scale, scale);
}

auto Asset_loader::center_asset() -> void
{
    sf::Vector2u texture_size = texture.getSize();
    sf::Vector2u window_size = window.getSize();

    sprite.setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    sprite.setPosition(window_size.x / 2.0f, window_size.y / 2.0f);

}

auto Asset_loader::get_texture() -> sf::Texture&
{
    return texture;
}

auto Asset_loader::get_sprite() -> sf::Sprite&
{
    return sprite;
}

auto Asset_loader::get_Local_sprite_bounds() -> sf::FloatRect
{
    return sprite.getLocalBounds();
}

auto Asset_loader::get_Global_sprite_bounds() -> sf::FloatRect
{
    return sprite.getGlobalBounds();
}

auto Asset_loader::set_scale(float value) -> void
{
    sprite.setScale(value, value);
}
