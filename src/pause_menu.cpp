#include "pause_menu.h"

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
    // HELPED BY GPT!!!
    //
    // Adjust title position to fit inside the brown box
    title_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - title_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(window.getSize().y * 0.15f)  // Move "Pause" to fit inside the brown box
    );

    // Define the area of the gray field
    float gray_field_top = window.getSize().y * 0.35f;  // Top of the gray field
    float gray_field_height = window.getSize().y * 0.4f;  // Height of the gray field

    // Calculate vertical spacing between the options
    float option_spacing = gray_field_height / 5.0f;  // Spacing to distribute options evenly

    // Position "Continue" closer to the top of the gray field
    continue_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - continue_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(gray_field_top + option_spacing * 0.1f)  // Closer to the top of the gray field
    );

    // Position "Options" at the center of the gray field
    options_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - options_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(gray_field_top + option_spacing * 1.6f)  // Center the "Options" text
    );

    // Position "Back to Title" slightly higher than before
    back_to_title_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - back_to_title_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(gray_field_top + option_spacing * 3.2f)  // Moved up slightly
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

auto CPause_menu::center_asset(Asset_loader& asset) -> void
{
    sf::Vector2u texture_size = asset.get_texture().getSize();
    sf::Vector2u window_size = window.getSize();

    asset.get_sprite().setOrigin(texture_size.x / 2.0f, texture_size.y / 2.0f);
    asset.get_sprite().setPosition(window_size.x / 2.0f, window_size.y / 2.0f);
}
