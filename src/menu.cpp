#include "menu.h"

Menu::Menu(sf::RenderWindow& window_c) : window(window_c), menu_text("Menu", 128, 0, 0)
{
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setScale(scale, scale);

    center_menu();

    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = menu_text.get_text().getGlobalBounds();

    float textXPos = xPos + (spriteBounds.width - textBounds.width) / 2;
    float textYPos = yPos - 16;

    menu_text.set_position(textXPos, textYPos);
}

// Getter

bool Menu::get_visable()
{
    return visable;
}

// Setter

void Menu::set_visable(bool value)
{
    visable = value;
}

// Methods

void Menu::draw_menu()
{
    if (visable)
    {
        window.draw(sprite);
        menu_text.draw_text(window);
    }
}

void Menu::center_menu()
{

    sf::Vector2u windowSize = window.getSize();

    sf::Vector2u textureSize = texture.getSize();

    xPos = (windowSize.x - (textureSize.x * sprite.getScale().x)) / 2;
    yPos = (windowSize.y - (textureSize.y * sprite.getScale().y)) / 2;

    sprite.setPosition(xPos, yPos);
}