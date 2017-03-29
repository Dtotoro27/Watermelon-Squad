#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleMine.h"
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
	App->player->Enable();
	return ret;
}

bool ModuleSea::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleSea::Update()
{

	// Draw everything --------------------------------------


	App->render->Blit(seatexture, 0, -3535 + SCREEN_HEIGHT, &sea, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->mine, 1);
		change = true;

	}



	return UPDATE_CONTINUE;
}