#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"
GameObject::GameObject(const char* texturesheet, int x, int y)
{
	ObjTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2; 
}

SDL_Rect GameObject::GetSrcRect()
{
	return srcRect;
}

SDL_Rect GameObject::GetDestRect()
{
	return destRect;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, ObjTexture, &srcRect, &destRect);
}

MGO::MGO(const char* texturesheet, int x, int y)
{
	ObjTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

Player::Player(const char* texturesheet, int x, int y)
{
	ObjTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	position = 2;
}



void Player::Update()
{
	static int animation = 0;

	animation++;


	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 1;//צטפנא לוםÿוע נאחלונ
	destRect.w = srcRect.w * 1;//צטפנא לוםÿוע נאחלונ

	if (animation >= 20)
	{
		animation -= 20;
		switch (position)
		{
		case 0:
			position = 1;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 1:
			position = 0;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 2:
			position = 3;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 3:
			position = 2;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 4:
			position = 5;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 5:
			position = 4;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 6:
			position = 7;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		case 7:
			position = 6;
			ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman0.bmp");
			break;
		default:
			break;
		}
	}
}


void Player::Move(SDL_Event e)
{
		if (e.key.keysym.sym == SDLK_LEFT)
		{
			xpos -= 2;
			if (position != 1)
			{
				ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman1.bmp");
				position = 0;
			}
		}
		if (e.key.keysym.sym == SDLK_RIGHT)
		{
			xpos += 2;
			if (position != 3)
			{
				ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman3.bmp");
				position = 2;
			}
		}
		if (e.key.keysym.sym == SDLK_UP)
		{
			ypos -= 2;
			if (position != 5)
			{
				ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman2.bmp");
				position = 4;
			}
		}
		if (e.key.keysym.sym == SDLK_DOWN)
		{
			ypos += 2;
			if (position != 7)
			{
				ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\Pacman4.bmp");
				position = 6;
			}
		}
	
}

int Player::Vector(SDL_Event e)
{
	int vector;
	if (e.key.keysym.sym == SDLK_LEFT)
	{
		vector = 1;
	}
	if (e.key.keysym.sym == SDLK_RIGHT)
	{
		vector = 2;
	}
	if (e.key.keysym.sym == SDLK_UP)
	{
		vector = 3;
	}
	if (e.key.keysym.sym == SDLK_DOWN)
	{
		vector = 4;
	}
	return vector;
}

void Player::MoveBack(int vector)
{
	if (vector == 1) xpos += 2;
	if (vector == 2) xpos -= 2;
	if (vector == 3) ypos += 2;
	if (vector == 4) ypos -= 2;
}


Enemy::Enemy(const char* texturesheet, int x, int y)
{
	ObjTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

Ghost::Ghost(int a, int x, int y)
{
	switch (a)
	{
	case 0:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost1.bmp");
		break;
	case 1:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost2.bmp");
		break;
	case 2:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost3.bmp");
		break;
	case 3:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost4.bmp");
		break;
	case 4:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost5.bmp");
		break;
	case 5:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost6.bmp");
		break;

	default:
		break;
	}
	
	xpos = x;
	ypos = y;
	vector = 1;

}

void Ghost::Update()
{

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 1;//צטפנא לוםÿוע נאחלונ
	destRect.w = srcRect.w * 1;//צטפנא לוםÿוע נאחלונ
	TIK++;
	if (TIK >= 30)
	{
		TIK = 0;
		switch (rand()%4)
		{
		case 0:
			vector = 1;
			break;
		case 1:
			vector = 2;
			break;
		case 2:
			vector = 2;
			break;
		case 3:
			vector = 4;
			break;
		default:
			break;
		}
	}
	switch (vector)
	{
	case 1:
		xpos -= 3;
		break;
	case 2:
		xpos += 3;
		break;
	case 3:
		ypos -= 3;
		break;
	case 4:
		ypos += 3;
		break;
	default:
		break;
	}
}

void Ghost::MoveBack()
{
	if (vector == 1) xpos += 3;
	if (vector == 2) xpos -= 3;
	if (vector == 3) ypos += 3;
	if (vector == 4) ypos -= 3;
}

int Ghost::EffectForPlayer(int x, int y)
{
	if ( (x - xpos)*(x-xpos) < 32*32 && (y-ypos)*(y-ypos) < 32*32)
	{
		return 1;
	}
	return 0;
}

bool Ghost::Killed(int x, int y)
{
	if ((x - xpos) * (x - xpos) < 32 * 32 && (y - ypos) * (y - ypos) < 32 * 32)
	{
		return true;
	}
	return false;
} 
void Ghost::Change(int a)
{
	switch (a)
	{
	case 0:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost1.bmp");
		break;
	case 1:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost2.bmp");
		break;
	case 2:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost3.bmp");
		break;
	case 3:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost4.bmp");
		break;
	case 4:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost5.bmp");
		break;
	case 5:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\ghost6.bmp");
		break;
	case 6:
		ObjTexture = TextureManager::LoadTexture("C:\\Users\\stast\\Desktop\\programming\\C++\\kursovik\\DEV\\test\\Project2\\assets\\fghost.bmp");
		break;
	default:
		break;
	}
}

Dot::Dot(const char* texturesheet, int x, int y)
{

	ObjTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void Dot::Update()
{
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 1;//צטפנא לוםÿוע נאחלונ
	destRect.w = srcRect.w * 1;//צטפנא לוםÿוע נאחלונ
}

bool Dot::Take(int x, int y)
{
	if ((xpos - x ) * (xpos - x) < 32 * 32 - 800  && (ypos - y ) * (ypos - y ) < 32 * 32 - 800 ) return true;
	return false;
}

void Dot::Delete()
{
	del = true;
	ObjTexture = TextureManager::LoadTexture("");
}

