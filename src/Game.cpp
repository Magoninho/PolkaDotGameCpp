/*
 * Game.cpp
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Polka Dot Game!"),
	  player(sf::Vector2f(50.f, 50.f))
{
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
	}
}


void Game::update(sf::Time& deltaTime)
{
	player.setPosition(getMousePosition(window));
	player.update(); // don't need deltaTime because the player follows the mouse, dt is not necessary
	for (int i = 0; i < sizeof(balls)/sizeof(*balls); i++)
	{
		balls[i].update(deltaTime);
		if (player.collideCircle(balls[i].bShape))
		{
//			cout << "colidiu" << endl;
		}
	}

}

void Game::render()
{
	window.clear(sf::Color::White);
	player.draw(window);
	for (int i = 0; i < sizeof(balls)/sizeof(*balls); i++) {
		balls[i].draw(window);

	}

	window.display();
}

void Game::showFPS(int& fps)
{
	//	printf("%d fps\n", fps);
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

