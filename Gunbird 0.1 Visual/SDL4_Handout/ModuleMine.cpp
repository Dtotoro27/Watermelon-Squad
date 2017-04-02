#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleMine.h"
#include "ModuleSea.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"



ModuleMine::ModuleMine()
{
	// Background 
	mine.x = 0;
	mine.y = 0;
	mine.w = 234;
	mine.h = 3535;


}

ModuleMine::~ModuleMine()
{}

// Load assets
bool ModuleMine::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	minetexture = App->textures->Load("background_mine.png");
	App->audio->LoadMusic("Audio/mine.ogg");
	App->player->Enable();
	return ret;
}

bool ModuleMine::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleMine::Update()
{

	// Draw everything --------------------------------------
	
	
	App->render->Blit(minetexture, 0, -3535 + SCREEN_HEIGHT, &mine, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->sea, 1);
		change = true;

	}




	return UPDATE_CONTINUE;
}