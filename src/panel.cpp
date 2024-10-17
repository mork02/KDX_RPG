#include "panel.h"

CPanel::CPanel(sf::RenderWindow& Window, CInput& Input)
    : mWindow(Window), mInput(Input),
    mTitle_Screen(Window, Input),
    mGameplay(Window)
{
    mPause_Menu = std::make_unique<CPause_menu>(Window);
    mStats_Menu = std::make_unique<CStats_menu>(Window);
    mOption_Menu = std::make_unique<COption_menu>(Window);
}

auto CPanel::update() -> void
{ 
    switch (mScene)
    {
    case ESceneType::Title_screen:
        mTitle_Screen.draw(*this);
        break;
    case ESceneType::Gameplay:
        mGameplay.update();
        if (mCurrent_Menu) { mCurrent_Menu->draw(); }
        break;
    case ESceneType::Game_Over:
        break;
    }

}

auto CPanel::get_stats_menu() -> CStats_menu&
{
    return *mStats_Menu;
}

auto CPanel::get_pause_menu() -> CPause_menu&
{
    return *mPause_Menu;
}

auto CPanel::get_options_menu() -> COption_menu&
{
    return *mOption_Menu;
}

auto CPanel::get_title_screen() -> CTitle_Screen&
{
    return mTitle_Screen;
}

auto CPanel::get_gameplay() -> Gameplay&
{
    return mGameplay;
}

auto CPanel::get_input() -> CInput&
{
    return mInput;
}

auto CPanel::get_scene() -> ESceneType&
{
    return mScene;
}

auto CPanel::get_current_menu() -> CMenu*
{
    return mCurrent_Menu;
}

auto CPanel::set_scene(ESceneType new_scene) -> void
{
    mScene = new_scene;
}

auto CPanel::set_current_menu(CMenu* new_menu) -> void {
    if (mCurrent_Menu) { mCurrent_Menu->set_visible(false); }

    if (!new_menu) 
    {
        mCurrent_Menu = nullptr;
        return;
    }

    try {
        mCurrent_Menu = new_menu;
        mCurrent_Menu->set_visible(true);
    }
    catch (const std::exception& e) { std::cerr << "Error setting current menu visibility: " << e.what() << std::endl; }
}