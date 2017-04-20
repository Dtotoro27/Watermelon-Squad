#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleMine.h"
#include "ModuleCongrats.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"


ModuleSea::ModuleSea()
{
	// Background 
	sea.x = 0;
	sea.y = 0;
	sea.w = 234;
	sea.h = 3535;


}

ModuleSea::~ModuleSea()
{}

// Load assets
bool ModuleSea::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	seatexture = App->textures->Load("background_sea.png");
	App->audio->LoadMusic("Audio/sea.ogg");
	App->particles->Enable();
	App->collision->Enable();
	App->player->Enable();
	App->player->destroyed = false;
	return ret;
}

bool ModuleSea::CleanUp()
{
	LOG("Unloading stage");
	
	App->textures->Unload(seatexture);
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSea::Update()
{

	// Draw everything --------------------------------------


	App->render->Blit(seatexture, 0, -3535 + SCREEN_HEIGHT, &sea, 0.75f);

	App->render->camera.y += SCROLL_SPEED;


	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;

	}



	return UPDATE_CONTINUE;
}