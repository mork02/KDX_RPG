#include "frame.h"

Frame::Frame() : window(sf::VideoMode(WINDOW_WIDTH, WiNDOW_HEIGHT), WINDOW_TITLE) 
{ 
    std::cout << "Trying to open window..." << std::endl;
    gameloop(); 
}

void Frame::gameloop()
{
    window.setFramerateLimit(fps_value);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        fps_class.show_fps(window);

        panel.update(window);

        window.display();
    }
}
