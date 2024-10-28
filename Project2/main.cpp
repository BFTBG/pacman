#include "Game.h"
#include "Menu.h"
#include "SDL.h"
#include "Text.h"

Menu *menu = nullptr;





int main(int argc,char *argv[])
{
	const int FPS = 100;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	menu = new Menu();

	menu->init("BirchEngine", 800, 820, false); //640 X 480
	while (menu->running())
	{
		frameStart = SDL_GetTicks();

		menu->handleEvents();
		menu->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}
	menu->clean();


	return 0;
}