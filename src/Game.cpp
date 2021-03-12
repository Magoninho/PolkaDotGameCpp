/*
 * Game.cpp
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include "Game.h"



Game::Game()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Polka Dot Game!"),
	  player(sf::Vector2f(50.f, 50.f))
{

	// initializing music files
	if (!deathSong.openFromFile("Media/Audio/death.ogg"))
		std::cout << "failed to load music" << std::endl;
	if (!themeSong.openFromFile("Media/Audio/theme.ogg"))
		std::cout << "failed to load music" << std::endl;
	if (!winSong.openFromFile("Media/Audio/win.wav"))
			std::cout << "failed to load music" << std::endl;
	themeSong.play();

	// initializing fonts
	if (!font.loadFromFile("Media/Font/8-BIT.TTF"))
		std::cout << "error while loading media" << std::endl;

	win = false;


	// initialize balls
	for (int i = 0; i < sizeof(ball)/sizeof(Ball); ++i)
		balls.push_back(&ball[i]);
}

void Game::processEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		default:
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			restart();
	}
}


void Game::update(sf::Time& deltaTime)
{
	player.setPosition(getMousePosition(window));
	player.update();

	// checking if the player is colliding with some ball and updating all balls
	for (size_t i = 0; i < balls.size(); i++)
	{
		balls[i]->update(deltaTime);

		if (!player.isDead)
		{
			if (player.collideCircle(balls[i]->bShape))
			{
				if (player.getPlayerMass() < balls[i]->bShape.getRadius())
				{
					std::cout << "Morreu" << std::endl;
					player.isDead = true;
					themeSong.pause();
					deathSong.play();

				}

				balls.erase(balls.begin() + i);

				if (balls.empty() && player.isDead != true)
				{
					win = true;
					winSong.play();
					themeSong.pause();

				}

			}
		}
	}

}

void Game::drawWin(sf::RenderWindow& window)
{

	text.setFont(font);
	shadow.setFont(font);

	text.setString("YOU WOOOOONNNN");
	shadow.setString(text.getString());
	text.setCharacterSize(64);
	shadow.setCharacterSize(text.getCharacterSize());
	text.setPosition((WIDTH/2)-100, HEIGHT/2);
	shadow.setPosition(((WIDTH/2)-100)+3, (HEIGHT/2)+3);

	text.setFillColor(sf::Color::Blue);
	shadow.setFillColor(sf::Color::Black);

	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
	shadow.setOrigin(shadow.getLocalBounds().width/2, shadow.getLocalBounds().height/2);

	text.rotate(0.02f);
	shadow.rotate(0.02f);
	window.draw(shadow);
	window.draw(text);

}

void Game::showDeathScreen(sf::RenderWindow& window)
{
	text.setFont(font);
	shadow.setFont(font);

	text.setString("you died lol\npress space to restart");
	shadow.setString(text.getString());
	text.setCharacterSize(48);
	shadow.setCharacterSize(text.getCharacterSize());
	text.setPosition((WIDTH/2), HEIGHT/2);
	shadow.setPosition(((WIDTH/2))+3, (HEIGHT/2)+3);

	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
	shadow.setOrigin(shadow.getLocalBounds().width/2, shadow.getLocalBounds().height/2);

	text.setFillColor(sf::Color::Red);
	shadow.setFillColor(sf::Color::Black);
	window.draw(shadow);
	window.draw(text);
}

void Game::restart()
{
	themeSong.play();

	win = false;
	winSong.stop();

	deathSong.stop();
	balls.erase(balls.begin(), balls.end());
	player.isDead = false;

	player.setPlayerMass(10);
	for (int i = 0; i < sizeof(ball)/sizeof(Ball); ++i) {
		balls.push_back(&ball[i]);
		balls[i]->reset();
	}
}

void Game::render()
{
	window.clear(sf::Color::White);
	player.draw(window);
	for (size_t i = 0; i < balls.size(); i++)
		balls[i]->draw(window);

	if (player.isDead)
		showDeathScreen(window);

	if (win)
		drawWin(window);

	window.display();
}

void Game::showFPS(float fps)
{
	std::cout << fps << " fps" << std::endl;
}

void Game::run()
{
	int frames = 0;
	int fps = 60;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / fps);
	sf::Time timer = sf::Time::Zero;

	while (window.isOpen())
	{
		/**
		 * This is a process called fixed time steps
		 * The game will only update if the time passed is the same as 1 divided by the amount of fps
		 * */
		timeSinceLastUpdate += clock.restart();
		processEvents();

		while (timeSinceLastUpdate > timePerFrame) // time per frame
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
			// completou 1 segundo (60 frames)
			frames++;
		}


		// probably this is not even working (help pls)
		if (frames > fps)
		{

			showFPS(1.0f / clock.getElapsedTime().asSeconds());
			frames = 0;
			clock.restart().asSeconds();
		}

		render();
	}
}

sf::Vector2f Game::getMousePosition(sf::RenderWindow& window)
{
	return sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

