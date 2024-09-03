#include "asset_loader.h"

Asset_loader::Asset_loader(std::string path_c, int x_c, int y_c, int speed_c, int width_c, int height_c)
	: path(path_c), x(x_c), y(y_c), speed(speed_c), width(width_c), height(height_c),
	image()
{}