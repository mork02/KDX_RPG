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

auto Frame::gameloop() -> void
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

auto Frame::handle_window_close_event() -> void
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

auto Frame::handle_keyboard_input() -> void
{

}

auto Frame::handle_main_menu_click_event() -> void
{
    if (panel.get_scene() == Scene::Main_Menu) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            panel.get_main_menu().check_text_click();
        }
    }
}

auto Frame::handle_menu_click_event() -> void
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
       
    }
}
