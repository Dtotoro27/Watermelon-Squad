#ifndef __ENEMY_SURFINGTURRET2_H__
#define __ENEMY_SURFINGTURRET2_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_SurfingTurret2 : public Enemy
{
private:
	iPoint originalpos;
	Animation turret1;
	Animation turret2;
	Animation turret3;
	Animation turret4;
	Animation turret5;
	Animation turret6;
	Animation turret7;
	Animation turret8;
	Animation turret9;
	Animation turret10;
	Animation turret11;
	Animation turret12;
	Animation turret13;
	Animation turret14;
	Animation turret15;
	Animation turret16;
	Animation turret17;
	Animation turret18;
	Animation turret19;
	Animation turret20;
	Animation turret21;
	Animation turret22;
	Animation turret23;
	Animation turret24;
	Animation turret25;
	Animation turret26;
	Animation turret27;
	Animation turret28;
	Animation turret29;
	Animation turret30;
	Animation turret31;

	Animation base;
	Animation water;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;

public:

	Enemy_SurfingTurret2(int x, int y);

	void Move();
	void Shoot();
};

#endif
