#include "gameplay.h"

CGameplay::CGameplay(sf::RenderWindow& Window)
    : mWindow(Window), mCamera(Window)

{
    mPause_Menu = std::make_unique<CPause_menu>(Window);
    mStats_Menu = std::make_unique<CStats_menu>(Window);
    mOption_Menu = std::make_unique<COption_menu>(Window);

    mWarrior = std::make_unique<CWarrior>(Window);
    load_Entities();
}

auto CGameplay::load_Level() -> void
{
    // TODO: load level
}

auto CGameplay::load_Entities() -> void
{
    mEntities.reserve(10);
    mEntities.push_back(std::move(std::make_unique<CGoblin>(mWindow)));
}

auto CGameplay::get_menu_options() -> COption_menu&
{
    return *mOption_Menu;
}

auto CGameplay::get_menu_pause() -> CPause_menu&
{
    return *mPause_Menu;
}

auto CGameplay::get_menu_stats() -> CStats_menu&
{
    return *mStats_Menu;
}

auto CGameplay::set_current_menu(CMenu* new_menu) -> void
{
    if (mCurrent_Menu == new_menu)
    {
        mCurrent_Menu->set_visible(false);
        mCurrent_Menu = nullptr;
        return;
    }

    if (mCurrent_Menu)  mCurrent_Menu->set_visible(false);

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

auto CGameplay::event_mouse(sf::Event& Event, CPanel* Panel) -> void
{
    if (mCurrent_Menu)  mCurrent_Menu->handle_click_event(*this, Panel);
    // TODO: add mouse input
}

auto CGameplay::event_keyboard(sf::Event& Event) -> void
{
    mWarrior->set_direction(Event);
    if (Event.key.code == sf::Keyboard::Escape)   set_current_menu(mPause_Menu.get());
    if (Event.key.code == sf::Keyboard::G)   set_current_menu(mStats_Menu.get());
}


auto CGameplay::update(float delta_time) -> void
{
    // TODO: add collusion class to detect collusion between entities

    for (auto& entity : mEntities)
    {
        entity->get_Asset().draw();
    }
    
    mWarrior->update(delta_time);
    // mCamera.update(mWarrior.get());
    if (mCurrent_Menu) mCurrent_Menu->draw();
}
