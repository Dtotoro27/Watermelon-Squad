#ifndef __ENEMY_MINISHIP_H__
#define __ENEMY_MINISHIP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_MiniShip : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;

public:

	Enemy_MiniShip(int x, int y);
	void Move();
};

#endif