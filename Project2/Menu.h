#pragma once
#ifndef Menu_hpp
#define Menu_hpp
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
class Menu {
public:
	Menu();
	~Menu();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void render();
	void clean();

	bool running() { return isRunning; }


	static SDL_Renderer *renderer;

	static SDL_Event event;
private:
	bool isRunning = false;
	SDL_Window* window;




};
#endif /*Game_hpp*/