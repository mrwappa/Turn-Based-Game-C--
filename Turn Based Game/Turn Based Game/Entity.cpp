#include "stdafx.h"
#include "Entity.h"

std::map<std::string, GrowingArray<Entity*>*> Entity::SuperList;

sf::Mouse* Entity::MouseState;
sf::Keyboard* Entity::KeyboardState;
sf::Event* Entity::Event;
sf::RenderWindow* Entity::Window;

Entity::Entity(float aX, float aY)
{
	myX = aX;
	myY = aY;
	myAnimationSpeed = 0;
	myDepth = 0;
	myAngle = 0;
	myDepth = 0;
	myXScale = 1;
	myYScale = 1;
	myColor = sf::Color::White;
	GrArrayPtr = nullptr;
	AddInstance(this);
}


Entity::~Entity()
{
}

void Entity::AddInstance(Entity* aEntity)
{
	//check if key doesnt exist
	if (SuperList.count(typeid(aEntity).name()) == 0)
	{
		SuperList[typeid(aEntity).name()] = new GrowingArray<Entity*>;
	}
	GrArrayPtr = SuperList.at(typeid(aEntity).name());
	GrArrayPtr->Add(aEntity);
	GrArrayPtr = nullptr;
}

void Entity::DestroyInstance(Entity* aEntity)
{
	GrArrayPtr = SuperList.at(typeid(aEntity).name());
	GrArrayPtr->RemoveCyclic(aEntity);
	GrArrayPtr = nullptr;
}

//Init,Update,Draw
void Entity::Init()
{
	
}

void Entity::BeginUpdate()
{

}

void Entity::Update()
{

}

void Entity::EndUpdate()
{

}

void Entity::Draw()
{
	mySprite.SetAnimationSpeed(myAnimationSpeed);
	mySprite.Draw(myX, myY, myXScale, myYScale, myAngle, myDepth, myColor);
}

void Entity::DrawGUI()
{

}

bool Entity::KeyboardCheck(sf::Keyboard::Key aKey)
{
	if (KeyboardState->isKeyPressed(aKey))
	{
		return true;
	}
	return false;
}

bool Entity::KeyboardCheckPressed(sf::Keyboard::Key aKey)
{
	/*if (KeyboardState->isKeyPressed(aKey) and !PreviousKeyboardState->isKeyPressed(aKey))
	{
		return true;
	}
	return false;*/
	/*if (Event->type == sf::Event::KeyPressed and Event->key.code == aKey)
	{
		return true;
	}*/

	if (Event->type == sf::Event::KeyPressed)
	{
		if (Event->key.code == aKey)
		{
			return true;
		}
	}
	return false;
	
}

bool Entity::MouseCheck(sf::Mouse::Button aButton)
{
	if (MouseState->isButtonPressed(aButton))
	{
		return true;
	}
	return false;
}

bool Entity::MouseCheckPressed(sf::Mouse::Button aButton)
{
	
	return false;
}
