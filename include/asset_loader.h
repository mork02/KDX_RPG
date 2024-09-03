#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Asset_loader
{
private:
	std::string path;
	int x, y;
	int speed;
	int width, height;
	
	sf::Image image;

public:
	Asset_loader(std::string path, int x, int y, int speed = 10, int width = 32, int height = 32);

};

