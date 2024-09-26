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
    background_asset.center_asset();
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
    title_text.set_position(
        static_cast<int>(window.getSize().x / 2.0f - title_text.get_text().getGlobalBounds().width / 2),
        static_cast<int>(window.getSize().y * 0.15f)
    );

    float gray_field_top = window.getSize().y * 0.35f;
    float gray_field_height = window.getSize().y * 0.4f;
    float option_spacing = gray_field_height / 5.0f;

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

    if (continue_text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(nullptr);
    }
    else if (options_text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(&panel.get_options_menu());
    }
    else if (back_to_title_text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(nullptr);
        panel.set_scene(ESceneType::Title_screen);
    }
}
