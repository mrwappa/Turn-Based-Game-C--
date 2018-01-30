#include "stdafx.h"
#include "Entity.h"

std::map<std::string, GrowingArray<Entity*>*> Entity::SuperList;
std::map<std::string, GrowingArray<Entity*>*> Entity::ClassHierarchy;
InputHandler* Entity::Input;
GrowingArray<Entity*>* Entity::GrArrayPtr;
Camera* Entity::Camera;
GSprite Entity::Pixel;

Entity::Entity(std::string aName)
{
	myAnimationSpeed = 0;
	myDepth = 0;
	myAngle = 0;
	myDepth = 0;
	myXScale = 1;
	myYScale = 1;
	myAlpha = 1;
	myColor = sf::Color::White;
	GrArrayPtr = nullptr;
	myName = aName;
	AddInstance(this,aName);
}


Entity::~Entity()
{
}

void Entity::AddInstance(Entity* aEntity, std::string aName)
{
	//check if key doesnt exist
	if (SuperList.count(aName) == 0)
	{
		SuperList[aName] = new GrowingArray<Entity*>;
	}
	GrArrayPtr = SuperList.at(aName);
	GrArrayPtr->Add(aEntity);
	GrArrayPtr = nullptr;
}

void Entity::DestroyInstance(Entity* aEntity)
{
	GrArrayPtr = SuperList.at(aEntity->GetName());
	GrArrayPtr->DeleteCyclic(aEntity);
	GrArrayPtr = nullptr;
}

Entity* Entity::GetObject(std::string aEntity)
{
	GrArrayPtr = SuperList.at(aEntity);
	if (GrArrayPtr->Size() > 0)
	{
		return GrArrayPtr->FindAtIndex(0);
	}
	return NULL;
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
	if (mySprite.GetTextureWidth() > 0)
	{
		mySprite.Draw(myX, myY, myXScale, myYScale, myAngle, myDepth, myAlpha, myColor, myAnimationSpeed);
	}
	
}

void Entity::DrawGUI()
{

}

bool Entity::KeyboardCheck(sf::Keyboard::Key aKey)
{	
	return Input->keyData[aKey] > 0;
}

bool Entity::KeyboardCheckPressed(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] == 2;
}

bool Entity::KeyboardCheckRelease(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] == -1;
}

bool Entity::KeyboardCheckReleased(sf::Keyboard::Key aKey)
{
	return Input->keyData[aKey] == 0;
}

bool Entity::MouseCheck(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] > 0;
}

bool Entity::MouseCheckPressed(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] == 2;
}

bool Entity::MouseCheckRelease(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] == -1;
}

bool Entity::MouseCheckReleased(sf::Mouse::Button aButton)
{
	return Input->mouseData[aButton] == 0;
}

bool Entity::MouseWheelUp()
{
	return Input->MouseWheelUp;
}

bool Entity::MouseWheelDown()
{
	return Input->MouseWheelDown;
}

int Entity::GameMouseX()
{
	return Camera->myMouseX;
}

int Entity::GameMouseY()
{
	return Camera->myMouseY;
}

int Entity::GUIMouseX()
{
	return sf::Mouse::getPosition().x;
}

int Entity::GUIMouseY()
{
	return sf::Mouse::getPosition().y;
}

void Entity::DrawLine(float aX1, float aY1, float aX2, float aY2, float aDepth, sf::Color aColor, float aWidth)
{
	GSprite line;
	line.SetTexture("Sprites/spr_pixel.png", 1);

	/*float deltax = aX2 - aX1;
	float deltay = aY2 - aY1;
	
	float deltalength = SQRT2((deltax * deltax) + (deltay * deltay));

	line.Draw(aX1, aY1, aWidth, deltalength,(std::atan2(deltay, deltax)), aDepth, 1, aColor, 0);*/
	Vector2f delta = Vector2f(aX2,aY2) - Vector2f(aX1, aY1);

	line.Draw(aX1, aY1, delta.Length(), aWidth,sf::Vector2f(0,1)*0.5f, RtoD(std::atan2f(delta.y, delta.x)), 0, 1, sf::Color::White, 0);
}
//Accessors, Modifiers
#pragma region
bool Entity::GetActive()
{
	return myActive;
}

std::string Entity::GetName()
{
	return myName;
}

void Entity::SetActive(const bool aActive)
{
	myActive = aActive;
}
#pragma endregion

float Entity::SQRT2(const float aX)
{
	const float xhalf = 0.5f*aX;

	union // get bits for floating value
	{
		float x;
		int i;
	} u;

	u.x = aX;
	u.i = SQRT_MAGIC_F - (u.i >> 1);  // gives initial guess y0

	return aX * u.x*(1.5f - xhalf * u.x*u.x); // Newton step, repeating increases accuracy 
}
float Entity::RtoD(const float aR)
{
	return aR * (180 * M_PI);
}

float Entity::DtoR(const float aD)
{
	return aD / (180 / M_PI);
}


