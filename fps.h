#include "SFML/Graphics.hpp"
#include <sstream>

class FPS
{
public:
	FPS();

	const unsigned int getFPS() const;

private:
	unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;

public:
	void update();
	void show_fps(sf::RenderWindow &window);
};