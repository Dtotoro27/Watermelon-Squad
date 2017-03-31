#ifndef __MODULEWELCOMEPAGE_H__
#define __MODULEWELCOMEPAGE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleWelcomePage : public Module
{
public:
	ModuleWelcomePage();
	~ModuleWelcomePage();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	bool change = true;
	SDL_Texture* welcome = nullptr;
};

#endif // __MODULEWELCOMEPAGE_H__