#include "tmx_loader.h"
#include <sstream>
#include <iostream>
#include <filesystem>

CTmx_Loader::CTmx_Loader() : mapWidth(0), mapHeight(0), tileWidth(0), tileHeight(0) {}

bool CTmx_Loader::LoadFromFile(const std::string& path) {
    using namespace tinyxml2;
    XMLDocument doc;

    if (doc.LoadFile(path.c_str()) != XML_SUCCESS) {
        std::cerr << "Failed to load TMX file: " << path << "\n";
        return false;
    }

    // Parse <map>
    XMLElement* mapElement = doc.FirstChildElement("map");
    if (!mapElement) {
        std::cerr << "Invalid TMX file: Missing <map> element\n";
        return false;
    }
    mapElement->QueryIntAttribute("width", &mapWidth);
    mapElement->QueryIntAttribute("height", &mapHeight);
    mapElement->QueryIntAttribute("tilewidth", &tileWidth);
    mapElement->QueryIntAttribute("tileheight", &tileHeight);

    // Parse <tileset>
    for (XMLElement* tilesetElement = mapElement->FirstChildElement("tileset");
        tilesetElement; tilesetElement = tilesetElement->NextSiblingElement("tileset")) {
        const char* sourceAttr = tilesetElement->Attribute("source");
        int firstGid;
        tilesetElement->QueryIntAttribute("firstgid", &firstGid);

        if (sourceAttr) {
            std::string basePath = std::filesystem::path(path).parent_path().string() + "/";
            std::string tilesetPath = basePath + sourceAttr;

            XMLDocument tilesetDoc;
            if (tilesetDoc.LoadFile(tilesetPath.c_str()) != XML_SUCCESS) {
                std::cerr << "Failed to load TSX file: " << tilesetPath << "\n";
                return false;
            }

            XMLElement* tilesetRoot = tilesetDoc.FirstChildElement("tileset");
            if (!tilesetRoot) {
                std::cerr << "Invalid TSX file structure: " << tilesetPath << "\n";
                return false;
            }

            XMLElement* imageElement = tilesetRoot->FirstChildElement("image");
            if (!imageElement) {
                std::cerr << "Error: <image> tag not found in TSX file." << tilesetPath << "\n";
                return false;
            }

            const char* imageSource = imageElement->Attribute("source");
            if (!imageSource) {
                std::cerr << "Error: Missing 'source' attribute in <image> tag of TSX file." << tilesetPath << "\n";
                return false;
            }

            std::string imagePath = basePath + imageSource;

            tilesetTextures.emplace_back(); 
            sf::Texture& texture = tilesetTextures.back(); 
            if (!texture.loadFromFile(imagePath)) {
                std::cerr << "Failed to load tileset image: " << imagePath << "\n";
                return false;
            }

            // Create tile sprites
            int tileCount = (texture.getSize().x / tileWidth) * (texture.getSize().y / tileHeight);
            for (int i = 0; i < tileCount; ++i) {
                sf::Sprite sprite;
                sprite.setTexture(texture);
                int tx = (i * tileWidth) % texture.getSize().x;
                int ty = (i * tileWidth) / texture.getSize().x * tileHeight;
                sprite.scale(scale, scale);
                sprite.setTextureRect(sf::IntRect(tx, ty, tileWidth, tileHeight));
                tileSprites[firstGid + i] = sprite;
            }
        }
        else {
            std::cerr << "Error: Inline tilesets are not supported in this example.\n";
            return false;
        }
    }

    // Parse <layer>
    for (XMLElement* layerElement = mapElement->FirstChildElement("layer");
        layerElement; layerElement = layerElement->NextSiblingElement("layer")) {
        Layer layer;
        XMLElement* dataElement = layerElement->FirstChildElement("data");
        if (!dataElement) {
            std::cerr << "Error: Missing <data> element in <layer>.\n";
            return false;
        }

        const char* csvData = dataElement->GetText();
        if (!csvData) {
            std::cerr << "Error: Missing CSV data in <data> element.\n";
            return false;
        }

        std::stringstream ss(csvData);
        std::string tileIdStr;

        int row = 0, col = 0;
        while (std::getline(ss, tileIdStr, ',')) {
            int tileId = std::stoi(tileIdStr);
            if (tileId > 0) {
                auto it = tileSprites.find(tileId);
                if (it != tileSprites.end()) {
                    sf::Sprite sprite = it->second;
                    sprite.setPosition(col * tileWidth * scale, row * tileHeight * scale);

                    Tile tile;
                    tile.sprite = sprite;
                    layer.tiles.push_back(tile);
                }
            }
            if (++col >= mapWidth) {
                col = 0;
                ++row;
            }
        }

        layers.push_back(layer);
    }

    return true;
}

void CTmx_Loader::render(sf::RenderWindow& window) {
    for (const auto& layer : layers) {
        for (const auto& tile : layer.tiles) {
            window.draw(tile.sprite);
        }
    }
}
