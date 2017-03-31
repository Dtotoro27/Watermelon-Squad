#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleWelcomePage.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"

ModuleWelcomePage::ModuleWelcomePage()
{}

ModuleWelcomePage::~ModuleWelcomePage()
{}

// Load assets
bool ModuleWelcomePage::Start()
{
	LOG("Loading space scene");

	welcome = App->textures->Load("rtype/intro.png");

	return true;
}

// UnLoad assets
bool ModuleWelcomePage::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(welcome);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleWelcomePage::Update()
{

	// Draw everything --------------------------------------
	App->render->Blit(welcome, 0, 0, NULL);
	if (App->input->keyboard[SDL_SCANCODE_SPACE] && change) {
		change = false;
		App->fade->FadeToBlack(this, App->scene_space, 1);
		change = true;
	}

	return UPDATE_CONTINUE;
}