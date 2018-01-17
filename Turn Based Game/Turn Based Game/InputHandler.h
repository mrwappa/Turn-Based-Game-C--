#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include "SFML\Window.hpp"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	static sf::Mouse* MouseState;
	static sf::Keyboard* KeyboardState;
	static sf::Event* Event;

	bool KeyboardCheck(sf::Keyboard::Key aKey);
	bool KeyboardCheckPressed(sf::Keyboard::Key aKey);
	bool KeyboardCheckRelease(sf::Keyboard::Key aKey);
	bool KeyboardCheckReleased(sf::Keyboard::Key aKey);
	bool MouseCheck(sf::Mouse::Button aButton);
	bool MouseCheckPressed(sf::Mouse::Button aButton);
	bool MouseCheckRelease(sf::Mouse::Button aButton);
	bool MouseCheckReleased(sf::Mouse::Button aButton);
};
#endif // !INPUT_HANDLER