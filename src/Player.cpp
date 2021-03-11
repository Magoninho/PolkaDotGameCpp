/*
 * Player.cpp
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f position)
{
	playerMass = 10;

	pShape.setFillColor(sf::Color::Green);
	pShape.setPosition(position);
	pShape.setRadius((float) playerMass);
	pShape.setOrigin(pShape.getLocalBounds().width/2, pShape.getLocalBounds().height/2);

	isDead = false;
}




void Player::increaseMass()
{
	playerMass++;
	pShape.setRadius((float) playerMass);
	pShape.setOrigin(pShape.getLocalBounds().width/2, pShape.getLocalBounds().height/2);
}

/**
 * \brief Checks if the player is colliding with another circle
 *
 * \return bool
 * */
bool Player::collideCircle(sf::CircleShape& circle)
{
	sf::CircleShape& circle1 = pShape;
	sf::CircleShape& circle2 = circle;
	circle2.setOrigin(circle2.getLocalBounds().width/2, circle2.getLocalBounds().height/2);

	auto dx = circle1.getPosition().x - circle2.getPosition().x;
	auto dy = circle1.getPosition().y - circle2.getPosition().y;
	// distância dos dois eixos (hipotenusa)
	double distance = sqrt(dx * dx + dy * dy);

	if (distance < circle1.getRadius() + circle2.getRadius())
	{
		increaseMass();
		return true;
	}
	return false;
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		isDead = false;
}

void Player::draw(sf::RenderWindow& window)
{
	if (!isDead)
		window.draw(pShape);
}


////// getters and setters //////

int Player::getPlayerMass()
{
	return playerMass;
}
void Player::setPlayerMass(int newMass)
{
	playerMass = newMass;
	pShape.setRadius((float) playerMass);
	pShape.setOrigin(pShape.getLocalBounds().width/2, pShape.getLocalBounds().height/2);
}

void Player::setPosition(sf::Vector2f position)
{
	pShape.setPosition(position);
}

Player::~Player()
{
	// TODO Auto-generated destructor stub
}

