#pragma once
#include <iostream>
#include <list>

using namespace std;

class Entity;

class EntityManager
{
private:
	static EntityManager* instance;
	list<Entity*> entities;
	EntityManager() {};

public:
	~EntityManager() {};

	static EntityManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new EntityManager();
		}
		return instance;
	}

	void UpdateEntities(float deltaTime);
	void AddEntity(Entity* entity);

	list<Entity*> GetEntities() { return entities; }
};