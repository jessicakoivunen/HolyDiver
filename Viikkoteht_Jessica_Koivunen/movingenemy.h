#pragma once
#include "gameobject.h"
#include "map.h"

class MovingEnemy : public GameObject
{
private:
	int posX;
	int posY;
	char name = 'M';

public:
	char getName() { return name; }
	int getPosX() { return posX; }
	int getPosY() { return posY; }

	MovingEnemy(int _posX, int _posY) : GameObject(_posX, _posY) {
		this->posX = _posX;
		this->posY = _posY;
	}

	virtual void Move(Map& map);
	virtual int Direction();
	virtual bool CanMove(Map& map);
};