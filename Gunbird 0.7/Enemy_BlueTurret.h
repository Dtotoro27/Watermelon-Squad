#ifndef __ENEMY_BLUETURRET_H__
#define __ENEMY_BLUETURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BlueTurret : public Enemy
{
private:
	iPoint originalpos;
	Animation enemy_position_1;
	Animation enemy_position_2;
	Animation enemy_position_3;
	Animation enemy_position_4;
	Animation enemy_position_5;
	Animation enemy_position_6;
	Animation enemy_position_7;
	Animation enemy_position_8;
	Animation enemy_position_9;
	Animation enemy_position_10;
	Animation enemy_position_11;
	Animation enemy_position_12;
	Animation enemy_position_13;
	Animation enemy_position_14;
	Animation enemy_position_15;
	Animation enemy_position_16;
	Animation enemy_position_17;
	Animation enemy_position_18;
	Animation enemy_position_19;
	Animation enemy_position_20;
	Animation enemy_position_21;
	Animation enemy_position_22;
	Animation enemy_position_23;
	Animation enemy_position_24;
	Animation enemy_position_25;
	Animation enemy_position_26;
	Animation enemy_position_27;
	Animation enemy_position_28;
	Animation enemy_position_29;
	Animation enemy_position_30;
	Animation enemy_position_31;
	Animation enemy_position_32;

	Animation appear;
	Path movement;
	Uint32 start_time = 0;
	Uint32 now = 0;
	uint time = 0;
	float pos_x;
	float pos_y;
	float module;
	float v_x;
	float v_y;

public:

	Enemy_BlueTurret(int x, int y);

	void Move();
	void Shoot();
};

#endif
