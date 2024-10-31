#include "panel.h"

CPanel::CPanel(sf::RenderWindow& Window, sf::Event& Event)
    : mWindow(Window), mEvent(Event), mInput(),
    mTitle_Screen(Window),
    mGameplay(Window, mInput)
{
    mPause_Menu = std::make_unique<CPause_menu>(Window);
    mStats_Menu = std::make_unique<CStats_menu>(Window);
    mOption_Menu = std::make_unique<COption_menu>(Window);
}

auto CPanel::update() -> void
{
    switch (mCurrent_Scene)
    {
    case ESceneType::Title_screen:
        mTitle_Screen.draw();
        break;
    case ESceneType::Gameplay:
        mGameplay.update();
        break;
    case ESceneType::Game_Over:
        break;
    }

    if (mCurrent_Menu) mCurrent_Menu->draw();
}

// getter

auto CPanel::get_option_menu() -> COption_menu&
{
    return *mOption_Menu;
}

auto CPanel::get_pause_menu() -> CPause_menu&
{
    return *mPause_Menu;
}

auto CPanel::get_stats_menu() -> CStats_menu&
{
    return *mStats_Menu;
}

// setter

auto CPanel::set_scene(ESceneType new_scene) -> void
{
    mCurrent_Scene = new_scene;
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

// events

auto CPanel::handle_event() -> void
{
    event_close();
    event_mouse();
    event_keyboard();
}

auto CPanel::event_close() -> void
{
    if (mEvent.type == sf::Event::Closed)
    {
        mWindow.close();
    }
}

auto CPanel::event_mouse() -> void
{
    if (mEvent.type == sf::Event::MouseButtonPressed 
        && mEvent.mouseButton.button == sf::Mouse::Left 
        && mCurrent_Scene == ESceneType::Title_screen)
    {
        mTitle_Screen.handle_click_event(*this, mInput);
    }

    if (mEvent.type == sf::Event::MouseButtonPressed 
        && mEvent.mouseButton.button == sf::Mouse::Left
        && mCurrent_Scene == ESceneType::Gameplay)
    {
        if (mCurrent_Menu)  mCurrent_Menu->handle_click_event(*this);
        else    mGameplay.handle_mouse_input();
    }

}

auto CPanel::event_keyboard() -> void
{
    if (mEvent.type == sf::Event::KeyPressed 
        && mCurrent_Scene == ESceneType::Gameplay)
    {
        if (mInput.get_keyboard().isKeyPressed(mInput.get_keyboard().Escape))
        {
            set_current_menu(mPause_Menu.get());
        }
        if (mInput.get_keyboard().isKeyPressed(mInput.get_keyboard().G))
        {
            set_current_menu(mStats_Menu.get());
        }
    }
}