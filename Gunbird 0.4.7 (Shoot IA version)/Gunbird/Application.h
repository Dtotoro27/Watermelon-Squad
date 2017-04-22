#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleMine;
class ModuleWelcome;
class ModuleCongrats;
class ModulePlayer;
class ModulePlayer2;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleParticles;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
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
	ModuleWelcome* welcome;
	ModuleCongrats* congrats;
	ModuleAudio* audio;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;

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