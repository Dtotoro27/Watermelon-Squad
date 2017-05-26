#ifndef __ENEMY_SHIPBIGMIDDLETURRET_H__
#define __ENEMY_SHIPBIGMIDDLETURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_ShipBigMiddleTurret : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Animation enemy_position;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	bool shoot1 = false;
	bool shoot2 = false;
	bool shoot3 = false;
	bool shoot4 = false;
	bool shoot5 = false;

public:

	Enemy_ShipBigMiddleTurret(int x, int y);

	void Move();
	void Shoot();
};

#endif