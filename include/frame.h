#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"

class CFrame
{
private:
    unsigned WINDOW_WIDTH = 1920;
    unsigned WINDOW_HEIGHT = 1080;
    const std::string WINDOW_TITLE = "KDX_RPG";
    const int FPS_Value = 60;

    sf::RenderWindow Window;
    sf::Event Event;
    CPanel Panel;
    CFPS FPS;

    auto gameloop() -> void;
public:
    CFrame();
};
