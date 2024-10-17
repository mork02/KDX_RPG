#include "option_menu.h"
#include "panel.h"

COption_menu::COption_menu(sf::RenderWindow& Window)
	: CMenu(Window, EMenuType::Options),
	mBackground_Asset(Window, mBackground_Path),
	mTitle_Text("Options", 109, false),
	mBack_Text("Back", 89, true)
{
	mBackground_Asset.set_scale(mBackground_Scale);
	mBackground_Asset.center_asset();
	set_text_position();
}

auto COption_menu::get_text_components() -> std::vector<std::reference_wrapper<CText>>
{
	return {
		{ std::ref(mTitle_Text) },
		{ std::ref(mBack_Text) }
	};
}

auto COption_menu::set_text_position() -> void
{
	mTitle_Text.set_position(
		mWindow.getSize().x / 2.0f - mTitle_Text.get_text().getGlobalBounds().width / 2,
		mWindow.getSize().y * 0.15f
	);

	float gray_field_top = mWindow.getSize().y * 0.35f;
	float gray_field_height = mWindow.getSize().y * 0.4f;
	float middle_spacing = gray_field_height / 5.0f;

	mBack_Text.set_position(
		mWindow.getSize().x / 2.0f - mBack_Text.get_text().getGlobalBounds().width / 2,
		gray_field_top + middle_spacing * 3.2f
	);

}

auto COption_menu::draw() -> void
{
	if (mVisible)
	{
		mWindow.draw(mBackground_Asset.get_sprite());

		for (const auto& text : get_text_components())
		{
			text.get().draw_text(mWindow);
		}
	}
}

auto COption_menu::handle_click_event(CPanel& panel) -> void
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(mWindow);
    if (mBack_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
		panel.set_current_menu(&panel.get_pause_menu());
    }
}
