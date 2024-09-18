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

auto Asset_loader::get_texture() -> sf::Texture&
{
    return texture;
}

auto Asset_loader::get_sprite() -> sf::Sprite&
{
    return sprite;
}
