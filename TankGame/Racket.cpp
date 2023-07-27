#include "Racket.h"

Racket::Racket(bool ai, Entity* target) : Entity("Paddle")
{
	_isAnAI = ai;
	_target = target;

	texture.loadFromFile("Resources/Textures/PongPaddle.png");
	setTexture(texture);

	if(!_isAnAI)
	{
		speed = 500.f;
		setPosition(16,250);
	}
	else
	{
		speed = 370.f;
		setPosition(750,250);
	}
}

Racket::~Racket()
{
	delete _target;
}

void Racket::AddScore()
{
	score++;
}

void Racket::ResetScore()
{
	score = 0;
}

void Racket::Update(float deltaTime)
{
	MovementLogic();

	move(velocity * deltaTime);
}

void Racket::Draw(RenderWindow* win)
{
	win->draw(*this);
}

void Racket::MovementLogic()
{
	velocity = Vector2f();

	if(!_isAnAI)
	{
		if (Keyboard::isKeyPressed(Keyboard::W))
			velocity.y = -speed;
		if (Keyboard::isKeyPressed(Keyboard::S))
			velocity.y = speed;
	}
	else
	{
		if(_target->getPosition().x > 400)
		{
			float targetY = _target->getPosition().y;
			float racketY = getPosition().y;

			if (targetY < racketY)
				velocity.y = -speed;
			else if (targetY > racketY)
				velocity.y = speed;
			else
				velocity.y = 0.0f;
		}
			
	}


	if (getPosition().y < 10)
		setPosition(getPosition().x, 10);
	
	if (getPosition().y > 590 - texture.getSize().y)
		setPosition(getPosition().x, 590 - texture.getSize().y);
}


int  Racket::GetScore() const
{
	return score;
}
