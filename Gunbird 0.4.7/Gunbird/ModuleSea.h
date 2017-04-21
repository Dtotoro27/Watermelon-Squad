#ifndef __ModuleSea_H__
#define __ModuleSea_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSea : public Module
{
public:
	ModuleSea();
	~ModuleSea();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	bool change = true;
	SDL_Texture* seatexture = nullptr;
	SDL_Rect sea;
	
};

#endif