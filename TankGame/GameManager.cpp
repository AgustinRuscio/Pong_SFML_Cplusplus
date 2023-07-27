#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

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

		if (_ia->GetScore() > 5) ResetGame();
	}
	else
	{
		_player->AddScore();

		if (_player->GetScore() > 5) ResetGame();
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