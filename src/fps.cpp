#include "fps.h"

CFPS::CFPS() : mFrame(0), mFps(0) {}

// Getter

auto CFPS::getFPS() const -> unsigned int
{
    return mFps;
}

// Methods

auto CFPS::update() -> void
{
    if (mClock.getElapsedTime().asSeconds() >= 1.f)
    {
        mFps = mFrame;
        mFrame = 0;
        mClock.restart();
    }

    ++mFrame;
}

auto CFPS::show_fps(sf::RenderWindow& window) -> void
{
    update();
    std::ostringstream ss;
    ss << getFPS();

    if (getFPS() != 0)
    {
        window.setTitle(ss.str());
    }
}
