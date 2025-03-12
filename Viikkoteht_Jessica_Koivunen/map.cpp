#include "map.h"

void Map::MallocMap() {
	//assuming all maps are square
	//using char count (N) to allocate memory for (char ** map)
	//first allocate N ammount of char* to "map"
	map = (char**)malloc(N * sizeof(char*));
	//then allocate N-long array of chars to each char*
	for (int i = 0; i < N; i++) {
		map[i] = (char*)malloc(N * sizeof(char));
	}
}

int Map::FindMap()
{
	mapFile.open(filepath);

	//check if opened
	if (!mapFile.is_open()) {
		//if open failure, return value indicating error			
		cout << "Error opening file.\n\n";
		return -1;
	}
	else {
		//read first row, count number of characters
		string row;
		getline(mapFile, row);
		N = row.length() + 1;
		//close file
		mapFile.close();
		return 0;
	}
}

void Map::InitMap()
{
	//save map chars to pointers
	mapFile.open(filepath);

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			char c;
			c = mapFile.get();
			map[a][b] = c;
		}
	}
	//close file
	mapFile.close();
}

void Map::AddCoord(int x, int y, char name)
{
	map[y][x] = name;
}

void Map::PrintMap()
{
	for (int d = 0; d < N; d++) {
		for (int e = 0; e < N; e++) {
			cout << map[d][e];
		}
	}
	cout << "\n\n";
}