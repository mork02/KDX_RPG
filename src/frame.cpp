#include "frame.h"

CFrame::CFrame()
    : Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close),
    Panel(Window, Event)
{
    Window.setFramerateLimit(FPS_Value);
    gameloop();
}

auto CFrame::gameloop() -> void
{
    while (Window.isOpen())
    {
        while (Window.pollEvent(Event))
        {
            Panel.handle_events();
        }

        Window.clear(sf::Color::Red);
        Panel.update();
        FPS.show_fps(Window);
        Window.display();
    }
}
