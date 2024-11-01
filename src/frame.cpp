#include "frame.h"

CFrame::CFrame()
    : mWindow(sf::VideoMode(mWINDOW_WIDTH, mWINDOW_HEIGHT), mWINDOW_TITLE, sf::Style::Close),
    mPanel(mWindow, mEvent)
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
            mPanel.handle_events();
        }

        mWindow.clear(sf::Color::Red);
        mPanel.update();
        mFPS.show_fps(mWindow);
        mWindow.display();
    }
}
