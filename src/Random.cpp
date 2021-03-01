/*
 * Random
 *
 *  Created on: 28 de fev. de 2021
 *      Author: magoninho
 */

#include <ctime>
#include <cstdlib>

int getRandomNumber(int min, int max)
{
	static bool first = true;
	if (first)
	{
	  srand( time(0) ); // "seedando" só uma vez no programa todo
	  first = false;
	}
	return (min + rand () % ((max + 1) - min));
}
