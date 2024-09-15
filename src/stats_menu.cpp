#include "stats_menu.h"
#include "panel.h"
#include "scene_manager.h"

Stats_menu::Stats_menu(sf::RenderWindow& window_c, Panel& panel_c, Input& input_c)
    : window(window_c), panel(panel_c), input(input_c), 
    visable(false),
    stats_asset(window_c, menu_path)
{
    stats_asset.get_sprite().setScale((float)scale, (float)scale);

    center_menu();

    sf::FloatRect spriteBounds = stats_asset.get_sprite().getGlobalBounds();


}

bool Stats_menu::get_visable() const
{
    return visable;
}

sf::FloatRect Stats_menu::get_text_bounds(Text text) {
    return text.get_text().getGlobalBounds();
}

void Stats_menu::set_visable(bool value)
{
    visable = value;
}

void Stats_menu::draw()
{
    // This method displays everything thats important for menu
    if (visable)
    {
        // Update mouse hover detection before drawing
        update_text_hover();

        // draw menu background
        window.draw(stats_asset.get_sprite());

        // draw all text
    }
}

void Stats_menu::center_menu()
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = stats_asset.get_texture().getSize();

    float centered_x = (windowSize.x - (textureSize.x * stats_asset.get_sprite().getScale().x)) / 2;
    float centered_y = (windowSize.y - (textureSize.y * stats_asset.get_sprite().getScale().y)) / 2;

    stats_asset.get_sprite().setPosition(centered_x, centered_y);
}

void Stats_menu::process_hover(const sf::Vector2f& mousePosF)
{
    /*
    auto texts = get_menu_texts();

    for (auto& text : texts)
    {
        sf::FloatRect textBounds = text.get().get_text().getGlobalBounds();

        if (textBounds.contains(mousePosF))
        {
            text.get().get_text().setFillColor(sf::Color(210, 170, 109)); // hovered
        }
        else
        {
            text.get().get_text().setFillColor(sf::Color::White); // defualt
        }
    }
    */
}

void Stats_menu::process_click(const sf::Vector2f& mousePosF)
{
    /*
    auto texts = get_menu_texts();

    for (auto& text : texts)
    {
        sf::FloatRect textBounds = text.get().get_text().getGlobalBounds();

        if (textBounds.contains(mousePosF))
        {
            if (&text.get() == &menu_continue_text)
            {
                set_visable(false);
                std::cout << "Continue button clicked, visable: " << visable << std::endl;
            }
            else if (&text.get() == &menu_option_text)
            {
                // Add logic
            }
            else if (&text.get() == &menu_quit_text)
            {
                set_visable(false);
                panel.set_scene(Scene::Main_Menu);  // Switch back to the main menu
            }
        }
    }
    */
}

void Stats_menu::update_text_hover()
{
    if (visable) {
        sf::Vector2f mousePosF = input.get_mouse_position();
        process_hover(mousePosF);
    }
}

void Stats_menu::check_text_click()
{
    if (visable) {
        sf::Vector2f mousePosF = input.get_mouse_position();
        process_click(mousePosF);
    }
}
