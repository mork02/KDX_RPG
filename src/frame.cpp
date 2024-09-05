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

    bool isKeyPressed = false;  
    bool isMousePressed = false;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (mouse.get_mouse().isButtonPressed(mouse.get_mouse().Left))
            {
                if (!isMousePressed)
                {
                    mouse.get_player().get_stats().set_hp(-1);  
                    isMousePressed = true;  
                }
            }
            else { isMousePressed = false; }

            if (keyboard.get_keyboard().isKeyPressed(keyboard.get_keyboard().I))
            {
                if (!isKeyPressed) 
                {

                    if (panel.get_menu().get_visable())
                    {
                        panel.get_menu().set_visable(false);
                    }
                    else
                    {
                        panel.get_menu().set_visable(true);
                    }
                    isKeyPressed = true;  
                }
            }
            else { isKeyPressed = false; }
        }

        window.clear();
        fps_class.show_fps(window);
        panel.update();
        window.display();
    }
}
