#include "frame.h"

Frame::Frame()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close),
    panel(window, input),
    input(window, panel.get_gameplay().get_player())
{
    // window.setMouseCursorVisible(false);

    std::cout << "opening window..." << std::endl;
    gameloop();
    std::cout << "closing window..." << std::endl;
}

void Frame::gameloop()
{
    window.setFramerateLimit(fps_value);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            handle_window_close_event();
            handle_keyboard_input();
            handle_main_menu_click_event();
            handle_menu_click_event();
        }

        // Render and update the frame
        window.clear();
        panel.update();
        fps_class.show_fps(window);
        window.display();
    }
}

void Frame::handle_window_close_event()
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

void Frame::handle_keyboard_input()
{
    if (input.get_keyboard().isKeyPressed(input.get_keyboard().Escape))
    {
        if (!input.get_isKeyPressed())
        {
            panel.get_menu().set_visable(!panel.get_menu().get_visable());
            input.set_isKeyPressed(true);
        }
    }
    else
    {
        input.set_isKeyPressed(false);
    }
}

void Frame::handle_main_menu_click_event()
{
    if (panel.get_scene() == Scene::Main_Menu) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            panel.get_main_menu().check_text_click();
        }
    }
}

void Frame::handle_menu_click_event()
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        panel.get_menu().check_text_click();
    }
}
