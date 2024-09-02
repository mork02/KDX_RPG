#include "rect.h"

Rect::Rect() : rect(sf::Vector2f(50.f, 50.f))
{
    rect.setPosition(dirX, dirY);
    rect.setFillColor(blue);
}


void Rect::draw_rect(sf::RenderWindow& window) 
{
    window.draw(rect);
    rect.setPosition(dirX, dirY);
    dirX++;
}
