#ifndef __ENEMY_BIRDBODY_H__
#define __ENEMY_BIRDBODY_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BirdBody : public Enemy
{
private:
	iPoint originalpos;

	Animation enemypos;
	Animation motor;

	uint collision = 0;
	bool left = true;
	bool right = false;

	uint timermove = 0;
	uint timer = 0;

	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;

public:

	Enemy_BirdBody(int x, int y);

	void Move();
	void Shoot();
};

#endif



