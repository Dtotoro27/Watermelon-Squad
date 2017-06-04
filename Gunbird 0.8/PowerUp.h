#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "Enemy.h"
#include "Path.h"

class PowerUp : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;
	bool onscreen = true;
	bool left = true;
	bool up = true;

public:

	PowerUp(int x, int y);
	void Move();
};

#endif
