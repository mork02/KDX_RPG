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
        entity->get_Asset().get_Sprite().getGlobalBounds().left,
        entity->get_Asset().get_Sprite().getGlobalBounds().top
    );

    sf::Vector2f currentPosition = mCamera.getCenter();
    sf::Vector2f newPosition = currentPosition + mMoveSpeed * (targetPosition - currentPosition);

    float map_StartX = mCamera.getSize().x / 2;
    float map_StartY = mCamera.getSize().y / 2;
    float map_ENDX = mWindow.getSize().x - mCamera.getSize().x / 2;
    float map_ENDY = mWindow.getSize().y - mCamera.getSize().y / 2;

    newPosition.x = std::max(map_StartX, std::min(newPosition.x, map_ENDX));
    newPosition.y = std::max(map_StartY, std::min(newPosition.y, map_ENDY));

    mCamera.setCenter(newPosition);
    mWindow.setView(mCamera);
}

auto CCamera::reset() -> void
{
    mWindow.setView(mWindow.getDefaultView());
}
