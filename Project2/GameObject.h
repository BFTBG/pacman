#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"

class GameObject {
public:
	GameObject() {};
	GameObject(const char* texturesheet, int x, int y);
	~GameObject() {};
	void Update();
	void Render();
	
	SDL_Rect GetSrcRect();
	SDL_Rect GetDestRect();
	
	int xpos;
	int ypos;
	SDL_Texture* ObjTexture;
	SDL_Rect srcRect, destRect;

};


//MGO - двигающийся игровой объект
class MGO : public GameObject
{
public:
	MGO(){}
	MGO(const char* texturesheeet, int x, int y);
	~MGO(){}
};


class Player : public MGO 
{
public:
	Player() {}
	Player(const char* texturesheeet, int x, int y);
	~Player() {}
	void Move(SDL_Event e);
	int Vector(SDL_Event e);
	void MoveBack(int vector);
	void Update();

	int position;
	
};


class Enemy : public MGO
{
public:
	Enemy() {}
	Enemy(const char* texturesheeet, int x, int y);
	~Enemy() {}
	int position;
	int vector;
	
	
	virtual int EffectForPlayer(int x, int y) { return 0; }

	virtual void MoveBack(int vector) {};


};

class Ghost : public Enemy
{
public:
	Ghost() {}
	Ghost(int a, int x, int y);
	~Ghost() {}
	int TIK=0;
	void MoveBack();
	virtual void Update();
	virtual int EffectForPlayer(int x, int y);
	virtual bool Killed(int x, int y);
	void Change(int a);


};

class Dot : public MGO
{
public:
	Dot() {}
	Dot(const char* texturesheeet, int x, int y);
	~Dot() {}
	bool Take(int x, int y);
	void Update();
	void Delete();
	bool del = false;

};

