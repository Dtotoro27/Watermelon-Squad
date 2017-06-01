#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class ModuleWindow;
class ModuleRender;
class ModuleInput;
class ModuleTextures;
class ModuleFonts;
class ModuleWelcome;
class ModuleCharacterSelect;
class ModuleSea;
class ModulePlayer;
class ModulePlayer2;
class ModuleEnemies;
class ModuleCongrats;
class ModuleParticles;
class ModuleUI;
class ModuleCollision;
class ModuleAudio;
class ModuleFadeToBlack;


class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleFonts* fonts;
	ModuleWelcome* welcome;
	ModuleCharacterSelect* characterselect;
	ModuleSea* sea;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleEnemies* enemies;
	ModuleCongrats* congrats;
	ModuleParticles* particles;
	ModuleUI* ui;
	ModuleCollision* collision;
	ModuleAudio* audio;	
	ModuleFadeToBlack* fade;
	
	

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