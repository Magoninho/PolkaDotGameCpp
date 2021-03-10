/*
 * Game.h
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include "Player.h"
#include "Ball.h"
#include <vector>
#ifndef GAME_H_
#define GAME_H_

#include "Constants.h"
class Game
{
public:
						Game();
	virtual 			~Game();
	void 				run();

public:
	sf::Vector2f		getMousePosition(sf::RenderWindow& window);

private:
	// game methods
	void				processEvents();
	void 				update(sf::Time& deltaTime);
	void				render();
	void				showFPS(int& fps);

private:
	// game variables
	sf::RenderWindow	window;
	Player				player;
	Ball				ball[60];
	std::vector<Ball*> 	balls;

};

#endif /* GAME_H_ */
