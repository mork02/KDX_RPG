#include "menu.h"

Menu::Menu(sf::RenderWindow& window_c, Input& input_c)
    : window(window_c), input(input_c),
    menu_title_text("Menu", 128, 0, 0),
    menu_continue_text("Continue", 86, 0, 0), 
    menu_option_text("Option", 86, 0, 0),      
    menu_quit_text("Quit", 86, 0, 0)
{
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setScale((float) scale, (float) scale);

    center_menu();

    sf::FloatRect spriteBounds = sprite.getGlobalBounds();

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

// Getter

bool Menu::get_visable() const
{
    return visable;
}

sf::FloatRect Menu::get_text_bounds(Text text) {
    return text.get_text().getGlobalBounds();
}

// Setter

void Menu::set_visable(bool value)
{
    visable = value;
}

// Methods

void Menu::draw()
{
    if (visable)
    {
        // Update mouse hover detection before drawing
        update_text_hover();

        // draw menu background
        window.draw(sprite);

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
    sf::Vector2u textureSize = texture.getSize();

    xPos = (windowSize.x - (textureSize.x * sprite.getScale().x)) / 2;
    yPos = (windowSize.y - (textureSize.y * sprite.getScale().y)) / 2;

    sprite.setPosition(xPos, yPos);
}

void Menu::update_text_hover()
{
    sf::Vector2f mousePosF = input.get_mouse_position();

    Text* texts[] = { &menu_continue_text, &menu_option_text, &menu_quit_text };

    for (Text* text : texts)
    {
        sf::FloatRect textBounds = text->get_text().getGlobalBounds();

        if (textBounds.contains(mousePosF))
        {
            text->get_text().setFillColor(sf::Color(210, 170, 109));

            if (input.is_mouse_button_pressed(sf::Mouse::Left))
            {
                if (text == &menu_continue_text)
                {
                    visable = false;
                }
                else if (text == &menu_option_text)
                {
                    // Add option menu
                }
                else if (text == &menu_quit_text)
                {
                    window.close();
                }
            }
        }
        else
        {
            text->get_text().setFillColor(sf::Color::White);
        }
    }
}