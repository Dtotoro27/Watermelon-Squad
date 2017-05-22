#ifndef __ENEMY_BOMB2_H__
#define __ENEMY_BOMB2_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Bomb2 : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;
	int bomb_num = 1;

public:

	Enemy_Bomb2(int x, int y);
	void Move();
};

#endif
