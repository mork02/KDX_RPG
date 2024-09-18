#include "panel.h"

Panel::Panel(sf::RenderWindow& window_c, Input& input_c)
    : window(window_c), input(input_c), current_scene(Scene::Main_Menu),
    main_menu(window_c, *this, input_c), menu(window_c, *this, input_c),
    gameplay(window_c), stats_menu(window_c, *this, input_c)
{
}

auto Panel::update() -> void
{
    // clears the screen every frame
    window.clear();

    switch (current_scene)
    {
    case Scene::Main_Menu:
        main_menu.draw();
        break;
    case Scene::Option_Menu:
        break;
    case Scene::Game_Over:
        break;
    case Scene::Gameplay:
        gameplay.update();
        stats_menu.draw();
        menu.draw();
        break;
    }
}

// Getter

auto Panel::get_menu() -> Menu&
{
    return menu;
}

auto Panel::get_stats_menu() -> Stats_menu&
{
    return stats_menu;
}

auto Panel::get_main_menu() -> Main_menu&
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

auto Panel::get_scene() -> Scene&
{
    return current_scene;
}

// Setter

auto Panel::set_scene(Scene scene) -> void
{
    current_scene = scene;
}
