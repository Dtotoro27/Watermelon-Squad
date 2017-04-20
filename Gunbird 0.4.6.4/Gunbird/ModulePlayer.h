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
	void OnCollision(Collider *c1, Collider *c2); //PON LOS ASTERISCOS DONDE ESTÁ LA NEGRITA

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation left;
	Animation right;
	Collider* playerhitbox;
	bool destroyed = false;
	bool godmode = false;
	iPoint position;
	iPoint camera_limits;
	int powerUps = 0;

};

#endif