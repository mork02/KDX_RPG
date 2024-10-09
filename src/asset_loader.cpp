#include "asset_loader.h"

CAsset_loader::CAsset_loader(sf::RenderWindow& window_c, const std::string& path_c, bool isAnimated, int x_c, int y_c)
    : window(window_c), CAnimation_loader(), 
    path(path_c), 
    is_animated(isAnimated), 
    x(x_c), y(y_c)
{
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    sprite.setScale(scale, scale);

    if (is_animated)    setup_animation(texture);
}

auto CAsset_loader::center_asset() -> void
{
    sf::Vector2u texture_size = texture.getSize();
    sf::Vector2u window_size = window.getSize();

    sprite.setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    sprite.setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
}

auto CAsset_loader::draw() -> void
{
    if (is_animated)    update(sprite);
    window.draw(sprite);
}

auto CAsset_loader::get_texture() -> sf::Texture&
{
    return texture;
}

auto CAsset_loader::get_sprite() -> sf::Sprite&
{
    return sprite;
}

auto CAsset_loader::get_Local_sprite_bounds() -> sf::FloatRect
{
    return sprite.getLocalBounds();
}

auto CAsset_loader::get_Global_sprite_bounds() -> sf::FloatRect
{
    return sprite.getGlobalBounds();
}

auto CAsset_loader::set_scale(float value) -> void
{
    sprite.setScale(value, value);
}
