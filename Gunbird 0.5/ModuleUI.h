#ifndef _Module_UI_
#define _Module_UI_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleUI : public Module
{
public:
	ModuleUI() {};
	~ModuleUI() {};

	bool Start() { return true; };
	bool CleanUp() { return true; };
	update_status Update() { return UPDATE_CONTINUE; };

public:
	
};

#endif // !MODULE_UI
