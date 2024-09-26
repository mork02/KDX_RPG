#include "option_menu.h"
#include "panel.h"

COption_menu::COption_menu(sf::RenderWindow& window_c)
	: CMenu(window_c, EMenuType::Options),
	background_asset(window_c, background_path),
	title_text("Options", 109, false),
	back_text("Back", 89, true)
{
	background_asset.set_scale(background_scale);
	background_asset.center_asset();
	set_text_position();
}

auto COption_menu::get_text_components() -> std::vector<std::reference_wrapper<Text>>
{
	return {
		{ std::ref(title_text) },
		{ std::ref(back_text) }
	};
}

auto COption_menu::set_text_position() -> void
{
	title_text.set_position(
		static_cast<int>(window.getSize().x / 2.0f - title_text.get_text().getGlobalBounds().width / 2),
		static_cast<int>(window.getSize().y * 0.15f)
	);

	float gray_field_top = window.getSize().y * 0.35f;
	float gray_field_height = window.getSize().y * 0.4f;
	float middle_spacing = gray_field_height / 5.0f;

	back_text.set_position(
		static_cast<int>(window.getSize().x / 2.0f - back_text.get_text().getGlobalBounds().width / 2),
		static_cast<int>(gray_field_top + middle_spacing * 3.2f)
	);

}

auto COption_menu::draw() -> void
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

auto COption_menu::handle_click_event(CPanel& panel) -> void
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    if (back_text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
		panel.set_current_menu(&panel.get_pause_menu());
    }
}
