#pragma once
#include "SFML/Graphics.hpp"
#include "input.h"
#include "gameplay.h"
#include "title_screen.h"
#include "stats_menu.h"
#include "pause_menu.h"
#include "scene_manager.h"

class Panel
{
private:
    sf::RenderWindow& window;
    Input& input;

    ESceneType current_scene;
    CTitle_Screen main_menu;
    Gameplay gameplay;

    CStats_menu stats_menu;
    CPause_menu pause_menu;

    CMenu* current_menu = &pause_menu;

public:
    Panel(sf::RenderWindow& window, Input& input);

    // Getter
    auto get_stats_menu() -> CStats_menu&;
    auto get_main_menu() -> CTitle_Screen&;
    auto get_gameplay() -> Gameplay&;
    auto get_input() ->Input&;
    auto get_scene() -> ESceneType&;

    // Setter
    auto set_scene(ESceneType scene) -> void;

    // Methods
    auto update() -> void;
};
