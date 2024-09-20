#include "title_screen.h"

CTitle_Screen::CTitle_Screen(sf::RenderWindow& window_c) : window(window_c),
background_asset(window_c, background_path),
title_text("KDX RPG", 168, false),
new_game_text("New Game", 136, true),
options_text("Options", 136, true),
quit_text("Quit", 136, true)
{
    scale_background(background_asset);
    position_texts();
}

auto CTitle_Screen::draw() -> void
{
    for (auto const asset : get_asset_components())
    {
        window.draw(asset.get().get_sprite());
    }
    
    animate_title_text();

    for (auto const text : get_text_components())
    {
        text.get().draw_text(window);
    }
}

auto CTitle_Screen::scale_background(Asset_loader& asset) -> void
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = asset.get_texture().getSize();

    asset.get_sprite().setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
}

auto CTitle_Screen::position_texts() -> void
{
    // MADE WITH GPT
    //
    sf::Vector2u windowSize = window.getSize();

    // Adjust title position to fit inside the brown sign area
    title_text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - title_text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(windowSize.y * 0.01f)  
    );

    // Define the area of the gray field for the menu items
    float gray_field_top = windowSize.y * 0.35f;  
    float gray_field_height = windowSize.y * 0.4f;  

    // Increase the spacing between the options
    float option_spacing = gray_field_height / 3.0f; 

    new_game_text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - new_game_text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 0.1f - 75)  
    );

    // Position "Options" below "New Game" with increased spacing
    options_text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - options_text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 1.5f - 75)  
    );

    // Position "Quit" with increased spacing below "Options"
    quit_text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - quit_text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 2.9f - 75)
    );
}

auto CTitle_Screen::animate_title_text() -> void
{
 
    if (increasing) {
        fade_alpha += fade_increment;
    }
    if (fade_alpha > 255.0f && increasing)
    {
        fade_alpha = 255.0f;
        increasing = false;
    }

    sf::Color color = title_text.get_text().getFillColor();
    color.a = static_cast<sf::Uint8>(fade_alpha);
    title_text.get_text().setFillColor(color);
}

auto CTitle_Screen::get_asset_components() -> std::vector<std::reference_wrapper<Asset_loader>>
{
    return {
        { std::ref(background_asset) }
    };
}

auto CTitle_Screen::get_text_components() -> std::vector<std::reference_wrapper<Text>>
{
    return {
        { std::ref(title_text) },
        { std::ref(new_game_text) },
        { std::ref(options_text) },
        { std::ref(quit_text) }
    };
}