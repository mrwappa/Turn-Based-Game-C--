#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
	std::string type = typeid(this).name();
}


Entity::~Entity()
{
}