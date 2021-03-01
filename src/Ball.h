/*
 * balls.h
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include <SFML/Graphics.hpp>
#ifndef BALL_H_
#define BALL_H_

class Ball
{
public:
					Ball();
	virtual 		~Ball();

public:
	void 			update(sf::Time& deltaTime);
	void			draw(sf::RenderWindow& window);

public:
	sf::CircleShape	bShape;
private:
	// TODO: make everything random
	int				x, y;
	short int 		direction[2];
	int 			speedX, speedY;
	int 			radius;
	sf::Color		color;

};

#endif /* BALL_H_ */
