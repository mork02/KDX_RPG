#include "frame.h"

CFrame::CFrame()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close),
    panel(window, input),
    input(window)
{
    // window.setMouseCursorVisible(false);

    std::cout << "opening window..." << std::endl;
    gameloop();
    std::cout << "closing window..." << std::endl;
}

auto CFrame::gameloop() -> void
{
    window.setFramerateLimit(fps_value);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            handle_window_close_event();
            handle_keyboard_input();
            handle_mouse_click_event();
        }

        // Render and update the frame
        window.clear();
        panel.update();
        fps_class.show_fps(window);
        window.display();
    }
}

auto CFrame::handle_window_close_event() -> void
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

auto CFrame::handle_keyboard_input() -> void
{
    if (panel.get_scene() == ESceneType::Gameplay) 
    {
        // Escape | Pause menu
        if (event.type == sf::Event::KeyPressed && input.get_keyboard().isKeyPressed(input.get_keyboard().Escape)) 
        {
            if (panel.get_current_menu() == &panel.get_pause_menu()) 
            {
                panel.set_current_menu(nullptr);
            }
            else 
            {
                panel.set_current_menu(&panel.get_pause_menu());
            }
        }

        // G | Stats menu
        if (panel.get_current_menu() != &panel.get_pause_menu()) {
            if (event.type == sf::Event::KeyPressed && input.get_keyboard().isKeyPressed(input.get_keyboard().G)) 
            {
                if (panel.get_current_menu() == &panel.get_stats_menu()) 
                {
                    panel.set_current_menu(nullptr);
                }
                else 
                {
                    panel.set_current_menu(&panel.get_stats_menu());
                }
            }
        }
    }
}



auto CFrame::handle_mouse_click_event() -> void
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (panel.get_scene() == ESceneType::Title_screen) 
        {
            panel.get_title_screen().handle_click_event(panel);
        }

        if (panel.get_scene() == ESceneType::Gameplay)
        {
            // Gameplay menus
            if (panel.get_current_menu()) 
            {
                panel.get_current_menu()->handle_click_event(panel);
            }
        }
    }
}
