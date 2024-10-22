#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"
#include "input.h"

class CFrame
{
private:
    unsigned mWINDOW_WIDTH = 1080;
    unsigned mWINDOW_HEIGHT = 720;
    const std::string mWINDOW_TITLE = "KDX_RPG";
    const int mFPS_Value = 60;

    sf::RenderWindow mWindow;
    sf::Event mEvent;
    CPanel mPanel;
    CInput mInput;
    CFPS mFPS;

    auto gameloop() -> void;
    auto event_window_close() -> void;
    auto event_menu_keyboard_input() -> void;
    auto event_menu_mouse_input() -> void;
    auto event_gameplay_mouse_input() -> void;

public:
    CFrame();
};
