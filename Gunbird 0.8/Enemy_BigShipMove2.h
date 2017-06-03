#ifndef __ENEMY_BIGSHIPMOVE2_H__
#define __ENEMY_BIGSHIPMOVE2_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BigShipMove2 : public Enemy
{
private:
	iPoint originalpos;
	Animation base;
	Animation shootopen;
	Animation shootclose;
	Animation water;
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

	Enemy_BigShipMove2(int x, int y);

	void Move();
	void Shoot();
};

#endif
