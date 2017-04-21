#ifndef _ModuleMine_H_
#define _ModuleMine_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleMine : public Module
{
public:
	ModuleMine();
	~ModuleMine();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	bool change = true;
	SDL_Texture* minetexture = nullptr;
	SDL_Texture* minetexture2 = nullptr;
	SDL_Texture* mineworkertexture = nullptr;
	SDL_Texture* pw_texture = nullptr;
	SDL_Rect mine;
	Collider* pw_hitbox;
	iPoint pw_pos;
	Animation mineworker;
	Animation pw_anim;


};

#endif