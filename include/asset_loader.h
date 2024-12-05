#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "animation_loader.h"
#include "text.h"

class CAsset_loader : public CAnimation_loader
{
private:
    sf::RenderWindow& mWindow;
    sf::Texture mTexture;
    sf::Sprite mSprite;

    bool mIs_Animated;
    unsigned mCurrent_Row = 0;
    unsigned mCurrent_Frame_Length = 0;
    sf::Vector2f mScale;

    bool mDebug = false;
    CText mD_Coordinates;

public:
    CAsset_loader(sf::RenderWindow& Window);

    auto init_asset(std::string Path) -> void;
    auto init_animation(std::string Path, unsigned Row = 1, unsigned Frame_Length = 1, unsigned Frame_Width = 32, unsigned Frame_Height = 32) -> void;

    auto get_Texture()  -> sf::Texture&;
    auto get_Sprite()   -> sf::Sprite&;
    auto get_Scale() -> sf::Vector2f&;

    auto set_Position(float x, float y) -> void;
    auto set_is_Animated(bool value) -> void;
    auto set_animation_param(unsigned Row, unsigned Frame_Length, unsigned Frame_Width = 32, unsigned Frame_Height = 32) -> void;
    auto set_direction(bool value) -> void;
    auto set_origin_center() -> void;

    auto center_asset() -> void;
    auto update() -> void;
    auto render() -> void;
};