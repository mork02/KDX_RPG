#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include "layers_enum.h"

class CTile_Map_Loader {
public:
    CTile_Map_Loader(const std::string& tilesetFile, int tileWidth, int tileHeight);

    auto addLayer(ELayers layerType, const std::string& filename) -> bool;
    auto draw(sf::RenderWindow& window) -> void;

private:
    auto createLayerSprites(ELayers layerType, const std::vector<std::vector<int>>& tilemap) -> void;

    sf::Texture tileset;
    std::map<ELayers, std::vector<sf::Sprite>> layers;
    int tileWidth = 32;
    int tileHeight = 32;
    int tilesPerRow;
    int tilesPerColumn;
};
