#pragma once
#include "Entity.h"
class MiddleFieldMark : public Entity
{
private:
	Texture _texture;

public:
	MiddleFieldMark();
	~MiddleFieldMark(){}

	void SetMarkPosition(Vector2f position);

	void Update(float deltaTime) override{}
	void Draw(RenderWindow* win) override
	{
		win->draw(*this);
	}
};