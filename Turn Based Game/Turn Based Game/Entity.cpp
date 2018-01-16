#include "stdafx.h"
#include "Entity.h"

std::map<std::string, GrowingArray<Entity*>*> Entity::SuperList;

Entity::Entity()
{
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
	/*GrowingArray<Entity*>* i = NULL;
	auto it = SuperList.find(typeid(this).name());
	if (it != SuperList.end()) i = it->second;*/

	
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
	mySprite.Draw(myX, myY, myXScale, myYScale, myAngle, myDepth, myColor);
}

void Entity::DrawGUI()
{

}
