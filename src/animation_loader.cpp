#include "animation_loader.h"

CAnimation_loader::CAnimation_loader() {}

auto CAnimation_loader::setup_animation(const sf::Texture& Texture, unsigned Row, unsigned Frame_Lenght, unsigned Frame_Width, unsigned Frame_Height) -> void
{
    mFrames.clear();

    unsigned y = Row * Frame_Height - Frame_Height;

    sf::Vector2u texture_size = Texture.getSize();
    int max_frames_in_row = texture_size.x / Frame_Width;

    Frame_Lenght = std::min((int)Frame_Lenght, max_frames_in_row);

    for (unsigned i = 0; i < Frame_Lenght; ++i)
    {
        unsigned x = i * Frame_Width;
        mFrames.emplace_back(sf::IntRect(x, y, Frame_Width, Frame_Height));
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

auto CAnimation_loader::get_total_frames() -> size_t
{
    return mFrames.size();
}

auto CAnimation_loader::update_frames(sf::Sprite& sprite) -> void
{
    if (mFrame_Timer.getElapsedTime() >= sf::seconds(mFrame_Duration))
    {
        // std::cout << "1. Current Frame -> " << mCurrent_Frame << std::endl;
        mCurrent_Frame = (mCurrent_Frame + 1) % get_total_frames();
        // std::cout << "2. Next Frame -> " << mCurrent_Frame << std::endl;
        sprite.setTextureRect(get_frame_rect(mCurrent_Frame));
        //std::cout << "3. Current Timer -> " << (float) mFrame_Timer.getElapsedTime().asSeconds() << std::endl;
        mFrame_Timer.restart();
    }
}