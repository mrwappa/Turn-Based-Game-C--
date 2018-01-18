#include "stdafx.h"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "GSprite.h"
#include "Entity.h"
#include "Player.h"
#include "Camera.h"


using namespace sf;

int main()
{
	//check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	sf::Shader depthShader;
	depthShader.loadFromFile("Shaders/vertex_shader.vert", sf::Shader::Type::Vertex);

	int width = sf::VideoMode::getDesktopMode().width;
	int height = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(width, height), "WINDOW", sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(true);
	window.setKeyRepeatEnabled(true);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	Camera::Window = &window;
	Camera camera(0,0);

	GSprite::DepthShader = &depthShader;
	GSprite::Window = &window;
	
	Player* player = new Player(50,50);

	InputHandler inputState;

	
	sf::Vector2i currentMousePosition;
	sf::Vector2i previousMousePosition = Vector2i(0, 0);
	sf::Vector2i mouseVelocity;

	while (window.isOpen())
	{
		sf::Event event;
		inputState.Update();
		Entity::Input = &inputState;
		Camera::Input = &inputState;
		InputHandler::Event = &event;
		Mouse mouse;
		
		currentMousePosition = mouse.getPosition();
		mouseVelocity = currentMousePosition - previousMousePosition;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::MouseWheelMoved)
			{
				// display number of ticks mouse wheel has moved
				std::cout << event.mouseWheel.delta << '\n';
			}
			inputState.UpdateMouseWheel();

		}

		//MAIN UPDATE LOOP
		#pragma region
		//BEGIN UPDATE
		for (auto const &instance : Entity::SuperList)
		{
			for (size_t i = 0; i < instance.second->Size(); i++)
			{
				//okej c++, du vägrar att kunna använda vanlig, acceptabel eller logisk syntax för index[] operatorer med maps, och därför måste jag uppenbarligen
				//göra något lika retarderat tillbaks för att få dig att funka...som att lägga till en FindAtIndex funktion som inte alls behövs eftersom jag har en
				//FUCKING INDEX OVERRIDE OPERATOR SOM SKA GÖRA DETTA JOBBET. MEN NEJ, DU VAR BARA TVUNGEN ATT SKITA NER ÖVER ALLT DET...kuksmaskare
				instance.second->FindAtIndex(i)->BeginUpdate();

			}
		}
		//UPDATE
		for (auto const &instance : Entity::SuperList)
		{
			for (size_t i = 0; i < instance.second->Size(); i++)
			{
				instance.second->FindAtIndex(i)->Update();
			}
		}

		//END UPDATE
		for (auto const &instance : Entity::SuperList)
		{
			for (size_t i = 0; i < instance.second->Size(); i++)
			{
				instance.second->FindAtIndex(i)->EndUpdate();
			}
		}
		#pragma endregion

		previousMousePosition = mouse.getPosition();
		//SET VIEW
		camera.SetView(-mouseVelocity/2);

		window.clear(Color(20, 80, 220, 1));
		//DRAW
		for (auto const &instance : Entity::SuperList)
		{
			for (size_t i = 0; i < instance.second->Size(); i++)
			{
				instance.second->FindAtIndex(i)->Draw();
			}
		}
		window.display();
	}

	for (auto const &instance : Entity::SuperList)
	{
		for (size_t i = 0; i < instance.second->Size(); i++)
		{
			instance.second->DeleteAll();
		}
	}
	Entity::SuperList.clear();

	return 0;
}