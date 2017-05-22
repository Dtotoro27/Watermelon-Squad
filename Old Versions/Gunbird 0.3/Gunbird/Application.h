#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 12

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleMine;
class ModuleSea;
class ModuleWelcome;
class ModuleCongrats;
class ModulePlayer;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleParticles;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleMine* mine;
	ModuleSea* sea;
	ModuleWelcome* welcome;
	ModuleCongrats* congrats;
	ModuleAudio* audio;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__