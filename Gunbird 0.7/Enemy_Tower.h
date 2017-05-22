#ifndef __ENEMY_TOWER_H__
#define __ENEMY_TOWER_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Tower : public Enemy
{
private:
	iPoint originalpos;
	Animation stand;
	Animation enemy_position;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;

public:

	Enemy_Tower(int x, int y);

	void Move();
	void Shoot();
};

#endif