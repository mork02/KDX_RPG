#include "panel.h"

CPanel::CPanel(sf::RenderWindow& window_c, CInput& input_c)
    : window(window_c), input(input_c),
    title_screen(window_c, *this, input_c),
    gameplay(window_c), 
    stats_menu(window_c), pause_menu(window_c)
{
    current_menu = nullptr;
}

auto CPanel::update() -> void
{
    // clears the screen every frame
    
    title_screen.draw();
    current_menu->draw();

    /*
    switch (current_scene)
    {
    case Scene::Main_Menu:
        main_menu.draw();
        break;
    case Scene::Gameplay:
        gameplay.update();
        break;
    case Scene::Game_Over:
        break;
    }
    */

}

// Getter

auto CPanel::get_stats_menu() -> CStats_menu&
{
    return stats_menu;
}

auto CPanel::get_pause_menu() -> CPause_menu&
{
    return pause_menu;
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
    if (new_menu == nullptr) {
        std::cout << "current_menu is being set to nullptr" << std::endl;
    }
    current_menu = new_menu;
}