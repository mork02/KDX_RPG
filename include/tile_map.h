#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    // Load the tileset and tilemap from a CSV file with a scaling factor
    bool loadFromCSV(const std::string& tileset, sf::Vector2u tileSize, const std::string& csvFile, unsigned int width, unsigned int height, sf::Vector2f scale = sf::Vector2f(1.f, 1.f));

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices; // Vertex array for tilemap
    sf::Texture m_tileset;      // Texture for tileset

    bool load(const std::string& tileset, sf::Vector2u tileSize, const std::vector<int>& tiles, unsigned int width, unsigned int height, sf::Vector2f scale); // Helper to load tilemap from vector
};
