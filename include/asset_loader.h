#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "animation_loader.h"

class CAsset_loader : public CAnimation_loader
{
private:
    sf::RenderWindow& window;
    std::string path;
    sf::Texture texture;
    sf::Sprite sprite;

    int x, y;
    float scale = 2.0f;
    bool is_animated;

    unsigned int current_frame = 0;
    sf::Clock frame_timer;
    float frame_duration = 0.1f;

    auto update() -> void; 

public:
    CAsset_loader(sf::RenderWindow& window, const std::string& path, bool isAnimated = false, int x = 0, int y = 0);

    auto get_texture() -> sf::Texture&;
    auto get_sprite() -> sf::Sprite&;
    auto get_Global_sprite_bounds() -> sf::FloatRect;
    auto get_Local_sprite_bounds() -> sf::FloatRect;

    auto set_scale(float value) -> void;
    auto center_asset() -> void;
    auto draw() -> void;
};
