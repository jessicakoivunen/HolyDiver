#pragma once
class GameObject
{
public:	
	int posX = 0;
	int posY = 0;
	char name = 'o';
	virtual char getName() { return name; }
	virtual int getPosX() { return posX; }
	virtual int getPosY() { return posY; }
	inline GameObject(int _posX, int _posY) {
		this->posX = _posX;
		this->posY = _posY;
	}
};