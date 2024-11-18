#include <iostream>
#include "player_movement.h"

CPlayer_Movement::CPlayer_Movement() :
	CMovement()
{}

void CPlayer_Movement::handle_movement(float delta_time, CAsset_loader& Asset)
{
    if (std::abs(mPosition.x - mTargeted_Position.x) > 10.0f)
    {
        if (mPosition.x < mTargeted_Position.x)
        {
            mPosition.x += mMovement_Speed * delta_time;
            Asset.set_animation_param(EAnimation_Warrior::A_RIGHT, EAnimation_Warrior::L_RIGHT);
            Asset.set_direction(true);
        }
        else if (mPosition.x > mTargeted_Position.x)
        {
            mPosition.x -= mMovement_Speed * delta_time;
            Asset.set_animation_param(EAnimation_Warrior::A_LEFT, EAnimation_Warrior::L_LEFT);
            Asset.set_direction(false);
        }
    }

    else if (std::abs(mPosition.y - mTargeted_Position.y) > 10.0f)
    {
        if (mPosition.y < mTargeted_Position.y)
        {
            mPosition.y += mMovement_Speed * delta_time;
            Asset.set_animation_param(EAnimation_Warrior::A_DOWN, EAnimation_Warrior::L_DOWN);
        }
        else if (mPosition.y > mTargeted_Position.y)
        {
            mPosition.y -= mMovement_Speed * delta_time;
            Asset.set_animation_param(EAnimation_Warrior::A_UP, EAnimation_Warrior::L_UP);
        }
    }

    if (std::abs(mPosition.x - mTargeted_Position.x) <= 10.0f &&
        std::abs(mPosition.y - mTargeted_Position.y) <= 10.0f)
    {
        Asset.set_animation_param(EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE);
    }

}

auto CPlayer_Movement::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
	if (Event.type == sf::Event::MouseButtonPressed)
		if (Event.key.code == sf::Mouse::Left)
		{
			mTargeted_Position = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));
		}
}

auto CPlayer_Movement::update(float delta_time, CAsset_loader& Asset) -> void
{
	handle_movement(delta_time, Asset);
}

