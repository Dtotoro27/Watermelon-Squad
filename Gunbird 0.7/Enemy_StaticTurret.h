#ifndef __ENEMY_STATICTURRET_H__
#define __ENEMY_STATICTURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_StaticTurret : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;

public:

	Enemy_StaticTurret(int x, int y);

	void Move();
	void Shoot();
};

#endif
