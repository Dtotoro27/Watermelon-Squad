#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_gamecontroller.h"
#include "SDL\include\SDL_scancode.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 100



enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};


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
	SDL_GameController *controller = nullptr;
	SDL_Joystick *joy = nullptr;
	bool buttonA = false;
	bool buttonB = false;
	bool buttonX = false;
	bool buttonY = false;
	bool dpadUp = false;
	bool dpadDown = false;
	bool dpadLeft = false;
	bool dpadRight = false;
};

#endif // __ModuleInput_H__