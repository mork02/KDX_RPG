#include "option_menu.h"
#include "gameplay_state.h"

COption_menu::COption_menu(sf::RenderWindow& Window) : 
	CMenu(Window, EMenuState::OPTIONS),
	mTitle_Text(Window, "Options", ECharacter_Size::LARGE, false),
	mBack_Text(Window, "Back", ECharacter_Size::MEDIUM, true)
{
	init_asset(mPath);
	get_Sprite().setScale(6, 6);
	center_asset(Window);
	set_text_position(Window);
}

auto COption_menu::get_text_components() -> std::vector<std::reference_wrapper<CText>>
{
	return {
		{ std::ref(mTitle_Text) },
		{ std::ref(mBack_Text) }
	};
}

auto COption_menu::set_text_position(sf::RenderWindow& Window) -> void
{
	mTitle_Text.set_position(
		Window.getSize().x / 2.0f - mTitle_Text.get_Global_text_Bounds().width / 2,
		Window.getSize().y * 0.15f
	);

	float gray_field_top = Window.getSize().y * 0.35f;
	float gray_field_height = Window.getSize().y * 0.4f;
	float middle_spacing = gray_field_height / 5.0f;

	mBack_Text.set_position(
		Window.getSize().x / 2.0f - mBack_Text.get_Global_text_Bounds().width / 2,
		gray_field_top + middle_spacing * 3.2f
	);

}

auto COption_menu::render(sf::RenderWindow& Window) -> void
{
	if (get_visible())
	{
		Window.draw(get_Sprite());

		for (const auto& text : get_text_components())
		{
			text.get().render(Window);
		}
	}
}

auto COption_menu::handle_events(sf::Event& Event, sf::RenderWindow& Window, CMenuManager& MenuManager, CStateManager* StateManager) -> void
{
    sf::Vector2f mouse_pos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
	if (mBack_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
	{
		MenuManager.set_menu(MenuManager.get_pause_menu());
	}
}
