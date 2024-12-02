#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>
#include <vector>
#include <string>
#include <unordered_map>

class CTmx_Loader {
private:
    struct Tile {
        sf::Sprite sprite;
    };

    struct Layer {
        std::vector<Tile> tiles;
    };

    std::vector<sf::Texture> tilesetTextures;
    std::unordered_map<int, sf::Sprite> tileSprites;
    std::vector<Layer> layers;

    int mapWidth, mapHeight;
    int tileWidth, tileHeight;
    float scale = 3;

public:
    CTmx_Loader();
    bool LoadFromFile(const std::string& path);
    void render(sf::RenderWindow& window);
};

