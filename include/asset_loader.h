#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "animation_loader.h"
#include "text.h"

class CAsset_loader : private CAnimation_loader
{
private:
    sf::RenderWindow& mWindow;
    std::string mPath;
    sf::Texture mTexture;
    sf::Sprite mSprite;

    float mX, mY;
    unsigned mFrame_Width, mFrame_Height;
    float mScale = 4.0f;
    bool mIs_Animated;

    auto update_Coordinates() -> void;

public:
    CAsset_loader(sf::RenderWindow& Window, const std::string& Path, bool Is_Animated = false, unsigned Row = 0, unsigned Frame_Length = 0, unsigned Frame_Width = 32, unsigned Frame_Height = 32);

    auto get_Texture()  -> sf::Texture&;
    auto get_Sprite()   -> sf::Sprite&;
    auto get_Global_sprite_bounds() -> sf::FloatRect;

    auto set_scale(float value) -> void;
    auto set_Position(float x, float y) -> void;

    auto center_asset() -> void;
    auto draw() -> void;
};
