#ifndef __ENEMY_SHIPBACKTURRET_H__
#define __ENEMY_SHIPBACKTURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_ShipBackTurret : public Enemy
{
private:
	iPoint originalpos;
	Animation base;
	Animation shootopen;
	Animation shootclose;
	Animation enemy_position;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint timer = 100;
	uint timer2 = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;

public:

	Enemy_ShipBackTurret(int x, int y);

	void Move();
	void Shoot();
};

#endif
