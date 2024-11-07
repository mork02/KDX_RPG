#include "frame.h"

CFrame::CFrame()
    : Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close),
    Panel(Window)
{
    Window.setFramerateLimit(FPS_Value);
    Window.setKeyRepeatEnabled(false);
    gameloop();
}

auto CFrame::gameloop() -> void
{
    while (Window.isOpen())
    {
        while (Window.pollEvent(Event))
        {
            Panel.handle_events(Event);
        }

        Window.clear(sf::Color::Red);
        Panel.update(Clock.restart().asSeconds());  // param: delta time
        FPS.show_fps(Window);
        Window.display();
    }
}
