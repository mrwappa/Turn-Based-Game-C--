#ifndef CAMERA_H
#define CAMERA_H

#include "SFML\Graphics.hpp"
#include "InputHandler.h"
#include <iostream>
class Camera
{
public:
	Camera(float aX, float aY);
	~Camera();

	void SetView(sf::Vector2i aMouseVelocity);

	static sf::RenderWindow* Window;
	static InputHandler* Input;
	
	sf::View myView;

	float myX;
	float myY;

	int myIdealWidth;
	int myCorrespondingWidth;
	int myIdealHeight;
	int myWidth;
	int myHeight;

	int myMonitorWidth;
	int myMonitorHeight;
	float myAspectRatio;
	float myWidthDifference;

	float myZoom;
	float myScreenShake;

	bool KeyboardCheck(sf::Keyboard::Key aKey);
	bool KeyboardCheckPressed(sf::Keyboard::Key aKey);
	bool KeyboardCheckRelease(sf::Keyboard::Key aKey);
	bool KeyboardCheckReleased(sf::Keyboard::Key aKey);
	bool MouseCheck(sf::Mouse::Button aButton);
	bool MouseCheckPressed(sf::Mouse::Button aButton);
	bool MouseCheckRelease(sf::Mouse::Button aButton);
	bool MouseCheckReleased(sf::Mouse::Button aButton);

	bool MouseWheelUp();
	bool MouseWheelDown();
};
#endif // !CAMERA_H