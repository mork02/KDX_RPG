#include "animation_loader.h"

CAnimation_loader::CAnimation_loader()
{}

auto CAnimation_loader::setup_animation(const sf::Texture& Texture, float Frame_Duration, unsigned Frame_Width, unsigned Frame_Height) -> void
{
    sf::Vector2u texture_size = Texture.getSize();
    for (unsigned y = 0; y < texture_size.y; y += Frame_Height)
    {
        for (unsigned x = 0; x < texture_size.x; x += Frame_Width)
        {
            mFrames.emplace_back(sf::IntRect(x, y, Frame_Width, Frame_Height));
        }
    }
}

auto CAnimation_loader::get_frame_rect(unsigned frame_index) -> sf::IntRect
{
    if (frame_index < mFrames.size())
    {
        return mFrames[frame_index];
    }
    return sf::IntRect();
}

auto CAnimation_loader::get_total_frames() -> unsigned
{
    return mFrames.size();
}

auto CAnimation_loader::update(sf::Sprite& sprite) -> void
{
    if (mFrame_Timer.getElapsedTime().asSeconds() >= mFrame_Duration)
    {
        mCurrent_Frame = (mCurrent_Frame + 1) % get_total_frames();
        sprite.setTextureRect(get_frame_rect(mCurrent_Frame));
        mFrame_Timer.restart();
    }
}