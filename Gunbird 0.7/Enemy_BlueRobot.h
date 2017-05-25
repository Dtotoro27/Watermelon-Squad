#ifndef __ENEMY_BLUEROBOT_H__
#define __ENEMY_BLUEROBOT_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BlueRobot : public Enemy
{
private:
	iPoint originalpos;
	Animation robot;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;

public:

	Enemy_BlueRobot(int x, int y);

	void Move();
	void Shoot();
};

#endif
