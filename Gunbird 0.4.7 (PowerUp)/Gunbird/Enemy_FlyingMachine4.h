#ifndef __ENEMY_FLYINGMACHINE4_H__
#define __ENEMY_FLYINGMACHINE4_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_FlyingMachine4 : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;

public:

	Enemy_FlyingMachine4(int x, int y);

	void Move();
};

#endif

