#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"

using namespace sf;

class Entity : public Sprite
{
private:
	string name;
public:
	Entity(string name);
	virtual ~Entity();
	virtual void Update(float deltaTime) = 0;

	virtual void Draw(RenderWindow* window) = 0;
};