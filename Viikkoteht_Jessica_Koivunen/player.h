#pragma once
#include "gameobject.h"
#include "map.h"
#include "light.h"

class Player : public GameObject
{
private:
	int posX;
	int posY;
	char name = 'P';
	int health = 100;
	int oxygen = 100;

public:
	char getName() { return name; }
	int getPosX() { return posX; }
	int getPosY() { return posY; }
	virtual int getHealth() { return health; }
	virtual int getOxygen() { return oxygen; }

	Player(int _posX, int _posY) :GameObject(_posX, _posY) {
		this->posX = _posX;
		this->posY = _posY;
	}

	virtual void Move(char dir, class Map& map, class Light& light);
	virtual void TakeDamage(int amount);
	virtual void ChangeOxygenLevel(int amount);
	virtual int nextX(char dir);
	virtual int nextY(char dir);
	virtual bool CanMove(char dir, class Map& map);
	virtual bool IsDead();
};