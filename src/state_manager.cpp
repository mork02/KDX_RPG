#include "state_manager.h"

CStateManager::CStateManager(sf::RenderWindow& Window) :
	mState(nullptr),
	mGameplay(std::make_unique<CGameplay>(Window)), 
	mTitle_Screen(std::make_unique<CTitle_Screen>(Window))
{}

auto CStateManager::set_state(CState* State) -> void
{
	mState = State;
}

auto CStateManager::get_gameplay() -> CGameplay*
{
	return mGameplay.get();
}

auto CStateManager::get_title_screen()->CTitle_Screen*
{
	return mTitle_Screen.get();
}

auto CStateManager::handle_events(sf::Event& Event) -> void
{
	if (mState)
	{
		mState->handle_events(Event, *this);
	}
}

auto CStateManager::update(float delta_time) -> void
{
	if (mState)
	{
		mState->update(delta_time);
	}
}

auto CStateManager::render() -> void
{
	if (mState)
	{
		mState->render();
	}
}
