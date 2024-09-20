#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c, Input& input_c)
    : window(window_c), input(input_c), current_scene(ESceneType::Main_Menu),
    main_menu(window_c),
    gameplay(window_c), 
    stats_menu(window_c), pause_menu(window_c)
{}

auto Panel::update() -> void
{
    // clears the screen every frame
    
    main_menu.draw();
    //current_menu->draw();

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

auto Panel::get_stats_menu() -> CStats_menu&
{
    return stats_menu;
}

auto Panel::get_main_menu() -> CTitle_Screen&
{
    return main_menu;
}

auto Panel::get_gameplay() -> Gameplay&
{
    return gameplay;
}

auto Panel::get_input() -> Input&
{
    return input;
}

auto Panel::get_scene() -> ESceneType&
{
    return current_scene;
}

// Setter

auto Panel::set_scene(ESceneType scene) -> void
{
    current_scene = scene;
}
