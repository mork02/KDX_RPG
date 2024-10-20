#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"
#include "input.h"

class CFrame
{
private:
    const unsigned mWINDOW_WIDTH = 1920;
    const unsigned mWINDOW_HEIGHT = 1080;
    const std::string mWINDOW_TITLE = "KDX_RPG";
    const int mFPS_Value = 60;

    sf::RenderWindow mWindow;
    sf::Event mEvent;
    CPanel mPanel;
    CInput mInput;
    CFPS mFPS_class;

    auto gameloop() -> void;
    auto handle_window_close_event() -> void;
    auto handle_menu_keyboard_input() -> void;
    auto handle_menu_mouse_input() -> void;
    auto handle_gameplay_mouse_input() -> void;

public:
    CFrame();
};
