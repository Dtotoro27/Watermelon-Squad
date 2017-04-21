#ifndef __ENEMY_TURRET_H__
#define __ENEMY_TURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Turret : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;

public:

	Enemy_Turret(int x, int y);
	void Move();
};

#endif