#ifndef _ModulePlayer2_H_
#define _ModulePlayer2_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer2 : public Module
{
private:
	int delay = 0;
	bool shooting;
	int delay2 = 0;
	bool bomb = false;
	int delay3 = 0;


public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider *c1, Collider *c2);
	uint audio_shot;

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* ash_bomb_texture = nullptr;
	SDL_Texture* ui = nullptr;
	uint score;

	Animation* current_animation = nullptr;
	Animation idle;
	Animation immortal;
	Animation left;
	Animation right;


	Animation ash_bomb_animation;
	Animation bomb_throw;

	Collider* player2hitbox;
	Collider* bombhitbox;
	bool destroyed = false;
	bool godmode2 = false;
	iPoint position;
	iPoint camera_limitsp2;
	iPoint bomb_position;
	iPoint time;
	iPoint position_immortal;
	int powerUps = 0;
	int lives = 2;

	int max_bomb = 2;
	bool dead = false;

};

#endif
