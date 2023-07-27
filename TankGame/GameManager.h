#pragma once
#include "Ball.h"
#include "Racket.h"
//#include <SFML/Audio.hpp>

class GameManager
{
private:
	static GameManager* instance;
	GameManager() {};

public:
	~GameManager() {};

	static GameManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}

	Racket* _player;
	Racket* _ia;
	Ball* _ball;

	//Music winMusic;
	//Music loseMusic;
	

	void SetEntities(Racket* player, Racket* ia, Ball* ball);
	void Gol(bool golFromIa);

	void ResetRacketPosition();
	void ResetGame();

};