#ifndef __ENEMY_SHIPHORIZONTALCANON_H__
#define __ENEMY_SHIPHORIZONTALCANON_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_ShipHorizontalCanon : public Enemy
{
private:
	iPoint originalpos;
	Animation enemypos;
	Animation shootopen;
	Animation shootclose;
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

	Enemy_ShipHorizontalCanon(int x, int y);

	void Move();
	void Shoot();
};

#endif

