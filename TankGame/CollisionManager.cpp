#include "CollisionManager.h"
#include "Entity.h"
#include "Racket.h"
#include "Ball.h"

CollisionManager* CollisionManager::instance = nullptr;

CollisionManager::CollisionManager()
{
	pongSound = new sf::Music();
	pongSound->openFromFile("Resources/SFX/pongSFX.ogg");
}

void CollisionManager::ResolveCollision(Entity* A, Entity* B)
{
	bool isBallA = (dynamic_cast<Ball*>(A) != nullptr);
	bool isBallB = (dynamic_cast<Ball*>(B) != nullptr);
	bool isRacketA = (dynamic_cast<Racket*>(A) != nullptr); 
	bool isRacketB = (dynamic_cast<Racket*>(B) != nullptr); 

	if ((isBallA && isRacketB) || (isBallB && isRacketA))
	{
		Ball* ball = isBallA ? dynamic_cast<Ball*>(A) : dynamic_cast<Ball*>(B);
		ball->SetVelocity(Vector2f(-ball->GetVelocity().x, ball->GetVelocity().y));
		pongSound->play();
	}
}

CollisionManager::~CollisionManager()
{
	list<Entity*>::iterator it;

	for (it = entities.begin(); it != entities.end(); it++)
	{
		Entity* current = *it;
		delete current;
	}

	delete pongSound;
}

void CollisionManager::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}

void CollisionManager::Updatecollisions()
{
	for (list<Entity*>::iterator it =  entities.begin(); it != entities.end(); it++)
	{
		for (list<Entity*>::iterator otherIt = it; otherIt != entities.end(); otherIt++)
		{
			Entity* entity = *it;
			Entity* otherEntity = *otherIt;

			if(entity != otherEntity && entity->getGlobalBounds().intersects(otherEntity->getGlobalBounds()))
			{
				ResolveCollision(entity, otherEntity);
				cout << "Collision" << endl;
			}
		}
	}
}