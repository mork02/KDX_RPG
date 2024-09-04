#include "frame.h"

Frame::Frame() 
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), panel(window), 
    mouse(panel.get_player()), keyboard(panel.get_player())
{ 
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
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (mouse.get_mouse().isButtonPressed(sf::Mouse::Left))
            {
                mouse.get_player().get_stats().set_hp(-1);
            }
        }
        window.clear();
        fps_class.show_fps(window);

        panel.update();

        window.display();
    }
}
