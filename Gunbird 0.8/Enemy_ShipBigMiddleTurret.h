#ifndef __ENEMY_SHIPBIGMIDDLETURRET_H__
#define __ENEMY_SHIPBIGMIDDLETURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_ShipBigMiddleTurret : public Enemy
{
private:
	iPoint originalpos;
	iPoint secondpos;
	Animation base;
	Animation shootopen;
	Animation shootclose;
	Animation enemy_position;
	Path movement;
	Path movement2;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint timer = 0;

public:

	Enemy_ShipBigMiddleTurret(int x, int y);

	void Move();
	void Shoot();
};

#endif