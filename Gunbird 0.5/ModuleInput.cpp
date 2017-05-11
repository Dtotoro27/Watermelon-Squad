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
		if (buttonA == KEY_IDLE)
			buttonA = KEY_DOWN;
		else
			buttonA = KEY_REPEAT;
	}
	else
	{
		if (buttonA == KEY_REPEAT || buttonA == KEY_DOWN)
			buttonA = KEY_UP;
		else
			buttonA = KEY_IDLE;
	}

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) == 1) {
		if (buttonB == KEY_IDLE)
			buttonB = KEY_DOWN;
		else
			buttonB = KEY_REPEAT;
	}
	else
	{
		if (buttonB == KEY_REPEAT || buttonB == KEY_DOWN)
			buttonB = KEY_UP;
		else
			buttonB = KEY_IDLE;
	}
	
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) == 1) {
		if (dpadUp == KEY_IDLE)
			dpadUp = KEY_DOWN;
		else
			dpadUp = KEY_REPEAT;
	}
	else
	{
		if (dpadUp == KEY_REPEAT || dpadUp == KEY_DOWN)
			dpadUp = KEY_UP;
		else
			dpadUp = KEY_IDLE;
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 1) {
		if (dpadDown == KEY_IDLE)
			dpadDown = KEY_DOWN;
		else
			dpadDown = KEY_REPEAT;
	}
	else
	{
		if (dpadDown == KEY_REPEAT || dpadDown == KEY_DOWN)
			dpadDown = KEY_UP;
		else
			dpadDown = KEY_IDLE;
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 1) {
		if (dpadLeft == KEY_IDLE)
			dpadLeft = KEY_DOWN;
		else
			dpadLeft = KEY_REPEAT;
	}
	else
	{
		if (dpadLeft == KEY_REPEAT || dpadLeft == KEY_DOWN)
			dpadLeft = KEY_UP;
		else
			dpadLeft = KEY_IDLE;
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 1) {
		if (dpadRight == KEY_IDLE)
			dpadRight = KEY_DOWN;
		else
			dpadRight = KEY_REPEAT;
	}
	else
	{
		if (dpadRight == KEY_REPEAT || dpadRight == KEY_DOWN)
			dpadRight = KEY_UP;
		else
			dpadRight = KEY_IDLE;
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