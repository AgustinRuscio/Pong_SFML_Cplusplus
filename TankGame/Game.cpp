#include "Game.h"

void Game::Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
    CollisionManager::GetInstance()->Updatecollisions();

    UpdateScores();
}

void Game::Draw()
{
    window->clear(Color::Black);

    for (Entity* entity : EntityManager::GetInstance()->GetEntities())
    {
        entity->Draw(window);
    }

    window->draw(*_playerScore);
    window->draw(*_aiScore);

    window->display();
}

Game::Game()
{
    window = new RenderWindow(sf::VideoMode(800, 600), "My window");

	_ball = new Ball();

	_playerRacket = new Racket(false, nullptr);
    _aiRacket = new Racket(true, _ball);

    GameManager::GetInstance()->SetEntities(_playerRacket, _aiRacket, _ball);

    _font = new Font();

    _playerScore = new Text(to_string(_playerRacket->GetScore()), *_font, 100);
    _playerScore->setFillColor(Color::Blue);
    _playerScore->setPosition(250, 20);

    _aiScore = new Text(to_string(_aiRacket->GetScore()), *_font, 100);
    _aiScore->setFillColor(Color::Yellow);
    _aiScore->setPosition(550, 20);

    _font->loadFromFile("Resources/Textures/Milky_Again.ttf");

    //music.openFromFile("Resources/SFX/BocaYoTeAmo.ogg");
    //
    //music.setLoop(true);
    //music.play();

    CreateField();
    UpdateScores();

    CollisionManager::GetInstance()->AddEntity(_playerRacket);
    CollisionManager::GetInstance()->AddEntity(_aiRacket);
    CollisionManager::GetInstance()->AddEntity(_ball);

	_isRunning = true;
}

Game::~Game()
{
    if (window)
    {
        delete window;
        window = nullptr;
    }

    delete _playerRacket;
    delete _aiRacket;
    delete _ball;

    delete _font;
    delete _playerScore;
    delete _aiScore;

    list<MiddleFieldMark*>::iterator it;

    for (it = marksFieldList.begin(); it != marksFieldList.end(); it++)
    {
        MiddleFieldMark* current = *it;
        delete current;
    }
}

void Game::CreateField()
{
    for (int i = 0; i < 10; i++)
    {
        MiddleFieldMark* currentMark = new MiddleFieldMark();
        marksFieldList.push_back(currentMark);
    }

    list<MiddleFieldMark*>::iterator it;

    float i = 0;

    for (it = marksFieldList.begin(); it != marksFieldList.end(); it++)
    {
        MiddleFieldMark* current = *it;
        current->setPosition(400, i);
        i += 60;
    }
}

void Game::UpdateScores()
{
    _playerScore->setString(to_string(_playerRacket->GetScore()));

    _aiScore->setString(to_string(_aiRacket->GetScore()));
}


void Game::Run() {

    const float FPS = 60.f;
    const float MS_PER_FRAME = 1.f / FPS;
    float lag = 0;

    Clock clockDelta;
    Time delta = clockDelta.restart();

    while (window->isOpen() || _isRunning)
    {
        delta = clockDelta.restart();
        lag += delta.asSeconds();

    	Event event;
        while (window->pollEvent(event) )
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        while (lag >= MS_PER_FRAME)
        {
	        Update(MS_PER_FRAME);
            lag -= MS_PER_FRAME;
        }

    	Draw();
    }
}