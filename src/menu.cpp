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
    menu_asset.get_sprite().setScale(static_cast<float>(scale), static_cast<float>(scale));
    center_menu();
    position_menu_items();
}

auto Menu::get_visable() const -> bool
{
    return visable;
}

auto Menu::set_visable(bool value) -> void
{
    visable = value;
}

auto Menu::get_text_bounds(Text& text) -> sf::FloatRect
{
    return text.get_text().getGlobalBounds();
}

auto Menu::center_menu() -> void
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = menu_asset.get_texture().getSize();

    xPos = (windowSize.x - (textureSize.x * menu_asset.get_sprite().getScale().x)) / 2;
    yPos = (windowSize.y - (textureSize.y * menu_asset.get_sprite().getScale().y)) / 2;

    menu_asset.get_sprite().setPosition(xPos, yPos);
}

auto Menu::position_menu_items() -> void
{
    sf::FloatRect spriteBounds = menu_asset.get_sprite().getGlobalBounds();

    // Center title
    menu_title_text.set_position(
        static_cast<int>(xPos + (spriteBounds.width - get_text_bounds(menu_title_text).width) / 2),
        static_cast<int>(yPos - 25)
    );

    // Center option
    float optionYPos = yPos + (spriteBounds.height / 2) - get_text_bounds(menu_option_text).height / 2;
    menu_option_text.set_position(
        static_cast<int>(xPos + (spriteBounds.width - get_text_bounds(menu_option_text).width) / 2),
        static_cast<int>(optionYPos)
    );

    // Position continue 75px above option
    menu_continue_text.set_position(
        static_cast<int>(xPos + (spriteBounds.width - get_text_bounds(menu_continue_text).width) / 2),
        static_cast<int>(optionYPos - get_text_bounds(menu_continue_text).height - vertical_padding)
    );

    // Position quit 75px below option
    menu_quit_text.set_position(
        static_cast<int>(xPos + (spriteBounds.width - get_text_bounds(menu_quit_text).width) / 2),
        static_cast<int>(optionYPos + get_text_bounds(menu_option_text).height + vertical_padding)
    );
}

auto Menu::get_menu_texts() -> std::vector<std::reference_wrapper<Text>>
{
    return { std::ref(menu_continue_text), std::ref(menu_option_text), std::ref(menu_quit_text) };
}

auto Menu::process_hover(const sf::Vector2f& mousePosF) -> void
{
    for (auto& text : get_menu_texts())
    {
        sf::FloatRect textBounds = text.get().get_text().getGlobalBounds();
        if (textBounds.contains(mousePosF))
        {
            text.get().get_text().setFillColor(hover_color);  // hovered
        }
        else
        {
            text.get().get_text().setFillColor(default_color);  // default
        }
    }
}

auto Menu::process_click(const sf::Vector2f& mousePosF) -> void
{
    for (auto& text : get_menu_texts())
    {
        sf::FloatRect textBounds = text.get().get_text().getGlobalBounds();

        if (textBounds.contains(mousePosF))
        {
            if (&text.get() == &menu_continue_text)
            {
                set_visable(false);
                std::cout << "Continue button clicked, visible: " << visable << std::endl;
            }
            else if (&text.get() == &menu_option_text)
            {
                set_visable(false);
            }
            else if (&text.get() == &menu_quit_text)
            {
                set_visable(false);
                panel.set_scene(Scene::Main_Menu);
            }
        }
    }
}

auto Menu::update_text_hover() -> void
{
    if (visable)
    {
        sf::Vector2f mousePosF = input.get_mouse_position();
        process_hover(mousePosF);
    }
}

auto Menu::draw() -> void
{
    if (visable)
    {
        update_text_hover();
        window.draw(menu_asset.get_sprite());

        for (auto& text : get_menu_texts())
        {
            text.get().draw_text(window);
        }
    }
}

auto Menu::check_text_click() -> void
{
    if (visable)
    {
        sf::Vector2f mousePosF = input.get_mouse_position();
        process_click(mousePosF);
    }
}
