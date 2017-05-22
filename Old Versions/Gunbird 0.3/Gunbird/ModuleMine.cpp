#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleMine.h"
#include "ModuleAudio.h"
#include "ModuleSea.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

float mineworker_x = 190;

ModuleMine::ModuleMine()
{
	// Background 
	mine.x = 0;
	mine.y = 0;
	mine.w = 234;
	mine.h = 3535;


	mineworker.PushBack({ 59, 8, 11, 22 });
	mineworker.PushBack({ 83, 8, 11, 23 });
	mineworker.PushBack({ 107, 8, 13, 22 });
	mineworker.PushBack({ 83, 8, 11, 23 });
	mineworker.speed = 0.08f;



}

ModuleMine::~ModuleMine()
{}

// Load assets
bool ModuleMine::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	minetexture = App->textures->Load("background_mine.png");
	mineworkertexture = App->textures->Load("mineworker.png");
	App->player->Enable();
	App->audio->LoadMusic("Audio/mine.ogg");
	mineworker_x = 190;
	return ret;
}

bool ModuleMine::CleanUp()
{
	App->textures->Unload(minetexture);
	App->textures->Unload(mineworkertexture);
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleMine::Update()
{

	// Draw everything --------------------------------------


	App->render->Blit(minetexture, 0, -3535 + SCREEN_HEIGHT, &mine, 0.75f);

	App->render->Blit(mineworkertexture, mineworker_x, 15, &(mineworker.GetCurrentFrame()), 0.75f);

	App->render->camera.y += SCROLL_SPEED;


	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->sea, 1);
		change = true;
	}

	mineworker_x -= 0.25;




	return UPDATE_CONTINUE;
}