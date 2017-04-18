#ifndef __ENEMY_BALLOON_H__
#define __ENEMY_BALLOON_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Balloon : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	iPoint originalpos;
	Animation fly;

public:

	Enemy_Balloon(int x, int y);
	Path movement;
	void Move();
};

#endif
