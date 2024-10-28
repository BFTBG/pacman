#include "Menu.h"
#include "Text.h"
#include <string>
#include "Game.h"

Game* game = nullptr;

SDL_Event event2;


SDL_Renderer* Menu::renderer = nullptr;

SDL_Event Menu::event;

SDL_Texture* infos;
const int TOTAL_DATA = 1000;
Sint32 Data[TOTAL_DATA];
bool success = false;

void bubble(int* mass, int N)
{
	for (int i = 1; i < N; ++i)
	{
		for (int r = 0; r < N - i; r++)
		{
			if (mass[r] < mass[r + 1])
			{
				int temp = mass[r];
				mass[r] = mass[r + 1];
				mass[r + 1] = temp;
			}
		}
	}
}


Menu::Menu()
{}
Menu::~Menu()
{
}
void Menu::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;

	}
	else {
		isRunning = false;
	}

	/*SDL_Surface* tmpSurface = SDL_LoadBMP("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\wall.bmp");
	infos = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);*/
}

void Menu::handleEvents()
{
	SDL_Event event;


	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:

		if (event.key.keysym.sym == SDLK_SPACE)
		{
			const int FPS = 100;
			const int frameDelay = 1000 / FPS;
			Uint32 frameStart;
			int frameTime;
			game = new Game();
			game->init("BirchEngine", 800, 820, false);
			while (game->running())
			{
				frameStart = SDL_GetTicks();

				game->handleEvents();
				game->update();
				game->render();

				frameTime = SDL_GetTicks() - frameStart;
				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}

			}
			game->clean();
		}
		if (event.key.keysym.sym == SDLK_e)
		{
			
			SDL_Window* inform = nullptr;
			SDL_Surface* screen;
		
			inform = SDL_CreateWindow("INFO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 820, SDL_WINDOW_SHOWN);
			
			screen = SDL_GetWindowSurface(inform);
			SDL_Surface* image;
			image = SDL_LoadBMP("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\info.bmp");
			SDL_BlitSurface(image, NULL, screen, NULL);
			SDL_UpdateWindowSurface(inform);
			SDL_FreeSurface(image);
		
			SDL_Delay(15000);
			SDL_DestroyWindow(inform);


		}
		
		
		if (event.key.keysym.sym == SDLK_q) isRunning = false;
		break;

	default:
		break;
	}
}


void Menu::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, infos, NULL, NULL);

	SDL_RWops* file = SDL_RWFromFile("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\SCORE.dat", "r+b");

	if (file == NULL)
	{
		printf("Warning: Unable to open file! SDL Error: %s\n", SDL_GetError());

		
		file = SDL_RWFromFile("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\SCORE.dat", "w+b");
		if (file != NULL)
		{
			printf("New file created!\n");

			for (int i = 0; i < TOTAL_DATA; ++i)
			{
				Data[i] = 0;
				SDL_RWwrite(file, &Data[i], sizeof(Sint32), 1);
			}

			SDL_RWclose(file);
		}
		else
		{
			printf("Error: Unable to create file! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
	}

	else
	{
		printf("Reading file...!\n");
		for (int i = 0; i < 1000; i++)
		{
				SDL_RWread(file, &Data[i], sizeof(Sint32), 1);

		}
		bubble(Data, 1000);

		SDL_RWclose(file);
	}
	
	std::cout << std::endl;
	DynamicText text1("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	DynamicText text2("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	DynamicText text4("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	DynamicText text5("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	DynamicText text3("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\PAC-FONT.TTF", 32);

	DynamicText Group("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\courier.ttf", 256);
	    


	DynamicText SCORE1("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);

	DynamicText SCORE2("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);

	DynamicText SCORE3("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);

	DynamicText SCORE4("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);

	DynamicText SCORE5("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	text3.DrawText(renderer, "PACMAN", 170, 80, 500, 100);

	int SCORE = game->Score();
	text2.DrawText(renderer, "SCORE", 170, 615, 200, 50);
	Group.DrawText(renderer, "О724Б", 530, 714, 200, 50);
	Group.DrawText(renderer, "Ткаченко С.И.", 535, 754, 200, 50);
	if(SCORE!=0)
		text2.DrawText(renderer, std::to_string(SCORE), 290, 230, 220, 100);
	SCORE1.DrawText(renderer, std::to_string(Data[0]), 420, 615, 50, 50);
	SCORE2.DrawText(renderer, std::to_string(Data[1]), 420, 655, 50, 50);
	SCORE3.DrawText(renderer, std::to_string(Data[2]), 420, 695, 50, 50);
	SCORE4.DrawText(renderer, std::to_string(Data[3]), 420, 735, 50, 50);
	SCORE5.DrawText(renderer, std::to_string(Data[4]), 420, 775, 50, 50);
	
	text1.DrawText(renderer, "Play    Space", 170, 315, 500, 100);
	
	text4.DrawText(renderer, "INFO   E", 170, 415, 300, 100);
	text5.DrawText(renderer, "QUIT   Q", 170, 515, 300, 100);

	SDL_RenderPresent(renderer);
}

void Menu::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

}