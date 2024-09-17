#include "tile_map.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool TileMap::loadFromCSV(const std::string& tileset, sf::Vector2u tileSize, const std::string& csvFile, unsigned int width, unsigned int height, sf::Vector2f scale) {
    // Open the CSV file
    std::ifstream file(csvFile);
    if (!file.is_open()) {
        std::cerr << "Failed to open the CSV file: " << csvFile << std::endl;
        return false;
    }

    // Vector to store tile numbers
    std::vector<int> tiles;
    std::string line, value;

    // Parse the CSV file
    while (std::getline(file, line)) {
        std::stringstream sstream(line);
        while (std::getline(sstream, value, ',')) {
            tiles.push_back(std::stoi(value));  // Convert string to integer and store
        }
    }

    file.close();

    // Ensure the tilemap is correctly sized
    if (tiles.size() != width * height) {
        std::cerr << "CSV file size does not match expected map dimensions." << std::endl;
        return false;
    }

    // Load the tilemap using the parsed tile data with the scale
    return load(tileset, tileSize, tiles, width, height, scale);
}

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const std::vector<int>& tiles, unsigned int width, unsigned int height, sf::Vector2f scale) {
    // Load the tileset texture
    if (!m_tileset.loadFromFile(tileset)) {
        return false;
    }

    // Resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // Populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            // Get the current tile number
            int tileNumber = tiles[i + j * width];

            // Find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // Define the 4 corners of the tile, adjusted for scale
            quad[0].position = sf::Vector2f(i * tileSize.x * scale.x, j * tileSize.y * scale.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x * scale.x, j * tileSize.y * scale.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x * scale.x, (j + 1) * tileSize.y * scale.y);
            quad[3].position = sf::Vector2f(i * tileSize.x * scale.x, (j + 1) * tileSize.y * scale.y);

            // Define the 4 texture coordinates (no scaling here, just map as normal)
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply the transform
    states.transform *= getTransform();

    // Apply the tileset texture
    states.texture = &m_tileset;

    // Draw the vertex array
    target.draw(m_vertices, states);
}