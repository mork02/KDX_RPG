#pragma once
#include <SFML/Graphics.hpp>

class CAnimation_loader
{
private:
    unsigned const width = 32;
    unsigned const height = 32;
    std::vector<sf::IntRect> frames;

    unsigned int current_frame = 0;
    sf::Clock frame_timer;
    float frame_duration = 0.5f;

protected:
    CAnimation_loader();

    auto setup_animation(const sf::Texture& texture, float frame_duration = 0.5f, unsigned frame_width = 32, unsigned frame_height = 32) -> void;
    auto get_frame_rect(unsigned frame_index) -> sf::IntRect;
    auto get_total_frames() -> unsigned;
    auto update(sf::Sprite& sprite) -> void;
};