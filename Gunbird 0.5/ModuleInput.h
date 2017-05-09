#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_gamecontroller.h"
#include "SDL\include\SDL_scancode.h"

#define MAX_KEYS 300


enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};
/*
enum GC_STATE
{
	GC_IDLE = 0,
	GC_A,
	GC_B,
	GC_X,
	GC_Y
};
*/
class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	int state;
	int dpad_state;
	int joy_state;
	SDL_GameController *controller = nullptr;
	SDL_Joystick *joy = nullptr;
};

#endif // __ModuleInput_H__