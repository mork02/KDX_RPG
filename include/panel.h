#pragma once
#include "SFML/Graphics.hpp"
#include "gameplay.h"
#include "title_screen.h"
#include "pause_menu.h"
#include "option_menu.h"
#include "stats_menu.h"
#include "scene_enum.h"

class CPanel
{
private:
    sf::RenderWindow& mWindow;
    sf::Event& mEvent;

    ESceneType mCurrent_Scene = ESceneType::Title_screen;
    CTitle_Screen mTitle_Screen;
    Gameplay mGameplay;

    std::unique_ptr<CPause_menu> mPause_Menu;
    std::unique_ptr<COption_menu> mOption_Menu;
    std::unique_ptr<CStats_menu> mStats_Menu;

    CMenu* mCurrent_Menu = nullptr;

    auto event_close() -> void;
    auto event_mouse() -> void;
    auto event_keyboard() -> void;
    auto handle_window_resolution() -> void;

public:
    CPanel(sf::RenderWindow& Window, sf::Event& Event);

    auto get_option_menu() -> COption_menu&;
    auto get_pause_menu() -> CPause_menu&;
    auto get_stats_menu() -> CStats_menu&;

    auto set_scene(ESceneType new_scene) -> void;
    auto set_current_menu(CMenu* new_menu) -> void;

    auto handle_events() -> void;
    auto update() -> void;
};