#include <iostream>
#include "player_movement.h"

CPlayer_Movement::CPlayer_Movement() :
	CMovement()
{}

void CPlayer_Movement::handle_movement(float delta_time, CAsset_loader& Asset)
{
    if (mMoving)
    {
        bool x_done = std::abs(mPosition.x - mTargeted_Position.x) <= 5.0f;
        bool y_done = std::abs(mPosition.y - mTargeted_Position.y) <= 5.0f;

        if (!x_done)
        {
            mPosition.x += (mPosition.x < mTargeted_Position.x ? 1 : -1) * mMovement_Speed * delta_time;
            Asset.set_animation_param(EAnimation_Warrior::A_RIGHT, EAnimation_Warrior::L_RIGHT);
            Asset.set_direction(mPosition.x < mTargeted_Position.x);
        }

        else if (!y_done)
        {
            mPosition.y += (mPosition.y < mTargeted_Position.y ? 1 : -1) * mMovement_Speed * delta_time;
            Asset.set_animation_param(EAnimation_Warrior::A_DOWN, EAnimation_Warrior::L_DOWN);
        }

        if (x_done && y_done)
        {
            Asset.set_animation_param(EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE);
            mMoving = false;
        }
    }
}


auto CPlayer_Movement::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
    if (Event.type == sf::Event::MouseButtonPressed && Event.key.code == sf::Mouse::Left)
    {
        sf::Vector2f mouse_pos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));

        mTargeted_Position.x = std::round((mouse_pos.x - 48) / 96) * 96 + 48;
        mTargeted_Position.y = std::round((mouse_pos.y - 48) / 96) * 96 + 48;

        mMoving = true;
    }
}

auto CPlayer_Movement::update(float delta_time, CAsset_loader& Asset) -> void
{
	handle_movement(delta_time, Asset);
}

