#ifndef __SHIP_CORPSE_H__
#define __SHIP_CORPSE_H__

#include "Enemy.h"
#include "Path.h"

class Ship_Corpse : public Enemy
{
private:
	iPoint originalpos;
	Animation base;
	Path movement;
	float pos_x;
	float pos_y;
	float module;
	


public:

	Ship_Corpse(int x, int y);

	void Move();
	void Shoot();
};

#endif