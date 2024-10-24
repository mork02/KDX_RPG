#include "pause_menu.h"
#include "panel.h"

CPause_menu::CPause_menu(sf::RenderWindow& Window)
    : CMenu(Window, EMenuType::Pause),
    mBackground_Asset(Window, mBackground_Path),
    mTitle_Text("Pause", 109, false),
    mContinue_Text("Continue", 89, true),
    mOptions_Text("Options", 89, true),
    mBack_To_Title_Text("Back to Title", 89, true)
{
    mBackground_Asset.set_scale(mBackground_Scale);
    mBackground_Asset.center_asset();
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
        mWindow.getSize().x / 2.0f - mTitle_Text.get_text().getGlobalBounds().width / 2,
        mWindow.getSize().y * 0.15f
    );

    float gray_field_top = mWindow.getSize().y * 0.35f;
    float gray_field_height = mWindow.getSize().y * 0.4f;
    float option_spacing = gray_field_height / 5.0f;

    mContinue_Text.set_position(
        mWindow.getSize().x / 2.0f - mContinue_Text.get_text().getGlobalBounds().width / 2,
        gray_field_top + option_spacing * 0.1f
    );

    mOptions_Text.set_position(
        mWindow.getSize().x / 2.0f - mOptions_Text.get_text().getGlobalBounds().width / 2,
        gray_field_top + option_spacing * 1.6f
    );

    mBack_To_Title_Text.set_position(
        mWindow.getSize().x / 2.0f - mBack_To_Title_Text.get_text().getGlobalBounds().width / 2,
        gray_field_top + option_spacing * 3.2f
    );
}

auto CPause_menu::draw() -> void
{
    if (mVisible) 
    {
        mWindow.draw(mBackground_Asset.get_Sprite());

        for (const auto& text : get_text_components()) 
        {
            text.get().draw_text(mWindow);
        }
    }
}

auto CPause_menu::handle_click_event(CPanel& panel) -> void
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(mWindow);

    if (mContinue_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(nullptr);
    }
    else if (mOptions_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(&panel.get_options_menu());
    }
    else if (mBack_To_Title_Text.get_Global_text_Bounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        panel.set_current_menu(nullptr);
        panel.set_scene(ESceneType::Title_screen);
    }
}
