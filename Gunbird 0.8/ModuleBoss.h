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
	float boss_speed;
	float boss_y;
	float boss_y2;
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
	Animation boss_animation2;
	int polla = 0;
	bool pause = false;
	bool spawnship = false;
	bool spawnbird = false;
	

	uint timer = 0;

};

#endif