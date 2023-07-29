#pragma once
#include <list>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

class Entity;

class CollisionManager
{
private:

	static CollisionManager* instance;
	CollisionManager();

	list<Entity*> entities;
	void ResolveCollision(Entity* A, Entity* B);

	sf::Music* pongSound;

public:
	virtual ~CollisionManager();

	static  CollisionManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new CollisionManager;

		return instance;
	}

	void AddEntity(Entity* entity);
	void Updatecollisions();
};

