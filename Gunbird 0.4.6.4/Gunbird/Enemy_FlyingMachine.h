#ifndef __ENEMY_FLYINGMACHINE_H__
#define __ENEMY_FLYINGMACHINE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_FlyingMachine : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;

public:

	Enemy_FlyingMachine(int x, int y);
	
	void Move();
};

#endif
