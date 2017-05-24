#ifndef __ENEMY_FLYINGMACHINE_H__
#define __ENEMY_FLYINGMACHINE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_FlyingMachine : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position_s;
	Animation enemy_position_sa;
	Animation enemy_position_a;
	Animation enemy_position_wa;
	Animation enemy_position_w;
	Animation enemy_position_wd;
	Animation enemy_position_d;
	Animation enemy_position_sd;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;

public:

	Enemy_FlyingMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif
