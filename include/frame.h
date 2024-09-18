#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fps.h"
#include "panel.h"
#include "input.h"

class Frame
{
private:
    const unsigned WINDOW_WIDTH = 1920;
    const unsigned WINDOW_HEIGHT = 1080;
    const std::string WINDOW_TITLE = "KDX_RPG";
    const int fps_value = 60;

    sf::RenderWindow window;
    sf::Event event;
    Panel panel;
    Input input;
    FPS fps_class;

    auto gameloop() -> void;
    auto handle_window_close_event() -> void;
    auto handle_keyboard_input() -> void;
    auto handle_main_menu_click_event() -> void;
    auto handle_menu_click_event() -> void;

public:
    Frame();
};
