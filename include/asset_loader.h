#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "animation_loader.h"

class CAsset_loader : public CAnimation_loader
{
private:
    sf::RenderWindow& mWindow;
    std::string mPath;
    sf::Texture mTexture;
    sf::Sprite mSprite;

    int mX, mY;
    float mScale = 2.0f;
    bool mIs_Animated;

public:
    CAsset_loader(sf::RenderWindow& Window, const std::string& Path, bool Is_Animated = false, int X = 0, int Y = 0);

    auto get_texture()  -> sf::Texture&;
    auto get_sprite()   -> sf::Sprite&;
    auto get_Global_sprite_bounds() -> sf::FloatRect;
    auto get_Local_sprite_bounds()  -> sf::FloatRect;

    auto set_scale(float value) -> void;
    auto center_asset() -> void;
    auto draw() -> void;

    auto set_Position(float x, float y) -> void;
};
