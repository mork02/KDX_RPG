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

    ESceneType mCurrent_Scene = ESceneType::TITLE_SCREEN;
    CTitle_Screen mTitle_Screen;
    CGameplay mGameplay;

    auto event_close(sf::Event& Event) -> void;
    auto event_mouse(sf::Event& Event) -> void;
    auto handle_window_resolution() -> void;

public:
    CPanel(sf::RenderWindow& Window);

    auto get_gameplay() -> CGameplay&;
    auto set_scene(ESceneType new_scene) -> void;

    auto handle_events(sf::Event& Event) -> void;
    auto update(float delta_time) -> void;
};