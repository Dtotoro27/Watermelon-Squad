#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleWelcome.h"
#include "ModuleMine.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"



ModuleWelcome::ModuleWelcome()
{
	// Background 
	welcome.x = 0;
	welcome.y = 0;
	welcome.w = 224;
	welcome.h = 320;


}

ModuleWelcome::~ModuleWelcome()
{}

// Load assets
bool ModuleWelcome::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	welcometexture = App->textures->Load("background_welcome.png");
	App->collision->Enable();
	App->audio->LoadMusic("Audio/characterselection.ogg");
	return ret;
}

bool ModuleWelcome::CleanUp()
{	
	App->textures->Unload(welcometexture);
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleWelcome::Update()
{

	// Draw everything --------------------------------------


	App->render->Blit(welcometexture, 0, -320 + SCREEN_HEIGHT, &welcome, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->mine, 1);
		change = true;

	}



	return UPDATE_CONTINUE;
}