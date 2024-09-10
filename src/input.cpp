#include "input.h"

Input::Input(sf::RenderWindow& window_c, Player& user_c)
	: window(window_c), user(user_c)
{}

// Getter

sf::Mouse Input::get_mouse() const { return mouse; }

sf::Vector2f Input::get_mouse_position() const { return window.mapPixelToCoords(mouse.getPosition(window)); }

sf::Keyboard Input::get_keyboard() const { return keyboard; }

bool Input::get_isKeyPressed() const { return isKeyPressed; }

bool Input::get_isMousePressed() const { return isMousePressed; }

// Setter

void Input::set_isKeyPressed(bool value) 
{
	isKeyPressed = value;
}

void Input::set_isMousePressed(bool value) 
{
	isMousePressed = value;
}

// Methods

bool Input::is_mouse_button_pressed(sf::Mouse::Button button) const
{
	return mouse.isButtonPressed(button);
}
