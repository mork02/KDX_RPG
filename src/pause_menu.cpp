#include "pause_menu.h"
#include "game_manager.h"

CPause_menu::CPause_menu(sf::RenderWindow& Window) : 
    CMenu(Window, EMenuState::PAUSE),
    mTitle_Text(Window, "Pause", ECharacter_Size::LARGE, false),
    mContinue_Text(Window, "Continue", ECharacter_Size::MEDIUM, true),
    mOptions_Text(Window, "Options", ECharacter_Size::MEDIUM, true),
    mBack_To_Title_Text(Window, "Back to Title", ECharacter_Size::MEDIUM, true)
{
    init_asset(mPath);
    center_asset(Window);
    get_Sprite().setScale(6, 6);
    set_text_position(Window);
}

auto CPause_menu::get_text_components() -> std::vector<std::reference_wrapper<CText>>
{
    return {
        { std::ref(mTitle_Text) },
        { std::ref(mContinue_Text) },
        { std::ref(mOptions_Text) },
        { std::ref(mBack_To_Title_Text) }
    };
}

auto CPause_menu::set_text_position(sf::RenderWindow& Window) -> void
{
    mTitle_Text.set_position(
        Window.getSize().x / 2.0f - mTitle_Text.get_Global_text_Bounds().width / 2,
        Window.getSize().y * 0.125f
    );

    float gray_field_top = Window.getSize().y * 0.35f;
    float gray_field_height = Window.getSize().y * 0.4f;
    float option_spacing = gray_field_height / 5.0f;

    mContinue_Text.set_position(
        Window.getSize().x / 2.0f - mContinue_Text.get_Global_text_Bounds().width / 2,
        gray_field_top + option_spacing * 0.1f
    );

    mOptions_Text.set_position(
        Window.getSize().x / 2.0f - mOptions_Text.get_Global_text_Bounds().width / 2,
        gray_field_top + option_spacing * 1.6f
    );

    mBack_To_Title_Text.set_position(
        Window.getSize().x / 2.0f - mBack_To_Title_Text.get_Global_text_Bounds().width / 2,
        gray_field_top + option_spacing * 3.2f
    );
}

auto CPause_menu::render(sf::RenderWindow& Window) -> void
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

auto CPause_menu::handle_events(sf::Event& Event, sf::RenderWindow& Window, CMenuManager& MenuManager, CStateManager* StateManager) -> void
{
    sf::Vector2f mouse_pos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));

    if (mContinue_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        MenuManager.set_menu(nullptr);
    }
    else if (mOptions_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        MenuManager.set_menu(MenuManager.get_option_menu());
    }
    else if (mBack_To_Title_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        MenuManager.set_menu(nullptr);
        StateManager->set_state(StateManager->get_title_screen());
    }
}
