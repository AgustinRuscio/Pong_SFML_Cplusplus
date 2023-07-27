#include "Entity.h"

Entity::Entity(std::string name) : Sprite()
{
	this->name = name;
	EntityManager::GetInstance()->AddEntity(this);
}

Entity::~Entity()
{
}
