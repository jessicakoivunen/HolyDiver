#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Map
{
private:
	char** map;		//pointer pointer map
	int N;			//length of map sides
	string filepath = "";
	ifstream mapFile;
	void MallocMap();
	int FindMap();
	void InitMap();

public:
	virtual int getN() { return N; }
	inline char** getMap() { return map; }
	virtual void AddCoord(int x, int y, char name);
	void PrintMap();
	inline Map(string mapfile) {
		this->filepath = mapfile;
		FindMap();			//get map file + row length
		MallocMap();		//allocate enough memory for map
		InitMap();			//get chars from file to map**
	}
	inline void FreeMemory() { free(map); }
};