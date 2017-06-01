#ifndef __EXTRABOMB_H__
#define __EXTRABOMB_H__

#include "Enemy.h"
#include "Path.h"

class ExtraBomb : public Enemy
{
private:
	iPoint originalpos;
	Animation fly;
	Path movement;
	bool onscreen = true;
	bool left = true;
	bool up = false;

public:

	ExtraBomb(int x, int y);
	void Move();
};

#endif
