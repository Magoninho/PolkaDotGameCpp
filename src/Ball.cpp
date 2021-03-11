/*
 * balls.cpp
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include "Ball.h"
#include "Declarations.h"
#include "Constants.h"
#include <iostream>

Ball::Ball()
{
	radius = Random::getRandomNumber(5, 50) == 0 ? Random::getRandomNumber(5, 50) : Random::getRandomNumber(5, 50);
	speedX = Random::getRandomNumber(-100, 150);
	speedY = Random::getRandomNumber(-100, 150);

	short int side = Random::getRandomNumber(0, 1);

	if (side == 0)
		x = Random::getRandomNumber(-WIDTH, 0);
	else
		x = Random::getRandomNumber(WIDTH, 0);


	y = HEIGHT / 2;

	bShape.setRadius((float)radius);
	bShape.setPosition((float)x, (float)y);

	// setting random colors for each ball
	if 		(Random::getRandomNumber(1, 5) == 1) color = sf::Color::Yellow;
	else if (Random::getRandomNumber(1, 5) == 2) color = sf::Color::Blue;
	else if (Random::getRandomNumber(1, 5) == 3) color = sf::Color::Red;
	else if (Random::getRandomNumber(1, 5) == 4) color = sf::Color::Cyan;
	else 								 		 color = sf::Color::Magenta;

	bShape.setFillColor(color);
}

/**
 * \brief sets a new random speed for both x and y speeds of the ball
 * */

void Ball::newRandomSpeed()
{
	speedX = Random::getRandomNumber(-100, 150);
	speedY = Random::getRandomNumber(-100, 150);
}

void Ball::reset()
{
	short int side = Random::getRandomNumber(0, 1);

	if (side == 0)
		x = Random::getRandomNumber(-WIDTH, 0);
	else
		x = Random::getRandomNumber(WIDTH, 0);

	bShape.setPosition((float)x, (float)y);

}

/**
 * \brief Updates the ball
 *
 * \param deltaTime
 * */
void Ball::update(sf::Time& deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	bShape.move(speedX * deltaTime.asSeconds(), speedY * deltaTime.asSeconds());

	if (bShape.getPosition().x > WIDTH + bShape.getRadius())
	{
		bShape.setPosition(0 - bShape.getRadius(), Random::getRandomNumber(0, HEIGHT));
		newRandomSpeed();
	}
	if (bShape.getPosition().x < 0 - bShape.getRadius())
	{
		bShape.setPosition(WIDTH + bShape.getRadius(), Random::getRandomNumber(0, HEIGHT));
		newRandomSpeed();
	}

	if (bShape.getPosition().y > HEIGHT + bShape.getRadius())
	{
		bShape.setPosition(x, 0 - bShape.getRadius());
		newRandomSpeed();
	}
	if (bShape.getPosition().y < 0 - bShape.getRadius())
	{
		bShape.setPosition(x, HEIGHT + bShape.getRadius());
		newRandomSpeed();
	}
}

/**
 * \brief Draws the ball to a window
 *
 * \param window
 * */

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(bShape);
}

Ball::~Ball()
{
	// TODO Auto-generated destructor stub
}

