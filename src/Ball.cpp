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
using namespace std;
Ball::Ball()
{
	radius = getRandomNumber(5, 50) == 0 ? getRandomNumber(5, 50) : getRandomNumber(5, 50);
	speedX = getRandomNumber(-100, 100);
	speedY = getRandomNumber(-100, 100);

	x = getRandomNumber(0, WIDTH);
	y = getRandomNumber(0, HEIGHT);

	bShape.setRadius((float)radius);
	bShape.setPosition((float)x, (float)y);

	// setting random colors for each ball
	if (getRandomNumber(1, 5) == 1) 	 color = sf::Color::Yellow;
	else if (getRandomNumber(1, 5) == 2) color = sf::Color::Blue;
	else if (getRandomNumber(1, 5) == 3) color = sf::Color::Red;
	else if (getRandomNumber(1, 5) == 4) color = sf::Color::Cyan;
	else color = sf::Color::Magenta;
	bShape.setFillColor(color);
}

void Ball::update(sf::Time& deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	bShape.move(speedX * deltaTime.asSeconds(), speedY * deltaTime.asSeconds());

	if (bShape.getPosition().x > WIDTH + bShape.getRadius())
		bShape.setPosition(0 - bShape.getRadius(), y);

	if (bShape.getPosition().x < 0 - bShape.getRadius())
		bShape.setPosition(WIDTH + bShape.getRadius(), y);

	if (bShape.getPosition().y > HEIGHT + bShape.getRadius())
		bShape.setPosition(x, 0 - bShape.getRadius());

	if (bShape.getPosition().y < 0 - bShape.getRadius())
		bShape.setPosition(x, HEIGHT + bShape.getRadius());


}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(bShape);
}

Ball::~Ball()
{
	// TODO Auto-generated destructor stub
}

