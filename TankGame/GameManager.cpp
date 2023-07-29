#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	winSound = new Music();
	winSound->openFromFile("Resources/SFX/winSFX.ogg");

	loseSound = new Music();
	loseSound->openFromFile("Resources/SFX/loseSFX.ogg");

	golSound = new Music();
	golSound->openFromFile("Resources/SFX/golSFX.ogg");
}


GameManager::~GameManager()
{
	delete winSound;
	delete loseSound;
	delete golSound;
}

void GameManager::SetEntities(Racket* player, Racket* ia, Ball* ball)
{
	_player = player;
	_ia = ia;
	_ball = ball;
}

void GameManager::Gol(bool golFromIa)
{
	if(golFromIa)
	{
		_ia->AddScore();
		golSound->play();

		if (_ia->GetScore() > 5)
		{
			loseSound->play();
			ResetGame();
		}
	}
	else
	{
		_player->AddScore();
		golSound->play();

		if (_player->GetScore() > 5)
		{
			winSound->play();
			ResetGame();
		}
	}

}

void GameManager::ResetRacketPosition()
{
	_player->setPosition(16, 250);
	_ia->setPosition(750, 250);
}

void GameManager::ResetGame()
{
	ResetRacketPosition();

	_ia->ResetScore();
	_player->ResetScore();
}