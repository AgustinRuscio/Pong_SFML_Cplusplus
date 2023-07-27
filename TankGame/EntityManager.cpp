#include "EntityManager.h"
#include "Entity.h"


EntityManager* EntityManager::instance = nullptr;

void EntityManager::UpdateEntities(float deltaTime)
{
	for (Entity* entity : entities)
	{
		entity->Update(deltaTime);
	}
}

void EntityManager::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}
