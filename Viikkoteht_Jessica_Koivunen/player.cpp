#include "player.h"

int Player::nextX(char dir) {
	int nextPosX = 0;

	if (dir == 'w' || dir == 'W' || dir == 's' || dir == 'S') {
		nextPosX = posX;
	}
	else if (dir == 'a' || dir == 'A') {
		nextPosX = posX - 1;
	}
	else if (dir == 'd' || dir == 'D') {
		nextPosX = posX + 1;
	}

	return nextPosX;
}

int Player::nextY(char dir) {
	int nextPosY = 0;

	if (dir == 'w' || dir == 'W') {
		nextPosY = posY - 1;
	}
	else if (dir == 'a' || dir == 'A' || dir == 'd' || dir == 'D') {
		nextPosY = posY;
	}
	else if (dir == 's' || dir == 'S') {
		nextPosY = posY + 1;
	}

	return nextPosY;
}

void Player::Move(char dir, Map& map, Light& light)
{
	if (dir == 'w' || dir == 'W') {
		posY -= 1;								// move up
		map.AddCoord(posX, posY, name);
		map.AddCoord(posX, posY + 1, 'o');
		light.AddCoord(posX, posY, map);
		light.AddCoord(posX, posY + 1, map);

	}
	else if (dir == 'a' || dir == 'A') {
		posX -= 1;								// move left
		map.AddCoord(posX, posY, name);
		map.AddCoord(posX + 1, posY, 'o');
		light.AddCoord(posX, posY, map);
		light.AddCoord(posX + 1, posY, map);

	}
	else if (dir == 's' || dir == 'S') {
		posY += 1;								//move down
		map.AddCoord(posX, posY, name);
		map.AddCoord(posX, posY - 1, 'o');
		light.AddCoord(posX, posY, map);
		light.AddCoord(posX, posY - 1, map);
	}
	else if (dir == 'd' || dir == 'D') {
		posX += 1;								//move right
		map.AddCoord(posX, posY, name);
		map.AddCoord(posX - 1, posY, 'o');
		light.AddCoord(posX, posY, map);
		light.AddCoord(posX - 1, posY, map);
	}
	ChangeOxygenLevel(-1);
}

void Player::TakeDamage(int amount)
{
	health -= amount;
}

void Player::ChangeOxygenLevel(int amount)
{
	oxygen += amount;		//amount can be +/-
}

bool Player::CanMove(char dir, Map& map) {

    if (map.getMap()[nextY(dir)][nextX(dir)] == 'x') {
        return false;
    }
    return true;
}

bool Player::IsDead() {

	if (oxygen > 0 && health > 0) return false;
	else return true;
}