#include "title_screen.h"
#include "scene_enum.h"
#include "panel.h"
#include "input.h"

CTitle_Screen::CTitle_Screen(sf::RenderWindow& Window) :
    mWindow(Window),
    mBackground_Asset(Window, mBackground_Path, false),
    mTitle_Text(Window, "KDX RPG", 168, false),
    mNew_Game_Text(Window, "New Game", 136, true),
    mOptions_Text(Window, "Options", 136, true),
    mQuit_Text(Window, "Quit", 136, true)
{
    scale_background();
    scale_text();
    position_texts();
}


auto CTitle_Screen::draw() -> void
{
    for (auto const asset : get_asset_components())
    {
        mWindow.draw(asset.get().get_Sprite());
    }
    
    animate_title_text();

    for (auto const& text : get_text_components())
    {
        text.get().draw_text();
    }
}

auto CTitle_Screen::scale_background() -> void
{
    sf::Vector2u windowSize = mWindow.getSize();
    sf::Vector2u textureSize = mBackground_Asset.get_Texture().getSize();

    mBackground_Asset.get_Sprite().setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
}

auto CTitle_Screen::scale_text() -> void
{
    // TODO: add scale text stuff
}

auto CTitle_Screen::position_texts() -> void
{
    sf::Vector2u windowSize = mWindow.getSize();

    mTitle_Text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - mTitle_Text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(windowSize.y * 0.01f)
    );

    float gray_field_top = windowSize.y * 0.35f;
    float gray_field_height = windowSize.y * 0.4f;
    float option_spacing = gray_field_height / 3.0f;

    mNew_Game_Text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - mNew_Game_Text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 0.1f - 75)
    );

    mOptions_Text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - mOptions_Text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 1.5f - 75)
    );

    mQuit_Text.get_text().setPosition(
        static_cast<float>(windowSize.x / 2.0f - mQuit_Text.get_text().getGlobalBounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 2.9f - 75)
    );
}

auto CTitle_Screen::animate_title_text() -> void
{
    if (mIncreasing) {
        mFade_Alpha += mFade_Increment;
    }
    if (mFade_Alpha > 255.0f && mIncreasing)
    {
        mFade_Alpha = 255.0f;
        mIncreasing = false;
    }

    sf::Color color = mTitle_Text.get_text().getFillColor();
    color.a = static_cast<sf::Uint8>(mFade_Alpha);
    mTitle_Text.get_text().setFillColor(color);
}

auto CTitle_Screen::handle_click_event(CPanel& panel, CInput& Input) -> void
{
    sf::Vector2f mouse_pos = Input.get_mouse_position(mWindow);

    if (mNew_Game_Text.get_Global_text_Bounds().contains(mouse_pos.x, mouse_pos.y))
    {
        panel.set_scene(ESceneType::Gameplay);
    }
    else if (mOptions_Text.get_Global_text_Bounds().contains(mouse_pos.x, mouse_pos.y))
    {
        std::cout << "Options clicked!" << std::endl;
    }
    else if (mQuit_Text.get_Global_text_Bounds().contains(mouse_pos.x, mouse_pos.y))
    {
        mWindow.close();
    }
}

auto CTitle_Screen::get_asset_components() -> std::vector<std::reference_wrapper<CAsset_loader>>
{
    return {
        { std::ref(mBackground_Asset) }
    };
}

auto CTitle_Screen::get_text_components() -> std::vector<std::reference_wrapper<CText>>
{
    return {
        { std::ref(mTitle_Text) },
        { std::ref(mNew_Game_Text) },
        { std::ref(mOptions_Text) },
        { std::ref(mQuit_Text) }
    };
}