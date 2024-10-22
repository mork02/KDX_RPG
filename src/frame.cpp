#include "frame.h"

CFrame::CFrame()
    : mWindow(sf::VideoMode(mWINDOW_WIDTH, mWINDOW_HEIGHT), mWINDOW_TITLE, sf::Style::Close),
    mPanel(mWindow, mInput)
{
    // window.setMouseCursorVisible(false);
    mWindow.setFramerateLimit(mFPS_Value);
    gameloop();
}

auto CFrame::gameloop() -> void
{
    while (mWindow.isOpen())
    {
        while (mWindow.pollEvent(mEvent))
        {
            event_window_close();
            event_menu_keyboard_input();
            event_menu_mouse_input();
            event_gameplay_mouse_input();
        }

        mWindow.clear(sf::Color::Red);
        mPanel.update();
        mFPS.show_fps(mWindow);
        mWindow.display();
    }
}

auto CFrame::event_window_close() -> void
{
    if (mEvent.type == sf::Event::Closed)
    {
        mWindow.close();
    }
}

auto CFrame::event_menu_keyboard_input() -> void
{
    if (mPanel.get_scene() == ESceneType::Gameplay) 
    {
        // Escape | Pause menu
        if (mEvent.type == sf::Event::KeyPressed && mInput.get_keyboard().isKeyPressed(mInput.get_keyboard().Escape)) 
        {
            if (mPanel.get_current_menu() == &mPanel.get_pause_menu()) 
            {
                mPanel.set_current_menu(nullptr);
            }
            else 
            {
                mPanel.set_current_menu(&mPanel.get_pause_menu());
            }
        }

        // G | Stats menu
        if (mPanel.get_current_menu() != &mPanel.get_pause_menu()) {
            if (mEvent.type == sf::Event::KeyPressed && mInput.get_keyboard().isKeyPressed(mInput.get_keyboard().G)) 
            {
                if (mPanel.get_current_menu() == &mPanel.get_stats_menu()) 
                {
                    mPanel.set_current_menu(nullptr);
                }
                else 
                {
                    mPanel.set_current_menu(&mPanel.get_stats_menu());
                }
            }
        }
    }
}

auto CFrame::event_menu_mouse_input() -> void
{
    if (mEvent.type == sf::Event::MouseButtonPressed && mEvent.mouseButton.button == sf::Mouse::Left)
    {
        if (mPanel.get_scene() == ESceneType::Title_screen) 
        {
            mPanel.get_title_screen().handle_click_event(mPanel, mInput);
        }

        if (mPanel.get_scene() == ESceneType::Gameplay)
        {
            // Gameplay menus
            if (mPanel.get_current_menu()) 
            {
                mPanel.get_current_menu()->handle_click_event(mPanel);
            }
        }
    }
}

auto CFrame::event_gameplay_mouse_input() -> void
{
    if (mPanel.get_scene() == ESceneType::Gameplay)
    {
        mPanel.get_gameplay().handle_mouse_input();
    }
}