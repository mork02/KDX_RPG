#include "frame.h"

Frame::Frame() 
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close), panel(window, mouse_ctrl, keyboard_ctrl), 
    mouse_ctrl(panel.get_player(), window), keyboard_ctrl(panel.get_player())
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
            if (mouse_ctrl.is_mouse_button_pressed(sf::Mouse::Left))
            {
                if (!isMousePressed)
                {
                    mouse_ctrl.get_player().get_stats().set_hp(-1);
                    isMousePressed = true;  
                }
            }
            else { isMousePressed = false; }

            if (keyboard_ctrl.get_keyboard().isKeyPressed(keyboard_ctrl.get_keyboard().Escape))
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
