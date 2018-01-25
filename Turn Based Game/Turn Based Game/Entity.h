#ifndef ENTITY_H
#define ENTITY_H

#define and &&
#define or ||
#define SQRT_MAGIC_F 0x5f3759df 
#define _USE_MATH_DEFINES

#include <map>
#include <typeinfo>
#include "GrowingArray.h"
#include "SFML\Graphics.hpp"
#include "GSprite.h"
#include "InputHandler.h"
#include "Camera.h"
#include <math.h>
#include "Vector2.h"

class Entity
{
public:

	Entity(std::string aTypeName);
	~Entity();

	static std::map<std::string, GrowingArray<Entity*>*> SuperList;
	static std::map<std::string, GrowingArray<Entity*>*> ClassHierarchy;

	static Camera* Camera;
	
	void AddInstance(Entity* aEntity, std::string aTypeName);
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
	
	//Extra Draw
	static GSprite Pixel;
	void DrawLine(float aX1, float aY1,float aX2, float aY2,  float aDepth, sf::Color aColor, float aWidth);
	//Accessors
#pragma region
	bool GetActive();
#pragma endregion
	//Modifiers
#pragma region
	void SetActive(const bool aActive);
#pragma endregion
	//Quick Maths
	float SQRT2(const float aX);
	float DtoR(const float aD);
	float RtoD(const float aR);
protected:
	float myX;
	float myY;
	/*float myXPrevious;
	float myYPrevious;*/
	
	float myDepth;
	float myAngle;
	float myXScale;
	float myYScale;
	float myAlpha;
	sf::Color myColor;
	
	GSprite mySprite;
	float myAnimationSpeed;

	float myActive;

private:
	static GrowingArray<Entity*>* GrArrayPtr;
};

#endif // !ENTITY_H