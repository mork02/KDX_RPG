#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class CAnimation_loader
{
private:
    std::vector<sf::IntRect> mFrames;

    unsigned int mCurrent_Frame = 0;
    float mFrame_Duration = .25f;
    sf::Clock mFrame_Timer;
    // TODO: add frame_duration changer for handling animation speed like walking and running

protected:
    CAnimation_loader();

    auto setup_animation(const sf::Texture& Texture, unsigned Row, unsigned Frame_Lenght, unsigned Frame_Width, unsigned Frame_Height) -> void;
    auto get_frame_rect(unsigned frame_index) -> sf::IntRect;
    auto get_total_frames() -> unsigned;
    auto update(sf::Sprite& sprite) -> void;

};