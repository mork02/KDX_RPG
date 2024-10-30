#include "SFML/Graphics.hpp"
#include "entity.h"

#pragma once
class CCamera
{
private:
    sf::View mCamera;
    sf::RenderWindow& mWindow;
    float mMoveSpeed;
    float mCamera_Zoom = 1.05f;

public:
    CCamera(sf::RenderWindow& Window);

    auto get_camera() -> sf::View&;

    auto update(CEntity* entity) -> void;
};
