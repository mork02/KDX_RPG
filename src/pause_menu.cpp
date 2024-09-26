#include "pause_menu.h"
#include "panel.h"

CPause_menu::CPause_menu(sf::RenderWindow& window_c)
    : CMenu(window_c, EMenuType::Pause),
    background_asset(window_c, background_path),
    title_text("Pause", 109, false),
    continue_text("Continue", 89, true),
    options_text("Options", 89, true),
    back_to_title_text("Back to Title", 89, true)
{
    background_asset.set_scale(background_scale);
    center_asset(background_asset);
    set_text_position();
}

auto CPause_menu::get_text_components() -> std::vector<std::reference_wrapper<Text>>
{
    return {
        { std::ref(title_text) },
        { std::ref(continue_text) },
        { std::ref(options_text) },
        { std::ref(back_to_title_text) }
    };
}

auto CPause_menu::set_text_position() -> void
{
    // Adjust title position to fit inside the brown box
    title_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - title_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(window.getSize().y * 0.15f)
    );

    // Define the area of the gray field
    float gray_field_top = window.getSize().y * 0.35f;
    float gray_field_height = window.getSize().y * 0.4f;
    float option_spacing = gray_field_height / 5.0f;

    // Position text components inside the gray field
    continue_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - continue_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(gray_field_top + option_spacing * 0.1f)
    );

    options_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - options_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(gray_field_top + option_spacing * 1.6f)
    );

    back_to_title_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - back_to_title_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(gray_field_top + option_spacing * 3.2f)
    );
}

auto CPause_menu::draw() -> void
{
    if (visible) 
    {
        window.draw(background_asset.get_sprite());

        for (const auto& text : get_text_components()) 
        {
            text.get().draw_text(window);
        }
    }
}

auto CPause_menu::handle_click_event(CPanel& panel) -> void
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    if (continue_text.get_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(nullptr);
    }
    else if (options_text.get_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        // add some logic !
        std::cout << "Options clicked!" << std::endl;
    }
    else if (back_to_title_text.get_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(nullptr);
        panel.set_scene(ESceneType::Title_screen);
    }
}

auto CPause_menu::center_asset(Asset_loader& asset) -> void
{
    sf::Vector2u texture_size = asset.get_texture().getSize();
    sf::Vector2u window_size = window.getSize();

    asset.get_sprite().setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    asset.get_sprite().setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
}