#include "tile_map_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

CTile_Map_Loader::CTile_Map_Loader(const std::string& Tileset_File, int Tiles_Row, int Tiles_Column)
    : mTiles_Per_Row(mTiles_Per_Row), mTiles_Per_Column(mTiles_Per_Column) 
{
    if (!mTile_Textures.loadFromFile(Tileset_File))
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

            int tilesetX = (tileType) % mTiles_Per_Row;
            int tilesetY = (tileType) / mTiles_Per_Row;

            sf::Sprite tile(mTile_Textures);
            tile.setTextureRect(sf::IntRect(
                tilesetX * mTile_Width,
                tilesetY * mTile_Height,
                mTile_Width,
                mTile_Height
            ));
            tile.setScale(mScale, mScale);
            tile.setPosition((float) x * mTile_Width * mScale, (float) y * mTile_Height * mScale);
            layerSprites.push_back(tile);
        }
    }
    mLayers[layerType] = layerSprites;
}

auto CTile_Map_Loader::draw(sf::RenderWindow& window) -> void 
{
    for (const auto& layer : mLayers) 
    {
        for (const auto& tile : layer.second) 
        {
            window.draw(tile);
        }
    }
}