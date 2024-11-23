#include "debug_manager.h"
#include "entity.h"
#include "text.h"
#include "enums.h"
#include <iostream>

auto CDebugManager::Hitbox(sf::RenderWindow& Window, CEntity* Entity) -> void
{
    if (!Entity) return;

    sf::Sprite asset = Entity->get_Asset().get_Sprite();
    sf::FloatRect sprite_bounds = asset.getGlobalBounds();

    // Coordinates Text
    std::string text = "X: " + std::to_string(sprite_bounds.left) +
        " / Y: " + std::to_string(sprite_bounds.top);
    CText coordinates(Window, text, ECharacter_Size::VERY_SMALL);
    coordinates.set_position(sprite_bounds.left, sprite_bounds.top + sprite_bounds.height);

    // Rectangle
    sf::RectangleShape debug_box(sf::Vector2f(sprite_bounds.width, sprite_bounds.height));
    debug_box.setPosition(sprite_bounds.left, sprite_bounds.top);
    debug_box.setOutlineColor(sf::Color::Blue);
    debug_box.setOutlineThickness(2.0f);
    debug_box.setFillColor(sf::Color::Transparent);

    coordinates.render();
    Window.draw(debug_box);
}

auto CDebugManager::MousePosition(sf::RenderWindow& Window) -> void
{
    sf::Vector2f MousePosition = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
    std::string text = "X: " + std::to_string(MousePosition.x) + "\nY: " + std::to_string(MousePosition.y);
    CText MouseText(Window, text, ECharacter_Size::VERY_SMALL);
    MouseText.render();
}

auto CDebugManager::render(sf::RenderWindow& Window, CEntity* Entity) -> void
{
    Hitbox(Window, Entity);
    MousePosition(Window);
}

