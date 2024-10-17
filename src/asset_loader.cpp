#include "asset_loader.h"

CAsset_loader::CAsset_loader(sf::RenderWindow& Window, const std::string& Path, bool Is_Animated, int X, int Y)
    : mWindow(Window), CAnimation_loader(), 
    mPath(Path), 
    mIs_Animated(Is_Animated), 
    mX(X), mY(Y)
{
    if (!mTexture.loadFromFile(mPath))
    {
        std::cerr << "Error loading texture from " << mPath << std::endl;
        Window.close();
    }

    mSprite.setTexture(mTexture);
    mSprite.setPosition(static_cast<float>(mX), static_cast<float>(mY));
    mSprite.setScale(mScale, mScale);

    if (mIs_Animated)    setup_animation(mTexture);
}

auto CAsset_loader::center_asset() -> void
{
    sf::Vector2u texture_size = mTexture.getSize();
    sf::Vector2u window_size = mWindow.getSize();

    mSprite.setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    mSprite.setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
}

auto CAsset_loader::draw() -> void
{
    if (mIs_Animated)    update(mSprite);
    mWindow.draw(mSprite);
}

auto CAsset_loader::get_texture() -> sf::Texture&
{
    return mTexture;
}

auto CAsset_loader::get_sprite() -> sf::Sprite&
{
    return mSprite;
}

auto CAsset_loader::get_Local_sprite_bounds() -> sf::FloatRect
{
    return mSprite.getLocalBounds();
}

auto CAsset_loader::get_Global_sprite_bounds() -> sf::FloatRect
{
    return mSprite.getGlobalBounds();
}

auto CAsset_loader::set_scale(float value) -> void
{
    mSprite.setScale(value, value);
}

auto CAsset_loader::set_Position(float x, float y) -> void
{
    mSprite.move(x, y);
}