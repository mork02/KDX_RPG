#include "asset_loader.h"

Asset_loader::Asset_loader(sf::RenderWindow& window_c, const std::string& path_c, int x_c, int y_c, float scale_c)
    : window(window_c), path(path_c), x(x_c), y(y_c), scale(scale_c)
{
    // Load the texture from file
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    // Set the texture for the sprite
    sprite.setTexture(texture);

    // Set position and scale
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    sprite.setScale(scale, scale);
}

void Asset_loader::draw()
{
    window.draw(sprite);
}