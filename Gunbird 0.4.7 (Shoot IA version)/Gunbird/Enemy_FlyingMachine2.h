#ifndef __ENEMY_FLYINGMACHINE2_H__
#define __ENEMY_FLYINGMACHINE2_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_FlyingMachine2 : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;

public:

	Enemy_FlyingMachine2(int x, int y);

	void Move();
};

#endif

