/*
 * Player.cpp
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(sf::Vector2f position)
{
	playerMass = 3;

	pShape.setFillColor(sf::Color::Black);
	pShape.setPosition(position);
	pShape.setRadius((float) playerMass * 5);
	pShape.setOrigin(pShape.getLocalBounds().width/2, pShape.getLocalBounds().height/2);
}




void Player::increaseMass()
{
	playerMass++;
	pShape.setRadius((float) playerMass * 10);
	pShape.setOrigin(pShape.getLocalBounds().width/2, pShape.getLocalBounds().height/2);
}

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
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		increaseMass();
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(pShape);
}


////// getters and setters //////

void Player::setPosition(sf::Vector2f position)
{
	pShape.setPosition(position);
}

Player::~Player()
{
	// TODO Auto-generated destructor stub
}

