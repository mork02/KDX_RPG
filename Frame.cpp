#include "Frame.h"

Frame::Frame() : window(sf::VideoMode(1920, 1080), "KDX RPG") { open_window(); }

void Frame::open_window()
{
    window.setFramerateLimit(60);
    FPS fps;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        fps.show_fps(window);

        panel.update(window);

        window.display();
    }
}
