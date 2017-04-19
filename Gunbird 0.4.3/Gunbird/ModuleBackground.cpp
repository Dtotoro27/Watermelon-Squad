#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// Background 
	background.x = 0;
	background.y = 0;
	background.w = 234;
	background.h = 3535;


}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	backgroundtexture = App->textures->Load("background_mine.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{

	// Draw everything --------------------------------------
	
	
	App->render->Blit(backgroundtexture, 0, -3535 + SCREEN_HEIGHT, &background, 0.75f);






	return UPDATE_CONTINUE;
}