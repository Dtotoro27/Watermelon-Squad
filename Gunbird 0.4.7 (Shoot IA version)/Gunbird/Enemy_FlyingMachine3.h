#ifndef __ENEMY_FLYINGMACHINE3_H__
#define __ENEMY_FLYINGMACHINE3_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_FlyingMachine3 : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;

public:

	Enemy_FlyingMachine3(int x, int y);

	void Move();
};

#endif

