#include "../include/fps.h"

FPS::FPS() : mFrame(0), mFps(0) {}

// Getter

const unsigned int FPS::getFPS() const { return mFps; }

//

// Methods

void FPS::update()
{
	if (mClock.getElapsedTime().asSeconds() >= 1.f)
	{
		mFps = mFrame;
		mFrame = 0;
		mClock.restart();
	}

	++mFrame;
}

void FPS::show_fps(sf::RenderWindow &window)
{
	update();
	std::ostringstream ss;
	ss << getFPS();
	if (getFPS() != 0)
	{
		window.setTitle(ss.str());
	};
}
