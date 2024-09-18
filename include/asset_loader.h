#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Asset_loader
{
private:
    sf::RenderWindow& window;
    std::string path;

    sf::Texture texture;
    sf::Sprite sprite;

    int x, y;
    float scale;

public:
    Asset_loader(sf::RenderWindow& window, const std::string& path, int x = 0, int y = 0, int width = 32, int height = 32, float scale = 4);

    // Getter methods
    auto get_texture() -> sf::Texture&;
    auto get_sprite() -> sf::Sprite&;
};
