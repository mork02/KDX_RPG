#pragma once
#include "SFML/Graphics.hpp"
#include "input.h"
#include "gameplay.h"
#include "title_screen.h"
#include "stats_menu.h"
#include "pause_menu.h"
#include "scene_manager.h"

class CPanel
{
private:
    sf::RenderWindow& window;
    CInput& input;

    ESceneType scene = ESceneType::Title_screen;
    CTitle_Screen title_screen;
    Gameplay gameplay;

    CStats_menu stats_menu;
    CPause_menu pause_menu;

    // FIX -> SHOULD NOT BE ON PAUSE MENU FOR FRAME KEYBOARD EVENTS | frame.cpp -> line 54
    CMenu* current_menu;

public:
    CPanel(sf::RenderWindow& window, CInput& input);

    // Getter
    auto get_scene() -> ESceneType&;
    auto get_title_screen() -> CTitle_Screen&;
    auto get_gameplay() -> Gameplay&;

    auto get_current_menu() -> CMenu*;
    auto get_stats_menu() -> CStats_menu&;
    auto get_pause_menu() -> CPause_menu&;

    auto get_input() ->CInput&;

    // Setter
    auto set_scene(ESceneType new_scene) -> void;
    auto set_current_menu(CMenu* new_menu) -> void;

    // Methods
    auto update() -> void;
};