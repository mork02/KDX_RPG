#include "asset_loader.h"

CAsset_loader::CAsset_loader(sf::RenderWindow& Window) :
    mWindow(Window), 
    CAnimation_loader(), 
    mD_Coordinates(Window, "", ECharacter_Size::VERY_SMALL), mIs_Animated(false)
{}

auto CAsset_loader::init_asset(std::string Path) -> void
{
    mIs_Animated = false;

    if (!mTexture.loadFromFile(Path))
    {
        std::cerr << "Error loading texture from " << Path << std::endl;
    }

    mSprite.setTexture(mTexture);

    mScale = { 3, 3 };
    mSprite.setScale(mScale.x, mScale.y);

}

auto CAsset_loader::init_animation(std::string Path, unsigned Row, unsigned Frame_Length, unsigned Frame_Width, unsigned Frame_Height) -> void
{
    mIs_Animated = true;

    if (!mTexture.loadFromFile(Path))
    {
        std::cerr << "Error loading texture from " << Path << std::endl;
    }
    mSprite.setTexture(mTexture);

    if (mIs_Animated)
    {
        if (Row == 0) Row = 1;
        if (Frame_Length == 0) Frame_Length = 1;

        setup_animation(mTexture, Row, Frame_Length, Frame_Width, Frame_Height);

        mSprite.setTextureRect(get_frame_rect(0));
    }

    mScale = { 3, 3 };
    mSprite.setScale(mScale.x, mScale.y);
}

auto CAsset_loader::center_asset() -> void
{
    sf::Vector2u texture_size = mTexture.getSize();
    sf::Vector2u window_size = mWindow.getSize();

    mSprite.setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    mSprite.setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
}

auto CAsset_loader::render() -> void
{
    if (mIs_Animated)   update(mSprite);

    mWindow.draw(mSprite);
}

auto CAsset_loader::get_Texture() -> sf::Texture&
{
    return mTexture;
}

auto CAsset_loader::get_Sprite() -> sf::Sprite&
{
    return mSprite;
}

auto CAsset_loader::get_Scale() -> sf::Vector2f&
{
    return mScale;
}

auto CAsset_loader::set_Position(float x, float y) -> void
{
    mSprite.setPosition(x, y);
}

auto CAsset_loader::set_is_Animated(bool value) -> void
{
    mIs_Animated = value;
    
}

auto CAsset_loader::set_animation_param(unsigned Row, unsigned Frame_Length, unsigned Frame_Width, unsigned Frame_Height) -> void
{
    if (Row == mCurrent_Row && Frame_Length == mCurrent_Frame_Length)
    {
        return;
    }

    mCurrent_Row = Row;
    mCurrent_Frame_Length = Frame_Length;

    if (Row == 0) Row = 1;
    if (Frame_Length == 0) Frame_Length = 1;

    setup_animation(mTexture, Row, Frame_Length, Frame_Width, Frame_Height);
    mSprite.setTextureRect(get_frame_rect(0));
}

auto CAsset_loader::set_direction(bool value) -> void
{
    if (value) mSprite.setScale(mScale.x, mScale.y);
    else mSprite.setScale(-mScale.x, mScale.y);
}

auto CAsset_loader::set_origin_center() -> void
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}
