#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"
#include "Text.h"
#include <string>
SDL_Event event1;
Map* map1;
Dot* dot[500];
Dot* sdot[500];
int dotID = 0;
int SdotID = 0;
int dotEat = 0;
int i, j;


int enemyCount = 4;

int  SCORE;

int times=0;



Player* player;
Ghost* ghost[4];
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


const int TOTAL_DATA = 10;
Sint32 gData[TOTAL_DATA];

Game::Game()
{}
Game::~Game()
{
}
void Game::init(const char* title, int width, int height, bool fullscreen)
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
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;

	}
	else {
		isRunning = false;
	}
	

	int Sdot = 0;
	map1 = new Map();
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			
			if (map1->Get(j, i) != 2)
			{
				if (((i * j) == 100 || (i * j) == 25 || (i * j) == 75 || (i * j) == 89))
				{
					sdot[SdotID] = new Dot("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\superdot.bmp", i * 32, j * 32);
					
					SdotID++;
					
				}
				else
				{
					dot[dotID] = new Dot("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\dot.bmp", i * 32, j * 32);
					dotID++;
				}
			}
			
				
		}
	
	}
	player = new Player("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp", 385, 510);
	
	for (int g = 0; g < enemyCount; g++)
	{
		ghost[g] = new Ghost(g, g * 100 + 32,300 );
	}
	
	


}
void Game::handleEvents()
{
	SDL_Event event;
	

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:

		if (event.key.keysym.sym == SDLK_LEFT ) event1 = event;
		if (event.key.keysym.sym == SDLK_RIGHT ) event1 = event;
		if (event.key.keysym.sym == SDLK_UP) event1 = event;  
		if (event.key.keysym.sym == SDLK_DOWN) event1 = event;  
		if (event.key.keysym.sym == SDLK_q) isRunning = false;
		break;
	default:
		break;
	}
}
void Game::update()
{
	int vector;


	player->Update();
	player->Move(event1);
	vector = player->Vector(event1);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (map1->Get(j, i) == 2)
			{
				if ((player->xpos - i * 32) * (player->xpos - i * 32) < 32 * 32 && (player->ypos - j * 32) * (player->ypos - j * 32) < 32 * 32)
				{
					player->MoveBack(vector);
				}
			}
		}
	}
	for (int g = 0; g < enemyCount; g++)
	{
		ghost[g]->Update();
		if (enemyCount) for (j = enemyCount - 1; j >= 0; j--)
		{
			if ((ghost[g]->xpos - ghost[j]->xpos) * (ghost[g]->xpos - ghost[j]->xpos) < 1024 && (ghost[g]->ypos - ghost[j]->ypos) * (ghost[g]->ypos - ghost[j]->ypos) < 1024 && j != g)
			{
				ghost[g]->MoveBack();
			}
		}

		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (map1->Get(j, i) == 2)
				{
					if ((ghost[g]->xpos - i * 32) * (ghost[g]->xpos - i * 32) < 32 * 32 - 200 && (ghost[g]->ypos - j * 32) * (ghost[g]->ypos - j * 32) < 32 * 32 - 200)
					{
						ghost[g]->MoveBack();
					}
				}
			}
		}
		if (ghost[g]->EffectForPlayer(player->xpos, player->ypos))
		{
			if (!times)
			{
				isRunning = false;
			}

		}
	}
	

	for (i = 0; i < dotID; i++)
	{
		if (dot[i]->Take(player->xpos, player->ypos) && !dot[i]->del)
		{
			dot[i]->Delete();
			dotEat++;
			SCORE += 10;
		}
	}
	for (i = 0; i < SdotID; i++)
	{
		if (sdot[i]->Take(player->xpos, player->ypos) && !sdot[i]->del)
		{
			sdot[i]->Delete();
			dotEat++;
			SCORE += 10;
			for (j = 0; j < enemyCount; j++)
			{
				ghost[j]->Change(6);
			}
			times = 1000;

		}
	}
	if (times)
	{
		times--;
		std::cout << times << std::endl;
		for(int g = 0; g < enemyCount; g++)
		{
			if (ghost[g]->Killed(player->xpos, player->ypos))
			{
				delete ghost[g];

				for (j = g + 1; j < enemyCount; j++)
				{
					ghost[j - 1] = ghost[j];

				}
				enemyCount-=1;
				SCORE += 100;
				break;
			}
		}
	
		if (!times)
		{
			if (enemyCount)
			{
				for (int g = enemyCount-1; g >=0; g--)
				{
					ghost[g]->Change(g);
				}
			}
			
		}
	}
	for (i = 0; i < dotID; i++) dot[i]->Update();
	for (i = 0; i < SdotID; i++) sdot[i]->Update();
	if (dotEat == dotID)
	{
		isRunning = false;
		
	}
	
}
void Game::render()
{
	SDL_RenderClear(renderer);
	map1->DrawMap();
	for (i = 0; i < dotID; i++) dot[i]->Render();
	for (i = 0; i < SdotID; i++) sdot[i]->Render();
	player->Render();
	DynamicText text1("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	DynamicText text2("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ARCADECLASSIC.TTF", 32);
	DynamicText text3("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\PAC-FONT.TTF", 32);
	text3.DrawText(renderer, "PACMAN", 170, 645, 500, 100);
	text1.DrawText(renderer, "SCORE ", 0, 725, 200, 100);
	text2.DrawText(renderer, std::to_string(SCORE),250, 725, 200, 100);
	for (i = 0; i < enemyCount; i++) ghost[i]->Render();
	SDL_RenderPresent(renderer);
}

int Game::Score()
{
	return SCORE;
}
void Game::clean()
{


	gData[0] = SCORE;
	
	SDL_RWops* file = SDL_RWFromFile("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\SCORE.dat", "a+b");
	if (file != NULL)
	{
		

		
		SDL_RWwrite(file, &gData[0], sizeof(Sint32), 1);
		

		
		SDL_RWclose(file);
		
	}
	else
	{
		printf("Error: Unable to save file! %s\n", SDL_GetError());
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	std::cout << "Game Cleaned" << std::endl;
	std::cout << SCORE << std::endl;


}