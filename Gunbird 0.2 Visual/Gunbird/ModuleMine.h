#ifndef __ModuleMine_H__
#define __ModuleMine_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

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
	SDL_Rect mine;
	

};

#endif