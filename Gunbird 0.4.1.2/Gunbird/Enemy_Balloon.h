#ifndef __ENEMY_BALLOON_H__
#define __ENEMY_BALLOON_H__

#include "Enemy.h"

class Enemy_Balloon : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_x = 0;
	Animation fly;

public:

	Enemy_Balloon(int x, int y);

	void Move();
};

#endif // __ENEMY_REDBIRD_H__