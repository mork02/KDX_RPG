#include "asset_loader.h"

CAsset_loader::CAsset_loader(sf::RenderWindow& Window, const std::string& Path, bool Is_Animated, unsigned Row, unsigned Frame_Length, unsigned Frame_Width, unsigned Frame_Height) :
    mWindow(Window), CAnimation_loader(),
    mPath(Path),
    mIs_Animated(Is_Animated),
    mX(0), mY(0),
    mFrame_Width(Frame_Width), mFrame_Height(Frame_Height)
{
    if (!mTexture.loadFromFile(mPath) && mIs_Animated)
    {
        std::cerr << "Error loading texture from " << mPath << std::endl;
    }

    mSprite.setTexture(mTexture);
    mSprite.setPosition(mX, mY);
    mSprite.setScale(mScale, mScale);

    if (mIs_Animated)
    {
        if (Row == 0) Row = 1;
        if (Frame_Length == 0) Frame_Length = 1;

        setup_animation(mTexture, Row, Frame_Length, mFrame_Width, mFrame_Height);

        mSprite.setTextureRect(get_frame_rect(0));
    }
}

auto CAsset_loader::center_asset() -> void
{
    sf::Vector2u texture_size = mTexture.getSize();
    sf::Vector2u window_size = mWindow.getSize();

    mSprite.setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    mSprite.setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
}

auto CAsset_loader::update_Coordinates() -> void
{
    mX = get_Global_sprite_bounds().getPosition().x;
    mY = get_Global_sprite_bounds().getPosition().y;
}

auto CAsset_loader::draw() -> void
{
    if (mIs_Animated) update(mSprite);

    update_Coordinates();
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

/* debugging stuff

auto CAsset_loader::debug_Coordinates() -> void
{
    std::string text = ("X: " + std::to_string(mX) + " / " + "Y: " + std::to_string(mY));
    mCoordinates.set_text(text);

    float debug_X = mX;
    float debug_Y = mY + get_Global_sprite_bounds().height;

    mCoordinates.set_position(debug_X, debug_Y);
    mCoordinates.draw_text(mWindow);
}

auto CAsset_loader::debug_Box() -> void
{
    if (mDebug_Mode)
    {
        sf::FloatRect sprite_bounds = mSprite.getGlobalBounds();

        sf::RectangleShape debug_box(sf::Vector2f(sprite_bounds.width, sprite_bounds.height));

        debug_box.setPosition(sprite_bounds.left, sprite_bounds.top);

        debug_box.setOutlineColor(sf::Color::Blue);
        debug_box.setOutlineThickness(2.0f);

        debug_box.setFillColor(sf::Color::Transparent);

        mWindow.draw(debug_box);
    }
}

auto CAsset_loader::debug() -> void
{
    debug_Box();
    debug_Coordinates();
}
*/