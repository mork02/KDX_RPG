#include "asset_loader.h"

Asset_loader::Asset_loader(sf::RenderWindow& window_c, const std::string& path_c, int x_c, int y_c, int width_c, int height_c, float scale_c)
    : window(window_c), path(path_c), x(x_c), y(y_c), scale(scale_c)
{
    if (!texture.loadFromFile(path)) 
    {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);

    // Set position and scale
    sprite.setPosition((float) x, (float) y);
    sprite.setScale(scale, scale);
}

sf::Texture& Asset_loader::get_texture() { return texture; }

sf::Sprite& Asset_loader::get_sprite() { return sprite; }