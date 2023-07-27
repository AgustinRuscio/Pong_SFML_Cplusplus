#pragma once
#include "Entity.h"

class Racket : public Entity
{
private:
	Texture texture;
	Vector2f velocity;
	float speed;

	int score = 0;

	bool _isAnAI;
	Entity* _target;

public:
	Racket(bool ai, Entity* target);
	~Racket();

	void AddScore();
	void ResetScore();

	void Update(float deltaTime) override;
	void Draw(RenderWindow* win) override;

	void MovementLogic();

	int GetScore() const;
};