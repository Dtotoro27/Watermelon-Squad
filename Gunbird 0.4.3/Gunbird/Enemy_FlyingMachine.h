#ifndef __ENEMY_FLYINGMACHINE_H__
#define __ENEMY_FLYINGMACHINE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_FlyingMachine : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	iPoint originalpos;
	Animation fly;

public:

	Enemy_FlyingMachine(int x, int y);
	Path movement;
	void Move();
};

#endif
