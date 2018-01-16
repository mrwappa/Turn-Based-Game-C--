#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include "GrowingArray.h"
#include "SFML\Graphics.hpp"
#include "GSprite.h"

class Entity
{
public:
	Entity(float aX, float aY);
	~Entity();
	
	static std::map<std::string, GrowingArray<Entity*>*> SuperList;
	void AddInstance(Entity* aEntity);
	void DeleteInstance(Entity* aEntity);

	//Init,Update,Draw
	virtual void Init();
	virtual void BeginUpdate();
	virtual void Update();
	virtual void EndUpdate();
	virtual void Draw();
	virtual void DrawGUI();

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
	GrowingArray<Entity*>* GrArrayPtr;
};

#endif // !ENTITY_H