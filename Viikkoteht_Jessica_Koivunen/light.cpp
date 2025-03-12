#include "light.h"

void Light::MallocLitMap()
{
	litmap = (char**)malloc(N * sizeof(char*));
	//then allocate N-long array of chars to each char*
	for (int i = 0; i < N-1; i++) {
		litmap[i] = (char*)malloc(N * sizeof(char));
	}
}

void Light::InitLitMap()
{
	for (int a = 0; a < N-1 ; a++) {
		for (int b = 0; b < N; b++) {

			if (b == N-1) litmap[a][b] = '\n';
			else litmap[a][b] = '*';
		}
	}
}

Light::Light(Map& map)
{
	N = map.getN();
	MallocLitMap();
	InitLitMap();
}

void Light::ChangeBattery(int amount)
{
	battery += amount;
}

void Light::LightArea(char dir, Player& player, Map& map)
{
	if (battery >= 4) {
		if (dir == 'i' || dir == 'I')
			AddCoord(player.getPosX(), player.getPosY() - 1, map);
		if (dir == 'j' || dir == 'J')
			AddCoord(player.getPosX() - 1, player.getPosY(), map);
		if (dir == 'k' || dir == 'K')
			AddCoord(player.getPosX(), player.getPosY() + 1, map);
		if (dir == 'l' || dir == 'L')
			AddCoord(player.getPosX() + 1, player.getPosY(), map);

		ChangeBattery(-4);
		player.ChangeOxygenLevel(-1);
	}
	else cout << "Low battery. Unable to use light.\n";
}

void Light::PrintMap()
{
	for (int d = 0; d < N-1; d++) {
		for (int e = 0; e < N; e++) {
			cout << litmap[d][e];
		}
	}
	cout << "\n\n";
}

void Light::AddCoord(int x, int y, Map& map)
{
	litmap[y][x] = map.getMap()[y][x];
}