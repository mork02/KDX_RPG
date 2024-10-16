#include "tile_map_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

CTile_Map_Loader::CTile_Map_Loader(const std::string& ctilesetFile_image, int ctiles_Row, int ctiles_Column)
    : tilesPerRow(tilesPerRow), tilesPerColumn(tilesPerColumn) 
{
    if (!tile_textures.loadFromFile(ctilesetFile_image))
    {
        std::cerr << "Error: Cant load Image." << std::endl;
    }
}

auto CTile_Map_Loader::addLayer(ELayers layerType, const std::string& filename_csv) -> bool 
{
    std::ifstream file(filename_csv);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Cant load csv." << std::endl;
        return false;
    }

    std::vector<std::vector<int>> tilemap;
    std::string line;

    while (std::getline(file, line)) 
    {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string item;

        while (std::getline(ss, item, ',')) 
        {
            row.push_back(std::stoi(item));
        }

        tilemap.push_back(row);
    }

    file.close();

    createLayerSprites(layerType, tilemap);
    return true;
}

auto CTile_Map_Loader::createLayerSprites(ELayers layerType, const std::vector<std::vector<int>>& tilemap) -> void 
{
    std::vector<sf::Sprite> layerSprites;

    for (std::size_t y = 0; y < tilemap.size(); ++y)
    {
        for (std::size_t x = 0; x < tilemap[y].size(); ++x)
        {
            int tileType = tilemap[y][x];

            if (tileType == -1) continue;

            int tilesetX = (tileType) % tilesPerRow;
            int tilesetY = (tileType) / tilesPerRow;

            sf::Sprite tile(tile_textures);
            tile.setTextureRect(sf::IntRect(
                tilesetX * tileWidth,
                tilesetY * tileHeight,
                tileWidth,
                tileHeight
            ));
            tile.setScale(scale, scale);
            tile.setPosition((float) x * tileWidth * scale, (float) y * tileHeight * scale);
            layerSprites.push_back(tile);
        }
    }
    layers[layerType] = layerSprites;
}

auto CTile_Map_Loader::draw(sf::RenderWindow& window) -> void 
{
    for (const auto& layer : layers) 
    {
        for (const auto& tile : layer.second) 
        {
            window.draw(tile);
        }
    }
}