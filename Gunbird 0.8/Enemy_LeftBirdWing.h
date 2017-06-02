#ifndef __ENEMY_LEFTBIRDWING_H__
#define __ENEMY_LEFTBIRDWING_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_LeftBirdWing : public Enemy
{
private:
	iPoint originalpos;

	Animation enemypos;


	bool left = true;
	bool right = false;

	bool lwingbroken = false;
	bool rwingbroken = false;

	uint timermove = 0;

	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint timer;

public:

	Enemy_LeftBirdWing(int x, int y);

	void Move();
	void Shoot();
};

#endif




