#pragma once
#ifndef Game_hpp
#define Game_hpp
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
class Game {
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	int Score();
	bool running() { return isRunning; }


	static SDL_Renderer *renderer;
	static SDL_Event event;
private:
	bool isRunning = false;
	SDL_Window* window;

	

};
#endif /*Game_hpp*/