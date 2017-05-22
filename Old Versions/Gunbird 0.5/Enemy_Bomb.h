#ifndef __ENEMY_BOMB_H__
#define __ENEMY_BOMB_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Bomb : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;
	int bomb_num = 1;

public:

	Enemy_Bomb(int x, int y);
	void Move();
};

#endif