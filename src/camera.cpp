#include "camera.h"

CCamera::CCamera(sf::RenderWindow& Window) : mWindow(Window), mMoveSpeed(0.05f)
{
    mCamera = Window.getDefaultView();
    mCamera.zoom(mCamera_Zoom);
}

auto CCamera::get_camera() -> sf::View&
{
    return mCamera;
}

auto CCamera::update(CEntity* entity) -> void
{
    sf::Vector2f targetPosition(
        entity->get_Asset().get_Sprite().getGlobalBounds().left + entity->get_Asset().get_Texture().getSize().x / 2,
        entity->get_Asset().get_Sprite().getGlobalBounds().top + entity->get_Asset().get_Texture().getSize().y / 2
    );

    sf::Vector2f currentPosition = mCamera.getCenter();
    sf::Vector2f newPosition = currentPosition + mMoveSpeed * (targetPosition - currentPosition);

    mCamera.setCenter(newPosition);
    mWindow.setView(mCamera);
}
