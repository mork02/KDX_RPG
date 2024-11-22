#include "option_menu.h"
#include "gameplay_state.h"

COption_menu::COption_menu(sf::RenderWindow& Window) : 
	CMenu(Window, EMenuState::OPTIONS),
	mTitle_Text(Window, "Options", ECharacter_Size::LARGE, false),
	mBack_Text(Window, "Back", ECharacter_Size::MEDIUM, true)
{
	init_asset(mPath);
	get_Sprite().setScale(6, 6);
	center_asset();
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

auto COption_menu::render() -> void
{
	if (get_visible())
	{
		mWindow.draw(get_Sprite());

		for (const auto& text : get_text_components())
		{
			text.get().render();
		}
	}
}

auto COption_menu::handle_events(sf::Event& Event, CMenuManager& MenuManager, CStateManager* StateManager) -> void
{
    sf::Vector2f mouse_pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
	if (mBack_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
	{
		MenuManager.set_menu(MenuManager.get_pause_menu());
	}
}
