#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"
#include "input.h"

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
    CInput mInput;
    CFPS mFPS;

    auto gameloop() -> void;
    auto handle_input_events() -> void;
    auto handle_title_screen_input() -> void;
    auto handle_gameplay_input() -> void;
    auto toggle_pause_menu() -> void;
    auto toggle_stats_menu() -> void;
         
public:
    CFrame();
};
