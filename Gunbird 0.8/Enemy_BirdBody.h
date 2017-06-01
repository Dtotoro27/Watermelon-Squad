#ifndef __ENEMY_BIRDBODY_H__
#define __ENEMY_BIRDBODY_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BirdBody : public Enemy
{
private:
	iPoint originalpos;
	iPoint originalposleftwing;

	Animation lwing;
	Animation brokenlwing;

	Animation enemypos;
	Animation motor;
	Animation shootopen;
	Animation shootclose;

	bool left = true;
	bool right = false;

	bool lwingbroken = false;
	bool rwingbroken = false;

	uint timermove = 0;

	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;
	uint timer;

public:

	Enemy_BirdBody(int x, int y);

	void Move();
	void Shoot();
};

#endif



