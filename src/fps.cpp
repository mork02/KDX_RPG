#include "fps.h"

FPS::FPS() : mFrame(0), mFps(0) {}

// Getter

auto FPS::getFPS() const -> unsigned int
{
    return mFps;
}

// Methods

auto FPS::update() -> void
{
    if (mClock.getElapsedTime().asSeconds() >= 1.f)
    {
        mFps = mFrame;
        mFrame = 0;
        mClock.restart();
    }

    ++mFrame;
}

auto FPS::show_fps(sf::RenderWindow& window) -> void
{
    update();
    std::ostringstream ss;
    ss << getFPS();

    if (getFPS() != 0)
    {
        window.setTitle(ss.str());
    }
}
