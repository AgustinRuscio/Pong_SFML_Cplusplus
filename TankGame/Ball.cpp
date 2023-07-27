#include "Ball.h"

#include "GameManager.h"


Ball::Ball() : Entity("Ball")
{
    setPosition(400, 400);

    shape.setRadius(radius);
    shape.setFillColor(Color::Green);
    shape.setPosition(400, 200);
    
    _speed = 400.f;

    _ballTexture.loadFromFile("Resources/Textures/ballTexture.png");
    setTexture(_ballTexture);

    _velocity = Vector2f(_speed, _speed);
}

Ball::~Ball()
{
}

void Ball::Update(float deltaTime)
{
    BallMovemnt(deltaTime);
    CheckGoal();
}

void Ball::Draw(RenderWindow* win)
{
    win->draw(shape);
}


void Ball::Bounce()
{
}

void Ball::SetVelocity(Vector2f newVelocity)
{
    _velocity = newVelocity;
}

Vector2f Ball::GetVelocity() const
{
    return _velocity;
}


void Ball::BallMovemnt(float deltaTime)
{
    move(_velocity * deltaTime);

    shape.setPosition(getPosition());

    if (getPosition().x <= -50 || getPosition().x >= 850 - 2 * radius)
		_velocity.x = -_velocity.x;

    if (getPosition().y <= 0 || getPosition().y >= 600 - 2 * radius)
        _velocity.y = -_velocity.y;

    if (getPosition().x > 800 || getPosition().x < 0)
    {
        shape.setPosition(400, 200);
        _velocity.x = -_velocity.x; 
    }
}

void Ball::CheckGoal()
{
    if (getPosition().x > 800)
    {
        GameManager::GetInstance()->Gol(false);
        setPosition(400, 200);
    }

    if (getPosition().x <= 0)
    {
        GameManager::GetInstance()->Gol(true);
        setPosition(400, 200);
    }
}