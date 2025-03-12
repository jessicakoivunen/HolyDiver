#pragma once
#include "map.h"
#include "player.h"

class Light
{
private:
	int battery = 100;
	char** litmap;
	void MallocLitMap();
	void InitLitMap();
	int N = 0;

public:
	inline int getBattery() { return battery; }
	Light(Map& map);
	void ChangeBattery(int amount);
	void LightArea(char dir, class Player& player, Map& map);
	void PrintMap();
	void AddCoord(int x, int y, Map& map);
	inline void FreeMemory() { free(litmap); }
};