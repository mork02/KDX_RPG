#include "title_screen.h"
#include "panel.h"
#include "scene_manager.h"

CTitle_Screen::CTitle_Screen(sf::RenderWindow& window_c, Panel& panel_c, Input& input_c)
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
    update_assets();  // Initialize the menu
}

auto CTitle_Screen::update_assets() -> void
{
    // Center and scale the background
    scale_background(background_asset);

    center_menu(new_game_asset, 0, -115);
    center_menu(options_asset, 0, 75);
    center_menu(quit_asset, 0, 265);

    center_text_in_asset(new_game_asset, new_game_text);
    center_text_in_asset(options_asset, options_text);
    center_text_in_asset(quit_asset, quit_text);

    // Position title text
    sf::FloatRect text_bounds = title_text.get_text().getLocalBounds();
    float title_X_Pos = window.getSize().x / 2.0f;
    float title_Y_Pos = text_bounds.height;
    title_text.set_position(static_cast<int>(title_X_Pos), static_cast<int>(title_Y_Pos));
}

auto CTitle_Screen::draw() -> void
{
    update_text_hover();  // Update mouse hover detection

    window.draw(background_asset.get_sprite());
    window.draw(new_game_asset.get_sprite());
    window.draw(options_asset.get_sprite());
    window.draw(quit_asset.get_sprite());

    window.draw(new_game_text.get_text());
    window.draw(options_text.get_text());
    window.draw(quit_text.get_text());

    animate_title();  // Animate the title
    title_text.draw_text(window);
}

auto CTitle_Screen::get_text_bounds(Text text) -> sf::FloatRect
{
    return text.get_text().getGlobalBounds();
}

auto CTitle_Screen::center_menu(Asset_loader& asset, int x, int y) -> void
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = asset.get_texture().getSize();

    asset.get_sprite().setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    asset.get_sprite().setPosition(windowSize.x / 2.0f + x, windowSize.y / 2.0f + y);
}

auto CTitle_Screen::center_text_in_asset(Asset_loader& asset, Text& text) -> void
{
    sf::FloatRect assetBounds = asset.get_sprite().getGlobalBounds();
    sf::FloatRect textBounds = text.get_text().getLocalBounds();

    text.get_text().setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    text.set_position(static_cast<int>(assetBounds.left + assetBounds.width / 2.0f), static_cast<int>(assetBounds.top + assetBounds.height / 2.0f));
}

auto CTitle_Screen::scale_background(Asset_loader& asset) -> void
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = asset.get_texture().getSize();

    asset.get_sprite().setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
}

auto CTitle_Screen::animate_title() -> void
{
    static bool shrinking = true;
    static int frame_counter = 0;
    const int frame_delay = 1;

    unsigned int current_size = title_text.get_text().getCharacterSize();
    sf::FloatRect text_bounds = title_text.get_text().getLocalBounds();

    title_text.get_text().setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);

    if (frame_counter < frame_delay)
    {
        ++frame_counter;
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

auto CTitle_Screen::get_text_components() -> std::vector<std::pair<std::reference_wrapper<Asset_loader>, std::reference_wrapper<Text>>>
{
    return {
        { std::ref(new_game_asset), std::ref(new_game_text) },
        { std::ref(options_asset), std::ref(options_text) },
        { std::ref(quit_asset), std::ref(quit_text) }
    };
}

auto CTitle_Screen::process_hover(const sf::Vector2f& mousePosF) -> void
{
    auto assetTextPairs = get_text_components();

    for (const auto& pair : assetTextPairs)
    {
        sf::FloatRect assetBounds = pair.first.get().get_sprite().getGlobalBounds();

        if (assetBounds.contains(mousePosF))
        {
            pair.second.get().get_text().setFillColor(sf::Color(210, 170, 109));  // Hover color
        }
        else
        {
            pair.second.get().get_text().setFillColor(sf::Color::White);  // Default color
        }
    }
}

auto CTitle_Screen::process_click(const sf::Vector2f& mousePosF) -> void
{
    auto assetTextPairs = get_text_components();

    for (const auto& pair : assetTextPairs)
    {
        sf::FloatRect assetBounds = pair.first.get().get_sprite().getGlobalBounds();

        if (assetBounds.contains(mousePosF))
        {
            if (&pair.second.get() == &new_game_text)
            {
                panel.set_scene(Scene::Gameplay);  // Start new game
            }
            else if (&pair.second.get() == &options_text)
            {
                // Add logic for options
            }
            else if (&pair.second.get() == &quit_text)
            {
                window.close();  // Quit the game
            }
        }
    }
}

auto CTitle_Screen::update_text_hover() -> void
{
    sf::Vector2f mousePosF = input.get_mouse_position();
    process_hover(mousePosF);
}

auto CTitle_Screen::check_text_click() -> void
{
    sf::Vector2f mousePosF = input.get_mouse_position();
    process_click(mousePosF);
}
