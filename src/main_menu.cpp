#include "main_menu.h"

Main_menu::Main_menu(sf::RenderWindow& window_c, Mouse_controller& mouse_ctrl_c)
    : window(window_c), mouse_ctrl(mouse_ctrl_c),
    title_text("KDX RPG", 64, 0, 0)
{
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture from " << path << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setScale((float)scale, (float)scale);

    center_menu();

    sf::FloatRect spriteBounds = sprite.getGlobalBounds();

    // MENU TITLE
    
    /*
    CHANGE SPRITE AND TEXT IN CENTER TOP TO DISPLAY IT AS TITLESCREEN
    */

    float titleXPos = spriteBounds.left + (spriteBounds.width - get_text_bounds(title_text).width) / 2;
    float titleYPos = spriteBounds.top + (spriteBounds.height - get_text_bounds(title_text).height) / 2;
    title_text.set_position((int)titleXPos, (int)titleYPos);
}

sf::FloatRect Main_menu::get_text_bounds(Text text) {
    return text.get_text().getGlobalBounds();
}

void Main_menu::center_menu()
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();

    xPos = (windowSize.x - (textureSize.x * sprite.getScale().x)) / 2;
    yPos = (windowSize.y - (textureSize.y * sprite.getScale().y)) / 2;

    sprite.setPosition(xPos, yPos);
}

void Main_menu::update_text_hover()
{
    sf::Vector2f mousePosF = mouse_ctrl.get_mouse_position();

    Text* texts[] = { &title_text };

    for (Text* text : texts)
    {
        sf::FloatRect textBounds = text->get_text().getGlobalBounds();

        if (textBounds.contains(mousePosF))
        {
            text->get_text().setFillColor(sf::Color(210, 170, 109));

            if (mouse_ctrl.is_mouse_button_pressed(sf::Mouse::Left))
            {

            }
        }
        else
        {
            text->get_text().setFillColor(sf::Color::White);
        }
    }
    
}

void Main_menu::draw()
{
    // Update mouse hover detection before drawing
    update_text_hover();

    // draw menu background
    window.draw(sprite);

    animate_title();

    // draw all text
    title_text.draw_text(window);
}

void Main_menu::animate_title()
{
    static bool shrinking = true;  
    unsigned int current_size = title_text.get_text().getCharacterSize();
    sf::FloatRect text_bounds = title_text.get_text().getLocalBounds();

    title_text.get_text().setOrigin(
        text_bounds.left + text_bounds.width / 2.0f, // Horizontal center
        text_bounds.top + text_bounds.height / 2.0f  // Vertical center
    );

    if (shrinking)
    {
        if (current_size > 64)
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
            // Switch to shrinking if the size hits 128
            shrinking = true;
        }
    }
}

