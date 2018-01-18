#ifndef ENTITY_H
#define ENTITY_H

#define and &&
#define or ||

#include <map>
#include "GrowingArray.h"
#include "SFML\Graphics.hpp"
#include "GSprite.h"
#include "InputHandler.h"
#include "Camera.h"

class Entity
{
public:

	Entity(float aX, float aY);
	~Entity();

	static std::map<std::string, GrowingArray<Entity*>*> SuperList;
	static std::map<std::string, GrowingArray<Entity*>*> ClassHierarchy;

	static Camera* Camera;
	
	void AddInstance(Entity* aEntity);
	void DestroyInstance(Entity* aEntity);
	
	//Init,Update,Draw
	virtual void Init();//används inte än, vet inte vad jag ska ha det för ATM
	virtual void BeginUpdate();
	virtual void Update();
	virtual void EndUpdate();
	virtual void Draw();
	virtual void DrawGUI();

	//Mouse,Keyboard
	static InputHandler* Input;

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

	int GameMouseX();
	int GameMouseY();
	int GUIMouseX();
	int GUIMouseY();
	
protected:
	float myX;
	float myY;
	/*float myXPrevious;
	float myYPrevious;*/
	
	float myDepth;
	float myAngle;
	float myXScale;
	float myYScale;
	sf::Color myColor;

	GSprite mySprite;
	float myAnimationSpeed;

private:
	static GrowingArray<Entity*>* GrArrayPtr;
};

#endif // !ENTITY_H