#ifndef _ModulePlayer_H_
#define _ModulePlayer_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define MAX_POWER_UPS 1

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider *c1, Collider *c2);
	uint audio_shot;

public:

	SDL_Texture* graphics = nullptr;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation immortal;
	Animation left;
	Animation right;
	Animation life_indicator;
	Collider* playerhitbox;
	bool destroyed = false;
	bool godmode = false;
	iPoint position;
	iPoint camera_limits;
	iPoint time;
	int powerUps = 0;
	int lifes = 3;
	bool dead = false;
	int position_lifes;

};

#endif