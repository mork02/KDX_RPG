#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"

class CFrame
{
private:
    unsigned mWINDOW_WIDTH = 1920;
    unsigned mWINDOW_HEIGHT = 1080;
    const std::string mWINDOW_TITLE = "KDX_RPG";
    const int mFPS_Value = 60;

    sf::RenderWindow mWindow;
    sf::Event mEvent;
    CPanel mPanel;
    CFPS mFPS;

    auto gameloop() -> void;
public:
    CFrame();
};
