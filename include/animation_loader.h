#pragma once
#include <SFML/Graphics.hpp>

class CAnimation_loader
{
private:
    unsigned const mWidth = 32;
    unsigned const mHeight = 32;
    std::vector<sf::IntRect> mFrames;

    unsigned int mCurrent_Frame = 0;
    sf::Clock mFrame_Timer;
    float mFrame_Duration = 0.5f;

protected:
    CAnimation_loader();

    auto setup_animation(const sf::Texture& Texture, float Frame_Duration = 0.5f, unsigned Frame_Width = 32, unsigned Frame_Height = 32) -> void;
    auto get_frame_rect(unsigned frame_index) -> sf::IntRect;
    auto get_total_frames() -> unsigned;
    auto update(sf::Sprite& sprite) -> void;
};