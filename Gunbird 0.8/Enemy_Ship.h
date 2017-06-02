#ifndef __ENEMY_SHIP_H__
#define __ENEMY_SHIP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Ship : public Enemy
{
private:
	iPoint originalpos;
	iPoint secondpos;
	Animation ship;
	Path movement;
	Path movement2;
	Path movement3;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint timer = 0;
	uint down_movement = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;



public:

	Enemy_Ship(int x, int y);

	void Move();
	void Shoot();
};

#endif
