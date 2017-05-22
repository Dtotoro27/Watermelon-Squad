#ifndef _ModulePlayer2_H_
#define _ModulePlayer2_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define MAX_POWER_UPS 1

struct SDL_Texture;
struct Collider;

class ModulePlayer2 : public Module
{

private:
	int delay = 0;
	bool shooting;
	float delay2 = 0;
	bool bomb = false;
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
	SDL_Texture* valnus_bomb_texture = nullptr;
	uint score = 0;


	Animation* current_animation = nullptr;
	Animation idle;
	Animation immortal;
	Animation left;
	Animation right;

	Animation ash_bomb_animation;
	Animation bomb_throw;
	Animation valnus_bomb_animation;
	Animation valnus_bomb;


	Collider* player2hitbox;
	Collider* bombhitbox;
	Collider* bombhitbox2;
	bool godmode2 = false;
	iPoint position;
	iPoint bomb_position;
	iPoint camera_limits2;
	iPoint time;
	iPoint position_immortal;
	int powerUps = 0;
	int lives = 2;
	int max_bomb_p2 = 2;
	bool dead = false;

};

#endif
