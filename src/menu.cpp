#include "menu.h"
#include "panel.h"
#include "scene_manager.h"

Menu::Menu(sf::RenderWindow& window_c, Panel& panel_c, Input& input_c)
    : window(window_c), panel(panel_c), input(input_c),
    visable(false),
    menu_asset(window_c, path),
    menu_title_text("Menu", 128, 0, 0),
    menu_continue_text("Continue", 86, 0, 0), 
    menu_option_text("Option", 86, 0, 0),      
    menu_quit_text("Back to Menu", 86, 0, 0)
{

    menu_asset.get_sprite().setScale((float)scale, (float)scale);

    center_menu();

    sf::FloatRect spriteBounds = menu_asset.get_sprite().getGlobalBounds();

    // MENU TITLE
    float titleXPos = xPos + (spriteBounds.width - get_text_bounds(menu_title_text).width) / 2;
    float titleYPos = yPos - 25; 
    menu_title_text.set_position((int) titleXPos, (int) titleYPos);

    // MENU OPTIONS
    // CENTER
    float optionXPos = xPos + (spriteBounds.width - get_text_bounds(menu_option_text).width) / 2;
    float optionYPos = yPos + (spriteBounds.height / 2) - get_text_bounds(menu_option_text).height / 2;
    menu_option_text.set_position((int) optionXPos, (int) optionYPos);

    // MENU CONMTINUE
    // 75 px above options
    float continueXPos = xPos + (spriteBounds.width - get_text_bounds(menu_continue_text).width) / 2;
    float continueYPos = optionYPos - get_text_bounds(menu_continue_text).height - 75; 
    menu_continue_text.set_position((int) continueXPos, (int) continueYPos);

    // MENU QUIT
    // 75 px under options
    float quitXPos = xPos + (spriteBounds.width - get_text_bounds(menu_quit_text).width) / 2;
    float quitYPos = optionYPos + get_text_bounds(menu_option_text).height + 75;
    menu_quit_text.set_position((int) quitXPos, (int) quitYPos);
}

bool Menu::get_visable() const
{
    return visable;
}

sf::FloatRect Menu::get_text_bounds(Text text) {
    return text.get_text().getGlobalBounds();
}

void Menu::set_visable(bool value)
{
    visable = value;
}

void Menu::draw()
{
    // This method displays everything thats important for menu
    if (visable)
    {
        // Update mouse hover detection before drawing
        update_text_hover();

        // draw menu background
        window.draw(menu_asset.get_sprite());

        // draw all text
        menu_title_text.draw_text(window);
        menu_continue_text.draw_text(window);
        menu_option_text.draw_text(window);
        menu_quit_text.draw_text(window);
    }
}

void Menu::center_menu()
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = menu_asset.get_texture().getSize();

    xPos = (windowSize.x - (textureSize.x * menu_asset.get_sprite().getScale().x)) / 2;
    yPos = (windowSize.y - (textureSize.y * menu_asset.get_sprite().getScale().y)) / 2;

    menu_asset.get_sprite().setPosition(xPos, yPos);
}


std::vector<std::reference_wrapper<Text>> Menu::get_menu_texts()
{
    // Returns text to handle click and hover event
    return { std::ref(menu_continue_text), std::ref(menu_option_text), std::ref(menu_quit_text) };
}

void Menu::process_hover(const sf::Vector2f& mousePosF)
{
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
}

void Menu::process_click(const sf::Vector2f& mousePosF)
{
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
}

void Menu::update_text_hover()
{
    if (visable) {
        sf::Vector2f mousePosF = input.get_mouse_position();
        process_hover(mousePosF);
    }
}

void Menu::check_text_click()
{
    if (visable) {
        sf::Vector2f mousePosF = input.get_mouse_position();
        process_click(mousePosF);
    }
}
