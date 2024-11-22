#include "title_screen_state.h"
#include "game_manager.h"

CTitle_Screen::CTitle_Screen(sf::RenderWindow& Window) :
    CState(),
    mWindow(Window),
    mAsset(Window),
    mTitle_Text(Window, "KDX RPG", ECharacter_Size::LARGE, false),
    mNew_Game_Text(Window, "New Game", ECharacter_Size::MEDIUM, true),
    mOptions_Text(Window, "Options", ECharacter_Size::MEDIUM , true),
    mQuit_Text(Window, "Quit", ECharacter_Size::MEDIUM, true)
{
    mAsset.init_asset(mBackground_Path);
    scale_background();
    position_texts();
}


auto CTitle_Screen::render() -> void
{
    mMouse_Position = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
    
    for (auto const asset : get_asset_components())
    {
        mWindow.draw(asset.get().get_Sprite());
    }

    for (auto const& text : get_text_components())
    {
        text.get().render();
    }
    
    animate_title_text();

}

auto CTitle_Screen::update(float delta_time) -> void
{
}

auto CTitle_Screen::scale_background() -> void
{
    sf::Vector2u windowSize = mWindow.getSize();
    sf::Vector2u textureSize = mAsset.get_Texture().getSize();

    mAsset.get_Sprite().setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
}

auto CTitle_Screen::position_texts() -> void
{
    sf::Vector2u windowSize = mWindow.getSize();

    mTitle_Text.set_position(
        static_cast<float>(windowSize.x / 2.0f - mTitle_Text.get_Global_text_Bounds().width / 2.0f),
        static_cast<float>(windowSize.y * 0.01f)
    );

    float gray_field_top = windowSize.y * 0.35f;
    float gray_field_height = windowSize.y * 0.4f;
    float option_spacing = gray_field_height / 3.0f;

    mNew_Game_Text.set_position(
        static_cast<float>(windowSize.x / 2.0f - mNew_Game_Text.get_Global_text_Bounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 0.1f - 75)
    );

    mOptions_Text.set_position(
        static_cast<float>(windowSize.x / 2.0f - mOptions_Text.get_Global_text_Bounds().width / 2.0f),
        static_cast<float>(gray_field_top + option_spacing * 1.5f - 75)
    );

    mQuit_Text.set_position(
        static_cast<float>(windowSize.x / 2.0f - mQuit_Text.get_Global_text_Bounds().width / 2.0f),
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

    sf::Color color = mTitle_Text.get_color();
    color.a = static_cast<sf::Uint8>(mFade_Alpha);
    mTitle_Text.set_color(color);
}

auto CTitle_Screen::handle_events(sf::Event& Event, CStateManager& StateManager) -> void
{
    if (Event.type == sf::Event::MouseButtonPressed)
    {
        if (Event.key.code == sf::Mouse::Left)
        {
            if (mNew_Game_Text.get_Global_text_Bounds().contains(mMouse_Position.x, mMouse_Position.y))
            {
                StateManager.set_state(StateManager.get_gameplay());
            }
            else if (mOptions_Text.get_Global_text_Bounds().contains(mMouse_Position.x, mMouse_Position.y))
            {
                std::cout << "Option!" << std::endl;
            }
            else if (mQuit_Text.get_Global_text_Bounds().contains(mMouse_Position.x, mMouse_Position.y))
            {
                std::cout << "Exit!" << std::endl;
                mWindow.close();
            }
        }
    }
}

auto CTitle_Screen::get_asset_components() -> std::vector<std::reference_wrapper<CAsset_loader>>
{
    return {
        { std::ref(mAsset) }
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