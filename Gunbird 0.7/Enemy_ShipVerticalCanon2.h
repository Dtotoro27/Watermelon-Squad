#ifndef __ENEMY_SHIPVERTICALCANON2_H__
#define __ENEMY_SHIPVERTICALCANON2_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_ShipVerticalCanon2 : public Enemy
{
private:
	iPoint originalpos;
	Animation enemypos;
	Animation shootopen_left;
	Animation shootopen_right;
	Animation shootclose_left;
	Animation shootclose_right;
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

	Enemy_ShipVerticalCanon2(int x, int y);

	void Move();
	void Shoot();
};

#endif


