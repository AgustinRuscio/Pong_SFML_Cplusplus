#pragma once
#include "Entity.h"

class Ball : public Entity
{
public:
    Ball();

    ~Ball();

    void Update(float deltaTime) override;
    void Draw(RenderWindow* win) override;
    
    void Bounce();

    void SetVelocity(Vector2f newVelocity);
    Vector2f GetVelocity() const;
    
private:

    void BallMovemnt(float time);

    void CheckGoal();

    float radius = 10;
    float _speed;
    
    Texture _ballTexture;

    CircleShape shape;
    Vector2f _velocity;
};