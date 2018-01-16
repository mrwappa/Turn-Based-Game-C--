#include "stdafx.h"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "GSprite.h"
#include "Entity.h"

using namespace sf;

int main()
{

	sf::Shader depthShader;
	depthShader.loadFromFile("Shaders/vertex_shader.vert", sf::Shader::Type::Vertex);

	int width = sf::VideoMode::getDesktopMode().width;
	int height = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(width, height), "WINDOW", sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	
	GSprite::DepthShader = &depthShader;
	GSprite::Window = &window;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
		/*std::map<std::string, GrowingArray<Entity*>*>::iterator it;
		for (it = Entity::SuperList.begin(); it != Entity::SuperList.end(); it++)
		{
			for (size_t i = 0; i < it->second->Size(); i++)
			{
				it->second[i]->Update();
			}
		}*/

		/*for (std::map<std::string, GrowingArray<Entity*>*>::iterator ii = Entity::SuperList.begin(); ii != Entity::SuperList.end(); ++ii)
		{
			std::cout << ii->first << ": " << std::endl;
			for (GrowingArray<Entity*>*>::iterator it = ii->second.begin(); it != ii->second.end(); ++it) {
				std::cout << *it << endl;
			}
		}*/

		
		for (const auto &p : Entity::SuperList)
		{
			std::cout << p.first << " :";
			for (const auto &s : p.second)
			{
				
			}
			for (size_t i = 0; i < p.second->Size(); i++)
			{
				p->second[i]->Update();
			}
		}

		/*for (auto const&[key, val] : symbolTable)
		{
			std::cout << key         // string (key)
				<< ':'
				<< val        // string's value
				<< std::endl;
		}*/
		window.clear(Color(20, 80, 220, 1));
		//window.draw(shape);
		window.display();
	}

	return 0;
}
