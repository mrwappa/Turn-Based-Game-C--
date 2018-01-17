#include "stdafx.h"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "GSprite.h"
#include "Entity.h"
#include "Player.h"

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

	Entity::Window = &window;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;

	GSprite::DepthShader = &depthShader;
	GSprite::Window = &window;
	
	Player* player = new Player(50,50);



	while (window.isOpen())
	{
		sf::Event event;
		Entity::Event = &event;

		Keyboard keyboardState;
		Mouse mouseState;
		Entity::MouseState = &mouseState;
		Entity::KeyboardState = &keyboardState;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

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

/*std::vector<double> bruh;
bruh.begin();
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
