#include "option_menu.h"
#include "panel.h"

COption_menu::COption_menu(sf::RenderWindow& Window) : 
	CMenu(Window, EMenuType::Options),
	mTitle_Text(Window, "Options", ECharacter_Size::LARGE, false),
	mBack_Text(Window, "Back", ECharacter_Size::MEDIUM, true)
{
	mAsset.init(mPath);
	mAsset.center_asset();
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
		mWindow.getSize().x / 2.0f - mTitle_Text.get_Global_text_Bounds().width / 2,
		mWindow.getSize().y * 0.15f
	);

	float gray_field_top = mWindow.getSize().y * 0.35f;
	float gray_field_height = mWindow.getSize().y * 0.4f;
	float middle_spacing = gray_field_height / 5.0f;

	mBack_Text.set_position(
		mWindow.getSize().x / 2.0f - mBack_Text.get_Global_text_Bounds().width / 2,
		gray_field_top + middle_spacing * 3.2f
	);

}

auto COption_menu::draw() -> void
{
	if (get_visible())
	{
		mWindow.draw(mAsset.get_Sprite());

		for (const auto& text : get_text_components())
		{
			text.get().update();
		}
	}
}

auto COption_menu::handle_click_event(CGameplay& Gameplay, CPanel* Panel) -> void
{
    sf::Vector2f mouse_pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
	if (mBack_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
	{
		Gameplay.set_current_menu(&Gameplay.get_menu_pause());
	}
}
