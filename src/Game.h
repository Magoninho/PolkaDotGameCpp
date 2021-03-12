/*
 * Game.h
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
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
	void				restart();
	void				showFPS(float fps);
	void 				showDeathScreen(sf::RenderWindow& window);
	void				drawWin(sf::RenderWindow& window); // TODO: idk if its a good idea lol

private:
	// game variables

	bool 				win;

	sf::Texture 		victory;
	sf::Sprite 			victorySprite;

	sf::Text 			text;
	sf::Text 			shadow;
	sf::Font 			font;


	sf::Music			winSong;
	sf::Music 			deathSong;
	sf::Music 			themeSong;
	sf::RenderWindow	window;
	Player				player;
	Ball				ball[150];
	std::vector<Ball*> 	balls;


};

#endif /* GAME_H_ */
