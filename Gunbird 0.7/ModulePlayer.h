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

private:
	int delay = 0;
	bool shooting;
	float delay2 = 0;	
	bool bomb = false;
	bool collision = false;
	int timer2 = 0;
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
	SDL_Texture* ash_bomb_texture = nullptr;
	SDL_Texture* valnus_bomb_texture = nullptr;
	uint score = 0;


	Animation* current_animation = nullptr;
	Animation idle;
	Animation immortal;
	Animation left;
	Animation right;
	Animation collision_animation;

	Animation ash_bomb_animation;
	Animation bomb_throw;
	Animation valnus_bomb_animation;
	Animation valnus_bomb;
	

	Collider* playerhitbox;
	Collider* bombhitbox;
	Collider* bombhitbox2;
	bool godmode = false;
	iPoint position;
	iPoint bomb_position;
	iPoint camera_limits;
	iPoint time;
	iPoint position_immortal;
	int powerUps = 0;
	int lives = 2;
	int max_bomb = 2;
	bool dead = false;

};

#endif


