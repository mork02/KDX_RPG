#include "SFML/Graphics.hpp"
#include <sstream>

class CFPS
{
public:
    CFPS();

    auto getFPS() const -> unsigned int;

private:
    unsigned int mFrame;
    unsigned int mFps;
    sf::Clock mClock;

public:
    auto update() -> void;
    auto show_fps(sf::RenderWindow& window) -> void;
};
