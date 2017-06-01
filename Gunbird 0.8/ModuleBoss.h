#ifndef _ModuleBoss_H_
#define _ModuleBoss_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleBoss : public Module
{
private:
	int delay;
	float boss_speed;
	float boss_x;
public:
	ModuleBoss();
	~ModuleBoss();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	SDL_Texture* bosstexture = nullptr;
	SDL_Texture* startplayer2texture = nullptr;
	bool change = true;
	Animation boss_animation;
	bool pause = false;


};

#endif