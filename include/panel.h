#pragma once
#include "SFML/Graphics.hpp"
#include "input.h"
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
    CInput& mInput;

    ESceneType mScene = ESceneType::Title_screen;
    CTitle_Screen mTitle_Screen;
    Gameplay mGameplay;

    std::unique_ptr<CPause_menu> mPause_Menu;
    std::unique_ptr<COption_menu> mOption_Menu;
    std::unique_ptr<CStats_menu> mStats_Menu;

    CMenu* mCurrent_Menu = nullptr;

public:
    CPanel(sf::RenderWindow& Window, CInput& Input);

    auto get_scene() -> ESceneType&;
    auto get_title_screen() -> CTitle_Screen&;
    auto get_gameplay() -> Gameplay&;

    auto get_current_menu() -> CMenu*;
    auto get_pause_menu() -> CPause_menu&;
    auto get_options_menu() -> COption_menu&;
    auto get_stats_menu() -> CStats_menu&;

    auto get_input() ->CInput&;

    auto set_scene(ESceneType new_scene) -> void;
    auto set_current_menu(CMenu* new_menu) -> void;

    auto update() -> void;
};