#ifndef __ModuleWelcome_H__
#define __ModuleWelcome_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleWelcome : public Module
{
public:
	ModuleWelcome();
	~ModuleWelcome();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	bool change = true;
	SDL_Texture* welcometexture = nullptr;
	SDL_Rect welcome;

};

#endif

