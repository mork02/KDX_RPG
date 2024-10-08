#pragma once
#include <SFML/Graphics.hpp>

class CAnimation_loader
{
protected:
    unsigned const width = 32;
    unsigned const height = 32;
    std::vector<sf::IntRect> frames;

public:
    CAnimation_loader();

    auto setup_animation(const sf::Texture& texture, unsigned frame_width, unsigned frame_height) -> void;
    auto get_frame_rect(unsigned frame_index) -> sf::IntRect;
    auto get_total_frames() -> unsigned;
};