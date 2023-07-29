#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Racket.h"
#include "Ball.h"
#include "MiddleFieldMark.h"
#include "CollisionManager.h"
#include "GameManager.h"

using namespace sf;

class Game
{
private:
	RenderWindow* window;
	Music* ambientMusic;

	bool _isRunning;
	void Update(float deltaTime);
	void Draw();

	Font* _font;

	Text* _playerScore;
	Text* _aiScore;

	Racket* _playerRacket;
	Racket* _aiRacket;
	Ball* _ball;



	list<MiddleFieldMark*> marksFieldList;

public:
	Game();

	void CreateField();

	void UpdateScores();

	virtual ~Game();
	void Run();
};