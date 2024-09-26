#include "panel.h"

CPanel::CPanel(sf::RenderWindow& window_c, CInput& input_c)
    : window(window_c), input(input_c),
    title_screen(window_c, input_c),
    gameplay(window_c)
{
    pause_menu = std::make_unique<CPause_menu>(window_c);
    stats_menu = std::make_unique<CStats_menu>(window_c);
    option_menu = std::make_unique<COption_menu>(window_c);
}

auto CPanel::update() -> void
{ 
    switch (scene)
    {
    case ESceneType::Title_screen:
        title_screen.draw(*this);
        break;
    case ESceneType::Gameplay:
        gameplay.update();
        if (current_menu) { current_menu->draw(); }
        break;
    case ESceneType::Game_Over:
        break;
    }

}

// Getter

auto CPanel::get_stats_menu() -> CStats_menu&
{
    return *stats_menu;
}

auto CPanel::get_pause_menu() -> CPause_menu&
{
    return *pause_menu;
}

auto CPanel::get_options_menu() -> COption_menu&
{
    return *option_menu;
}

auto CPanel::get_title_screen() -> CTitle_Screen&
{
    return title_screen;
}

auto CPanel::get_gameplay() -> Gameplay&
{
    return gameplay;
}

auto CPanel::get_input() -> CInput&
{
    return input;
}

auto CPanel::get_scene() -> ESceneType&
{
    return scene;
}

auto CPanel::get_current_menu() -> CMenu*
{
    return current_menu;
}

// Setter

auto CPanel::set_scene(ESceneType new_scene) -> void
{
    scene = new_scene;
}

auto CPanel::set_current_menu(CMenu* new_menu) -> void {
    if (current_menu) { current_menu->set_visible(false); }

    if (!new_menu) 
    {
        current_menu = nullptr;
        return;
    }

    try {
        current_menu = new_menu;
        current_menu->set_visible(true);
    }
    catch (const std::exception& e) { std::cerr << "Error setting current menu visibility: " << e.what() << std::endl; }
}