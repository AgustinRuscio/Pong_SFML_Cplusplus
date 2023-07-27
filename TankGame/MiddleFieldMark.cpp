#include "MiddleFieldMark.h"

MiddleFieldMark::MiddleFieldMark() : Entity("mark")
{
	_texture.loadFromFile("Resources/Textures/MiddleMark.png");
	setTexture(_texture);
}

void MiddleFieldMark::SetMarkPosition(Vector2f position)
{
	setPosition(position);
}