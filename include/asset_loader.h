#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Asset_loader
{
private:
	sf::RenderWindow& window;

	std::string path;

	int x, y;
	float scale;

	sf::Texture texture;
	sf::Sprite sprite;

public:
	Asset_loader(sf::RenderWindow& window, const std::string& path, int x = 0, int y = 0, float scale = 2);

	void draw();

};

