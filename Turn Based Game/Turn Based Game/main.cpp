#include "stdafx.h"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "Entity.h"
#include "Player.h"
#include "SpriteHandler.h"
#include "TileSet.h"

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
	GSprite::Camera = &camera;
	SpriteHandler::Window = &window;

	InputHandler inputState;
	SpriteHandler spriteHandler;

	bool gamePause = false;
	sf::Vector2i currentMousePosition;
	sf::Vector2i previousMousePosition = sf::Vector2i(0, 0);
	sf::Vector2i mouseVelocity;

	Entity::Pixel.SetTexture("Sprites/spr_pixel.png", 1);
	Entity::Pixel.SetAnimationSpeed(0);
	Entity::Camera = &camera;
	Entity::Input = &inputState;
	Camera::Input = &inputState;

	Player* player = new Player(50, 50);
	TileSet* Tiles = new TileSet(50, 50,4,4);

	while (window.isOpen())
	{
		sf::Event event;
		inputState.Update();
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

			if (event.type == sf::Event::LostFocus)
			{
				gamePause = true;
			}

			if (event.type == sf::Event::GainedFocus)
			{
				gamePause = false;
			}
			inputState.UpdateMouseWheel();
		}
		previousMousePosition = mouse.getPosition();
		//SET VIEW
		camera.SetView(-mouseVelocity / 2);

		//MAIN UPDATE LOOP
		if (true)//!gamePause
		{
			#pragma region
			//BEGIN UPDATE
			for (auto const &instance : Entity::SuperList)
			{
				for (size_t i = 0; i < instance.second->Size(); i++)
				{
					if (instance.second->FindAtIndex(i)->GetActive())
					{
						instance.second->FindAtIndex(i)->BeginUpdate();
					}
					
				}
			}
			//UPDATE
			for (auto const &instance : Entity::SuperList)
			{
				for (size_t i = 0; i < instance.second->Size(); i++)
				{
					if (instance.second->FindAtIndex(i)->GetActive())
					{
						instance.second->FindAtIndex(i)->Update();
					}
				}
			}

			//END UPDATE
			for (auto const &instance : Entity::SuperList)
			{
				for (size_t i = 0; i < instance.second->Size(); i++)
				{
					if (instance.second->FindAtIndex(i)->GetActive())
					{
						instance.second->FindAtIndex(i)->EndUpdate();
					}
				}
			}

			//"DRAW"
			for (auto const &instance : Entity::SuperList)
			{
				for (size_t i = 0; i < instance.second->Size(); i++)
				{
					if (instance.second->FindAtIndex(i)->GetActive())
					{
						instance.second->FindAtIndex(i)->Draw();
					}
				}
			}
			spriteHandler.SortDepth();
			#pragma endregion

			window.clear(Color(20, 80, 220, 1));
			//DRAW
			
			spriteHandler.DrawSprites();

			//depthShader.setUniform("depth", 1.0f);
			window.display();
		}
	
	}

	for (auto const &instance : Entity::SuperList)
	{
		for (size_t i = 0; i < instance.second->Size(); i++)
		{
			instance.second->DeleteAll();
		}
	}
	for (auto const &instance : Entity::SuperList)
	{
		delete instance.second;
	}
	Entity::SuperList.clear();

	return 0;
}