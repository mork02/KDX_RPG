#include "gameplay.h"
// #include "collision.h"

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
    sf::Color color1 = sf::Color(190, 190, 190);
    sf::Color color2 = sf::Color(100, 100, 100);

    for (unsigned y = 0; y < mWindow.getSize().y; y += 48)
    {
        for (unsigned x = 0; x < mWindow.getSize().x; x += 48)
        {
            sf::RectangleShape rect(sf::Vector2f(48.f, 48.f));
            rect.setPosition(static_cast<float>(x), static_cast<float>(y));

            if ((x / 48 + y / 48) % 2 == 0)
            {
                rect.setFillColor(color1);
            }
            else
            {
                rect.setFillColor(color2);
            }

            mWindow.draw(rect);
        }
    }
}

auto CGameplay::load_Entities() -> void
{
    mEntities.reserve(10);
    mEntities.push_back(std::move(std::make_unique<CGoblin>(mWindow)));
}

auto CGameplay::set_menu(EMenuState MenuState) -> void
{
    if (MenuState == EMenuState::PAUSE)   mNew_Menu = mPause_Menu.get();
    if (MenuState == EMenuState::STATS)   mNew_Menu = mStats_Menu.get();
    if (MenuState == EMenuState::OPTIONS) mNew_Menu = mOption_Menu.get();
    if (MenuState == EMenuState::NULLPTR) mNew_Menu = nullptr;
    
    if (mCurrent_Menu == mNew_Menu) {
        if (mCurrent_Menu) mCurrent_Menu->set_visible(false);
        mCurrent_Menu = nullptr;
        return;
    }

    if (mCurrent_Menu) {
        mCurrent_Menu->set_visible(false);
    }

    mCurrent_Menu = mNew_Menu;

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

auto CGameplay::handle_events(CGameManager& GameManager, sf::Event& Event) -> void
{
    if (Event.type == sf::Event::MouseButtonPressed)
    {
        if (Event.key.code == sf::Mouse::Left)
        {
            if (mCurrent_Menu)  mCurrent_Menu->handle_events(*this, &GameManager);
        }
    }

    mWarrior.get()->handle_events(mWindow, Event);

    if (Event.type == sf::Event::KeyPressed) {
        if (Event.key.code == sf::Keyboard::Escape)   set_menu(EMenuState::PAUSE);
        if (Event.key.code == sf::Keyboard::G)   set_menu(EMenuState::STATS);
    }
}

auto CGameplay::render() -> void
{
    load_Level();
    for (auto& entity : mEntities)
    {
        entity->render();
    }
    mWarrior->render();
    if (mCurrent_Menu) mCurrent_Menu->draw();
}

auto CGameplay::update(float delta_time) -> void
{
    for (auto& entity : mEntities)
    {
        entity->update(delta_time);
    }
    mWarrior->update(delta_time);
    // mCamera.update(mWarrior.get());

    
    // TODO: add collusion class to detect collusion between entities
}
