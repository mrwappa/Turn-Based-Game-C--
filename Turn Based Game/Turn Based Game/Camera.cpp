#include "stdafx.h"
#include "Camera.h"


sf::RenderWindow* Camera::Window;
InputHandler* Camera::Input;

Camera::Camera(float aX, float aY)
{
	myX = aX;
	myY = aY;
	myMonitorWidth = sf::VideoMode::getDesktopMode().width;
	myMonitorHeight = sf::VideoMode::getDesktopMode().height;

	myIdealHeight = 540;
	myCorrespondingWidth = 960;

	myAspectRatio = (float)myMonitorWidth / (float)myMonitorHeight;
	myIdealWidth = std::round(myIdealHeight*myAspectRatio);

	if (myIdealWidth % 2 != 0)
	{
		myIdealWidth++;
	}
	if (myIdealHeight % 2 != 0)
	{
		myIdealHeight++;
	}
	myWidthDifference = (float)myIdealWidth / (float)myCorrespondingWidth;


	myWidth = myIdealWidth / myWidthDifference;
	myHeight = myIdealHeight / myWidthDifference;

	myViewWidth = myWidth / myZoom;
	myViewHeight = myHeight / myZoom;

	myZoom = 1;
	myScreenShake = 0;

	myView.reset(sf::FloatRect(0, 0, myMonitorWidth, myMonitorHeight));
	myView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	myView.setSize(sf::Vector2f(myWidth, myHeight));
	myMouseX = myX - myViewWidth / 2 + sf::Mouse::getPosition().x / ((float)myMonitorWidth / (float)myViewWidth);
	myMouseY = myY - myViewHeight / 2 + sf::Mouse::getPosition().y / ((float)myMonitorHeight / (float)myViewHeight);

}



Camera::~Camera()
{
}

void Camera::SetView(sf::Vector2i aMouseVelocity)
{
	if (MouseWheelUp())
	{
		myZoom += 0.095f * myZoom;
	}
	if (MouseWheelDown())
	{
		myZoom -= 0.095f * myZoom;
	}
	if (KeyboardCheckPressed(sf::Keyboard::Space))
	{
		myZoom = 1;
	}
	if (MouseCheck(sf::Mouse::Left))
	{
		myX += aMouseVelocity.x/myZoom;
		myY += aMouseVelocity.y/myZoom;
	}
	

	myViewWidth = myWidth / myZoom;
	myViewHeight = myHeight / myZoom;
	myMouseX = myX - myViewWidth / 2 + sf::Mouse::getPosition().x / ((float)myMonitorWidth / (float)myViewWidth);
	myMouseY = myY - myViewHeight / 2 + sf::Mouse::getPosition().y / ((float)myMonitorHeight / (float)myViewHeight);
	myView.setCenter(myX, myY);
	myView.setSize(sf::Vector2f(myViewWidth, myViewHeight));
	Window->setView(myView);
	
}

bool Camera::KeyboardCheck(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] > 0;
}

bool Camera::KeyboardCheckPressed(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] == 2;
}

bool Camera::KeyboardCheckRelease(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] == -1;
}

bool Camera::KeyboardCheckReleased(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] == 0;
}

bool Camera::MouseCheck(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] > 0;
}

bool Camera::MouseCheckPressed(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] == 2;
}

bool Camera::MouseCheckRelease(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] == -1;
}

bool Camera::MouseCheckReleased(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] == 0;
}

bool Camera::MouseWheelUp()
{
	return Input->MouseWheelUp;
}

bool Camera::MouseWheelDown()
{
	return Input->MouseWheelDown;
}
