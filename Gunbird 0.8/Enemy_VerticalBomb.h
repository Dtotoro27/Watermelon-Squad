#ifndef __ENEMY_VERTICALBOMB_H__
#define __ENEMY_VERTICALBOMB_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_VerticalBomb : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;
	int bomb_num = 1;

public:

	Enemy_VerticalBomb(int x, int y);
	void Move();
};

#endif