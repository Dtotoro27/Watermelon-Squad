#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleWelcome.h"
#include "ModuleCongrats.h"
#include "ModuleMine.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"


ModuleCongrats::ModuleCongrats()
{
	// Background 
	congrats.x = 0;
	congrats.y = 0;
	congrats.w = 224;
	congrats.h = 320;


}

ModuleCongrats::~ModuleCongrats()
{}

// Load assets
bool ModuleCongrats::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	congratstexture = App->textures->Load("background_congrats.png");
	App->audio->LoadMusic("Audio/stageclear.ogg");
	return ret;
}

bool ModuleCongrats::CleanUp()
{
	App->textures->Unload(congratstexture);
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleCongrats::Update()
{

	// Draw everything --------------------------------------


	App->render->Blit(congratstexture, 0, -320 + SCREEN_HEIGHT, &congrats, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->welcome, 1);
		change = true;

	}



	return UPDATE_CONTINUE;
}