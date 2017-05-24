#ifndef __ENEMY_SURFINGTURRET_H__
#define __ENEMY_SURFINGTURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_SurfingTurret : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;

public:

	Enemy_SurfingTurret(int x, int y);

	void Move();
	void Shoot();
};

#endif
