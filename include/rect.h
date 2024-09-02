#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Rect
{
private:
    sf::Color blue = sf::Color::Blue;

    float dirX = 0.f, dirY = 0.f;
    sf::RectangleShape rect; 

public:
    Rect(); 
    void draw_rect(sf::RenderWindow& window); 
};
