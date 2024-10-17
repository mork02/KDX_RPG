#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include "layers_enum.h"

class CTile_Map_Loader {
private:
    auto createLayerSprites(ELayers layerType, const std::vector<std::vector<int>>& tilemap) -> void;

    sf::Texture mTile_Textures;
    std::map<ELayers, std::vector<sf::Sprite>> mLayers;
    int mTile_Width = 32;
    int mTile_Height = 32;
    float mScale = 2.2f;
    int mTiles_Per_Row;
    int mTiles_Per_Column;

public:
    CTile_Map_Loader(const std::string& Tileset_File, int Tiles_Row, int Tiles_Column);

    auto addLayer(ELayers layerType, const std::string& filename) -> bool;
    auto draw(sf::RenderWindow& window) -> void;

};
