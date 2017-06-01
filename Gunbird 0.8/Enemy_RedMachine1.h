#ifndef __ENEMY_REDMACHINE1_H__
#define __ENEMY_REDMACHINE1_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_RedMachine1 : public Enemy
{
private:
	iPoint originalpos;
	Animation machine;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;
	int shoots=0;
	bool shooting=false;

public:

	Enemy_RedMachine1(int x, int y);

	void Move();
	void Shoot();
};

#endif