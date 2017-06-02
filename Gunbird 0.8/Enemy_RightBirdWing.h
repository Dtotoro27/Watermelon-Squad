#ifndef __ENEMY_RIGHTBIRDWING_H__
#define __ENEMY_RIGHTBIRDWING_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_RightBirdWing : public Enemy
{
private:
	iPoint originalpos;

	Animation enemypos;
	Animation shootopen;
	Animation shootclose;

	bool left = true;
	bool right = false;


	uint timermove = 0;
	uint timer2 = 0;

	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint timer;

	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;

public:

	Enemy_RightBirdWing(int x, int y);

	void Move();
	void Shoot();
};

#endif
