#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	for (int i = 0; i < SDL_NumJoysticks(); i++) {
		if (SDL_IsGameController(i)) {
			controller = SDL_GameControllerOpen(i);
			joy = SDL_GameControllerGetJoystick(controller);
			LOG("Index \'%i\' is a compatible controller, named \'%s\'\n", i, SDL_GameControllerNameForIndex(i));
			break;
		}
		else {
			LOG("Index \'%i\' is not a compatible controller.\n", i);
		}
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}
	
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) == 1) {
		if (buttonA == false) {
			buttonA = true;
		}
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) == 1) {
		if (buttonB == false) {
			buttonB = true;
		}
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) == 1) {
		if (buttonX == false) {
			buttonX = true;
		}
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) == 1) {
		if (buttonY == false) {
			buttonY = true;
		}
	}
	
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) == 1) {
		if (dpadUp == false) {
			dpadUp = true;
		}
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 1) {
		if (dpadDown == false) {
			dpadDown = true;
		}
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 1) {
		if (dpadLeft == false) {
			dpadLeft = true;
		}
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 1) {
		if (dpadRight == false) {
			dpadRight = true;
		}
	}

	

	if (keyboard[SDL_SCANCODE_ESCAPE]) {
		App->CleanUp();
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	if (controller != NULL) {
		SDL_GameControllerClose(controller);
	}
	controller = nullptr;
	return true;
}