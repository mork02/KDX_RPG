#include "main_menu.h"
#include "panel.h"
#include "scene_manager.h"

Main_menu::Main_menu(sf::RenderWindow& window_c, Panel& panel_c, Input& input_c)
    : window(window_c), panel(panel_c), input(input_c),
    background_asset(window_c, background_path),
    title_text("KDX RPG", 100, 0, 0),
    new_game_text("New Game", 56, 0, 0),
    options_text("Options", 56, 0, 0),
    quit_text("Quit", 56, 0, 0),
    new_game_asset(window_c, sign1_path),
    options_asset(window_c, sign2_path),
    quit_asset(window_c, sign3_path)
{
    // Initialize the menu
    update_assets();
}

void Main_menu::update_assets()
{
    // Center and scale the background
    scale_background(background_asset);

    center_menu(new_game_asset, 0, -115);
    center_menu(options_asset, 0, 75);
    center_menu(quit_asset, 0, 265);

    center_text_in_asset(new_game_asset, new_game_text);
    center_text_in_asset(options_asset, options_text);
    center_text_in_asset(quit_asset, quit_text);

    // Position of title text
    sf::FloatRect text_bounds = title_text.get_text().getLocalBounds();
    float title_X_Pos = window.getSize().x / 2.0f;
    float title_Y_Pos = text_bounds.height;
    title_text.set_position((int) title_X_Pos, (int) title_Y_Pos);
}

void Main_menu::draw()
{
    // Update mouse hover detection before drawing
    update_text_hover();

    // Draw menu background
    window.draw(background_asset.get_sprite());

    // Draw menu assets and text
    window.draw(new_game_asset.get_sprite());
    window.draw(options_asset.get_sprite());
    window.draw(quit_asset.get_sprite());
    window.draw(new_game_text.get_text());
    window.draw(options_text.get_text());
    window.draw(quit_text.get_text());

    // Animate the title
    animate_title();

    // Draw the title text
    title_text.draw_text(window);
}

sf::FloatRect Main_menu::get_text_bounds(Text text)
{
    return text.get_text().getGlobalBounds();
}

void Main_menu::center_menu(Asset_loader& asset, int x, int y)
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = asset.get_texture().getSize();

    // Set the sprite's origin to its center
    asset.get_sprite().setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);

    // Position the sprite in the center of the window
    float x_Pos = (windowSize.x / 2.0f) + x;
    float y_Pos = (windowSize.y / 2.0f) + y;

    asset.get_sprite().setPosition(x_Pos, y_Pos);
}

void Main_menu::center_text_in_asset(Asset_loader& asset, Text& text)
{
    sf::FloatRect assetBounds = asset.get_sprite().getGlobalBounds();
    sf::FloatRect textBounds = text.get_text().getLocalBounds();

    // Set the text's origin to its center
    text.get_text().setOrigin(
        static_cast<float>(textBounds.left + textBounds.width / 2.0f),  // Horizontal center
        static_cast<float>(textBounds.top + textBounds.height / 2.0f)   // Vertical center
    );

    // Position the text at the center of the asset
    text.set_position(
        static_cast<int>(assetBounds.left + assetBounds.width / 2.0f),  // Center X
        static_cast<int>(assetBounds.top + assetBounds.height / 2.0f)   // Center Y
    );
}

void Main_menu::scale_background(Asset_loader& asset)
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = asset.get_texture().getSize();

    float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y);

    asset.get_sprite().setScale(scaleX, scaleY);
}

void Main_menu::animate_title()
{
    static bool shrinking = true;
    static int frame_counter = 0;
    const int frame_delay = 1;

    unsigned int current_size = title_text.get_text().getCharacterSize();
    sf::FloatRect text_bounds = title_text.get_text().getLocalBounds();

    title_text.get_text().setOrigin(
        text_bounds.left + text_bounds.width / 2.0f, // Horizontal center
        text_bounds.top + text_bounds.height / 2.0f  // Vertical center
    );

    if (frame_counter < frame_delay)
    {
        frame_counter++;
        return;
    }

    frame_counter = 0;

    if (shrinking)
    {
        if (current_size > 100)
        {
            title_text.get_text().setCharacterSize(current_size - 1);
        }
        else
        {
            shrinking = false;
        }
    }
    else
    {
        if (current_size < 128)
        {
            title_text.get_text().setCharacterSize(current_size + 1);
        }
        else
        {
            shrinking = true;
        }
    }
}

std::vector<std::pair<std::reference_wrapper<Asset_loader>, std::reference_wrapper<Text>>> Main_menu::get_text_components()
{
    // return vector of text to handle click and hover event        
    return {
        { std::ref(new_game_asset), std::ref(new_game_text) },
        { std::ref(options_asset), std::ref(options_text) },
        { std::ref(quit_asset), std::ref(quit_text) }
    };
}

void Main_menu::process_hover(const sf::Vector2f& mousePosF)
{
    auto assetTextPairs = get_text_components();

    for (const auto& pair : assetTextPairs)
    {
        sf::FloatRect assetBounds = pair.first.get().get_sprite().getGlobalBounds();

        if (assetBounds.contains(mousePosF))
        {
            pair.second.get().get_text().setFillColor(sf::Color(210, 170, 109));  // hovered
        }
        else
        {
            pair.second.get().get_text().setFillColor(sf::Color::White);  // default
        }
    }
}

void Main_menu::process_click(const sf::Vector2f& mousePosF)
{
    auto assetTextPairs = get_text_components();

    for (const auto& pair : assetTextPairs)
    {
        sf::FloatRect assetBounds = pair.first.get().get_sprite().getGlobalBounds();

        if (assetBounds.contains(mousePosF))
        {
            if (&pair.second.get() == &new_game_text)
            {
                panel.set_scene(Scene::Gameplay); 
            }
            else if (&pair.second.get() == &options_text)
            {
                // Add logic
            }
            else if (&pair.second.get() == &quit_text)
            {
                window.close();
            }
        }
    }
}

void Main_menu::update_text_hover()
{
    sf::Vector2f mousePosF = input.get_mouse_position();
    process_hover(mousePosF);
}

// Main click method using the helper
void Main_menu::check_text_click()
{
    sf::Vector2f mousePosF = input.get_mouse_position();
    process_click(mousePosF);
}
