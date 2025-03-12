#include "movingenemy.h"
#include <stdlib.h>
#include <time.h>

void MovingEnemy::Move(Map& map)
{
	if (CanMove(map)) {
		//if dir 0 don't move ...
		if (Direction() == 1) {
			posY -= 1;	// move up
			map.AddCoord(posX, posY, name);
			map.AddCoord(posX, posY + 1, 'o');
		}
		else if (Direction() == 2) {
			posX -= 1;	// move left
			map.AddCoord(posX, posY, name);
			map.AddCoord(posX + 1, posY, 'o');
		}
		else if (Direction() == 3) {
			posY += 1;	//move down
			map.AddCoord(posX, posY, name);
			map.AddCoord(posX, posY - 1, 'o');
		}
		else if (Direction() == 4) {
			posX += 1;	//move right
			map.AddCoord(posX, posY, name);
			map.AddCoord(posX - 1, posY, 'o');
		}
	}

}

int MovingEnemy::Direction()
{
	//Random direction range 0-4
	srand(time(NULL));
	int dir = rand() % 5;

	return dir;
}

bool MovingEnemy::CanMove(Map& map)
{
	int nextPosX = 0;
	int nextPosY = 0;

	if (Direction() == 1) {
		nextPosX = posX;
		nextPosY = posY - 1;
	}
	else if (Direction() == 2) {
		nextPosX = posX - 1;
		nextPosY = posY;
	}
	else if (Direction() == 3) {
		nextPosX = posX;
		nextPosY = posY + 1;
	}
	else if (Direction() == 4) {
		nextPosX = posX + 1;
		nextPosY = posY;
	}
	// if nothing else in coord. --> can move
	if (map.getMap()[nextPosY][nextPosX] == 'o') return true;
	else return false;
}