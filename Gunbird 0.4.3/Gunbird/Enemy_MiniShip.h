#ifndef __ENEMY_MINISHIP_H__
#define __ENEMY_MINISHIP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_MiniShip : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	iPoint originalpos;
	Animation fly;

public:

	Enemy_MiniShip(int x, int y);
	Path movement;
	void Move();
};

#endif