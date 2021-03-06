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
	bool player2 = false;
	SDL_Texture* minetexture = nullptr;
	SDL_Texture* minetexture2 = nullptr;
	SDL_Texture* mineanimationtexture = nullptr;
	SDL_Texture* mineworkertexture = nullptr;
	SDL_Texture* startplayer2texture= nullptr;
	SDL_Rect mine;
	Animation mineworkerwalkright;
	Animation mineworkerwalkleft;
	Animation mineworkerstand;
	Animation startplayer2animation;
	Animation p1, p2;
	Animation mineanimation;
	float mineworker_x;
	float mineworker_x2;
	float mineworker_x3;
	iPoint mineworkeractive;
	


};

#endif