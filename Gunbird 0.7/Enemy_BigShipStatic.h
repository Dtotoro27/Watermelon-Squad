#ifndef __ENEMY_BIGSHIPSTATIC_H__
#define __ENEMY_BIGSHIPSTATIC_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BigShipStatic : public Enemy
{
private:
	iPoint originalpos;
	Animation base;
	Animation shootopen;
	Animation shootclose;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint timer = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;


public:

	Enemy_BigShipStatic(int x, int y);

	void Move();
	void Shoot();
};

#endif