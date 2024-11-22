#include "menu_manager.h"

CMenuManager::CMenuManager(sf::RenderWindow& Window) : 
	mWindow(Window)
{}

auto CMenuManager::set_menu(CMenu* new_Menu) -> void
{
    if (mCurrent_Menu == new_Menu) {
        if (mCurrent_Menu) mCurrent_Menu->set_visible(false);
        mCurrent_Menu = nullptr;
        return;
    }

    if (mCurrent_Menu) {
        mCurrent_Menu->set_visible(false);
    }

    mCurrent_Menu = new_Menu;

    if (mCurrent_Menu) {
        try {
            mCurrent_Menu->set_visible(true);
        }
        catch (const std::exception& e) {
            std::cerr << "Error setting current menu visibility: " << e.what() << std::endl;
            mCurrent_Menu = nullptr;
        }
    }
}

auto CMenuManager::get_pause_menu() -> CPause_menu*
{
    return mPause_Menu.get();
}

auto CMenuManager::get_option_menu() -> COption_menu*
{
    return mOption_Menu.get();
}

auto CMenuManager::get_stats_menu() -> CStats_menu*
{
    return mStats_Menu.get();
}

auto CMenuManager::handle_events(sf::Event& Event, CStateManager* StateManager) -> void
{
    if (Event.type == sf::Event::MouseButtonPressed)
    {
        if (Event.key.code == sf::Mouse::Left)
        {
            if (mCurrent_Menu)  mCurrent_Menu->handle_events(Event, *this, StateManager);
        }
    }
    if (Event.type == sf::Event::KeyPressed) {
        if (Event.key.code == sf::Keyboard::Escape) set_menu(get_pause_menu());
        if (Event.key.code == sf::Keyboard::G)      set_menu(get_stats_menu());
    }
}

auto CMenuManager::update(float delta_time) -> void
{
}

auto CMenuManager::render() -> void
{
    if (mCurrent_Menu) mCurrent_Menu->render();
}
