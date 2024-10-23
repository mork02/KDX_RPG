#include "frame.h"

CFrame::CFrame()
    : mWindow(sf::VideoMode(mWINDOW_WIDTH, mWINDOW_HEIGHT), mWINDOW_TITLE, sf::Style::Close),
    mPanel(mWindow, mInput)
{
    mWindow.setFramerateLimit(mFPS_Value);
    gameloop();
}

auto CFrame::gameloop() -> void
{
    while (mWindow.isOpen())
    {
        while (mWindow.pollEvent(mEvent))
        {
            handle_input_events();
        }

        mWindow.clear(sf::Color::Red);
        mPanel.update();
        mFPS.show_fps(mWindow);
        mWindow.display();
    }
}

auto CFrame::handle_input_events() -> void
{
    if (mEvent.type == sf::Event::Closed)
    {
        mWindow.close();
    }

    switch (mPanel.get_scene())
    {
    case ESceneType::Title_screen:
        handle_title_screen_input();
        break;
    case ESceneType::Gameplay:
        handle_gameplay_input();
        break;
    default:
        break;
    }
}

auto CFrame::handle_title_screen_input() -> void
{
    if (mEvent.type == sf::Event::MouseButtonPressed && mEvent.mouseButton.button == sf::Mouse::Left)
    {
        mPanel.get_title_screen().handle_click_event(mPanel, mInput);
    }
}

auto CFrame::handle_gameplay_input() -> void
{
    if (mEvent.type == sf::Event::KeyPressed)
    {
        if (mInput.get_keyboard().isKeyPressed(mInput.get_keyboard().Escape))
        {
            toggle_pause_menu();
        }
        else if (mInput.get_keyboard().isKeyPressed(mInput.get_keyboard().G))
        {
            toggle_stats_menu();
        }
    }

    if (mEvent.type == sf::Event::MouseButtonPressed && mEvent.mouseButton.button == sf::Mouse::Left)
    {
        if (mPanel.get_current_menu())
        {
            mPanel.get_current_menu()->handle_click_event(mPanel);
        }
        else
        {
            mPanel.get_gameplay().handle_mouse_input();
        }
    }
}

auto CFrame::toggle_pause_menu() -> void
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

auto CFrame::toggle_stats_menu() -> void
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