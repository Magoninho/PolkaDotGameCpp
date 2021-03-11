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

	if (!music.openFromFile("Media/Audio/death.ogg"))
		std::cout << "failed to load music" << std::endl;



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
					music.play();

				}

				balls.erase(balls.begin() + i);

			}
		}
	}

}

void Game::showDeathScreen(sf::RenderWindow& window)
{
	sf::Text text;
	sf::Text shadow;
	sf::Font font;
	if (!font.loadFromFile("Media/Font/8-BIT.TTF"))
		std::cout << "error while loading media" << std::endl;

	text.setFont(font);
	shadow.setFont(font);

	text.setString("you died lol\npress space to restart");
	shadow.setString("you died lol\npress space to restart");
	text.setCharacterSize(32);
	shadow.setCharacterSize(32);
	text.setPosition((WIDTH/2)-100, HEIGHT/2);
	shadow.setPosition(((WIDTH/2)-100)+2, (HEIGHT/2)+2);

	text.setFillColor(sf::Color::Red);
	shadow.setFillColor(sf::Color::Black);
	window.draw(shadow);
	window.draw(text);
}

void Game::restart()
{
	music.stop();
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


	window.display();
}

void Game::showFPS(int& fps)
{
	printf("%d fps\n", fps);
}

void Game::run()
{
	int timer = 0;
	int fps = 60;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / fps);

	while (window.isOpen())
	{
		/**
		 * This is a process called fixed time steps
		 * The game will only update if the time passed is the same as 1 divided by the amount of fps
		 * */
		timeSinceLastUpdate += clock.restart();
		processEvents();

		while (timeSinceLastUpdate >= timePerFrame) // time per frame
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
			timer++;
		}
		if (timer >= fps)
		{
			showFPS(timer);
			timer = 0;
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

