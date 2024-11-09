#include "pause_menu.h"
#include "gameplay.h"
#include "panel.h"


CPause_menu::CPause_menu(sf::RenderWindow& Window) : 
    CMenu(Window, EMenuType::Pause),
    mTitle_Text(Window, "Pause", ECharacter_Size::LARGE, false),
    mContinue_Text(Window, "Continue", ECharacter_Size::MEDIUM, true),
    mOptions_Text(Window, "Options", ECharacter_Size::MEDIUM, true),
    mBack_To_Title_Text(Window, "Back to Title", ECharacter_Size::MEDIUM, true)
{
    mAsset.init(mPath);
    mAsset.center_asset();
    mAsset.get_Sprite().setScale(6, 6);
    set_text_position();
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

auto CPause_menu::set_text_position() -> void
{
    mTitle_Text.set_position(
        mWindow.getSize().x / 2.0f - mTitle_Text.get_Global_text_Bounds().width / 2,
        mWindow.getSize().y * 0.125f
    );

    float gray_field_top = mWindow.getSize().y * 0.35f;
    float gray_field_height = mWindow.getSize().y * 0.4f;
    float option_spacing = gray_field_height / 5.0f;

    mContinue_Text.set_position(
        mWindow.getSize().x / 2.0f - mContinue_Text.get_Global_text_Bounds().width / 2,
        gray_field_top + option_spacing * 0.1f
    );

    mOptions_Text.set_position(
        mWindow.getSize().x / 2.0f - mOptions_Text.get_Global_text_Bounds().width / 2,
        gray_field_top + option_spacing * 1.6f
    );

    mBack_To_Title_Text.set_position(
        mWindow.getSize().x / 2.0f - mBack_To_Title_Text.get_Global_text_Bounds().width / 2,
        gray_field_top + option_spacing * 3.2f
    );
}

auto CPause_menu::draw() -> void
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

auto CPause_menu::handle_click_event(CGameplay& Gameplay, CPanel* Panel) -> void
{
    sf::Vector2f mouse_pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));

    if (mContinue_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        Gameplay.set_current_menu(nullptr);
    }
    else if (mOptions_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        Gameplay.set_current_menu(&Gameplay.get_menu_options());
    }
    else if (mBack_To_Title_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        Gameplay.set_current_menu(nullptr);
        Panel->set_scene(ESceneType::TITLE_SCREEN);
    }
}
