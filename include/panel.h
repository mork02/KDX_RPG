#pragma once
#include "SFML/Graphics.hpp"
#include "gameplay.h"
#include "title_screen.h"

enum ESceneType
{
    TITLE_SCREEN = 1,
    GAMEPLAY = 2,
    GAME_OVER = 3
};

class CPanel
{
private:
    sf::RenderWindow& mWindow;
    sf::Event& mEvent;

    ESceneType mCurrent_Scene = ESceneType::TITLE_SCREEN;
    CTitle_Screen mTitle_Screen;
    CGameplay mGameplay;

    auto event_close() -> void;
    auto event_mouse() -> void;
    auto event_keyboard() -> void;
    auto handle_window_resolution() -> void;

public:
    CPanel(sf::RenderWindow& Window, sf::Event& Event);

    auto get_gameplay() -> CGameplay&;
    auto set_scene(ESceneType new_scene) -> void;

    auto handle_events() -> void;
    auto update() -> void;
};