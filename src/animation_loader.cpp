#include "animation_loader.h"

CAnimation_loader::CAnimation_loader()
{}

auto CAnimation_loader::setup_animation(const sf::Texture& texture, float frame_duration, unsigned frame_width, unsigned frame_height) -> void
{
    sf::Vector2u texture_size = texture.getSize();
    for (unsigned y = 0; y < texture_size.y; y += frame_height)
    {
        for (unsigned x = 0; x < texture_size.x; x += frame_width)
        {
            frames.emplace_back(sf::IntRect(x, y, frame_width, frame_height));
        }
    }
}

auto CAnimation_loader::get_frame_rect(unsigned frame_index) -> sf::IntRect
{
    if (frame_index < frames.size())
    {
        return frames[frame_index];
    }
    return sf::IntRect();
}

auto CAnimation_loader::get_total_frames() -> unsigned
{
    return frames.size();
}

auto CAnimation_loader::update(sf::Sprite& sprite) -> void
{
    if (frame_timer.getElapsedTime().asSeconds() >= frame_duration)
    {
        current_frame = (current_frame + 1) % get_total_frames();
        sprite.setTextureRect(get_frame_rect(current_frame));
        frame_timer.restart();
    }
}