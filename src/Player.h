/*
 * Player.h
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include <SFML/Graphics.hpp>
#include <cmath>
#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
public:
					Player (sf::Vector2f position);
	virtual 		~Player();

public:
	void			update(); //TODO:  sf::Time& deltaTime
	void			draw  (sf::RenderWindow& window);
	bool			collideCircle(sf::CircleShape& circle);

public:
	// setters
	void			setPosition(sf::Vector2f position);

public:
	// getters
	sf::Vector2f	getPosition();

private:
	// Player methods
	void 			increaseMass();

private:
	// Player variables
	int				playerMass;
	sf::CircleShape	pShape;


};

#endif /* PLAYER_H_ */
