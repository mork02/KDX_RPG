#include "panel.h"

CPanel::CPanel(sf::RenderWindow& Window, sf::Event& Event)
    : mWindow(Window), mEvent(Event),
    mTitle_Screen(Window),
    mGameplay(Window)
{
    // TODO: move all menus into gameplay
    // cuz menus only appear when player is in game
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

auto CPanel::handle_events() -> void
{
    switch (mEvent.type)
    {
        case sf::Event::Closed:
            event_close();
            break;

        case sf::Event::KeyPressed:
            event_keyboard();
            break;

        case sf::Event::KeyReleased:
            break;

        case sf::Event::MouseButtonPressed:
            event_mouse();
            break;

        case sf::Event::MouseButtonReleased:
            break;

        default:
            break;
        }
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
    if (mEvent.mouseButton.button == sf::Mouse::Left)
    {
        if (mCurrent_Scene == ESceneType::Title_screen)
        {
            // handle left click on Titlescreen //
            mTitle_Screen.handle_click_event(*this);
        }
        if (mCurrent_Scene == ESceneType::Gameplay)
        {
            // handle left click on Gameplay //
            if (mCurrent_Menu)  mCurrent_Menu->handle_click_event(*this);
            mGameplay.event_mouse(mEvent);
        }
    }
    if (mEvent.mouseButton.button == sf::Mouse::Right)
    {
        // handle right clicks //
    }

}

auto CPanel::event_keyboard() -> void
{
    if (mEvent.type == sf::Event::KeyPressed || mEvent.type == sf::Event::KeyReleased)
    {
        if (mCurrent_Scene == ESceneType::Gameplay)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))   set_current_menu(mPause_Menu.get());
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))    set_current_menu(mStats_Menu.get());
            mGameplay.event_keyboard(mEvent);
        }
        handle_window_resolution();
    }
}

auto CPanel::handle_window_resolution() -> void
{
    // handle keyboard input for changing Window Resolution
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))   mWindow.setSize(sf::Vector2u(720, 480));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))   mWindow.setSize(sf::Vector2u(1080, 720));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))   mWindow.setSize(sf::Vector2u(1920, 1080));
}