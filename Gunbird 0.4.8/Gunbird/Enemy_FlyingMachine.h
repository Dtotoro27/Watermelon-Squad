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
	int shoots = 0;
	Uint32 start_time = 0;
	Uint32 now = 0;

public:

	Enemy_FlyingMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif
