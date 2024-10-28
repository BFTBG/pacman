#pragma once
#include "Game.h"
#include "GameObject.h"
class Map
{
	
public:

	Map();
	~Map();
	void LoadMap(int arr[20][25]);
	void DrawMap();
	int Get(int i, int j);
	
	
private:
	int map[26][25];
	SDL_Rect src, dest;
	SDL_Texture* wall;
	SDL_Texture* abyss;


};

