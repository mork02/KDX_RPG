#include "main_menu.h"

Main_menu::Main_menu(sf::RenderWindow& window_c, Mouse_controller& mouse_ctrl_c)
    : window(window_c), mouse_ctrl(mouse_ctrl_c)
{
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setScale((float)scale, (float)scale);

    center_menu();
}

void Main_menu::center_menu()
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();

    xPos = (windowSize.x - (textureSize.x * sprite.getScale().x)) / 2;
    yPos = (windowSize.y - (textureSize.y * sprite.getScale().y)) / 2;

    sprite.setPosition(xPos, yPos);
}