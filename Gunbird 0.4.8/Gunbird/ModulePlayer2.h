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
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider *c1, Collider *c2);
	bool ModulePlayer2::GodMode(bool godmode);
	uint audio_shot;

public:

	SDL_Texture* graphics = nullptr;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation left;
	Animation right;
	Collider* player2hitbox;
	bool destroyed = false;
	bool godmode = false;
	iPoint position;
	iPoint camera_limitsp2;
	int powerUps = 0;

};

#endif
