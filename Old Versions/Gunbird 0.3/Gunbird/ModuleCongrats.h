#ifndef __ModuleCongrats_H__
#define __ModuleCongrats_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleCongrats : public Module
{
public:
	ModuleCongrats();
	~ModuleCongrats();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	bool change = true;
	SDL_Texture* congratstexture = nullptr;
	SDL_Rect congrats;

};

#endif
