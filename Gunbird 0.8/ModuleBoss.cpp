#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleWelcome.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"
#include "ModuleSea.h"
#include "ModuleBoss.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleCongrats.h"
#include "ModuleCharacterSelect.h"
#include "ModuleUI.h"


ModuleBoss::ModuleBoss()
{
	// Background 

	boss_animation.PushBack({ 0, 0, 288, 2399 });
	boss_animation.PushBack({ 288, 0, 288, 2399 });
	boss_animation.PushBack({ 576, 0, 288, 2399 });
	boss_animation.PushBack({ 864, 0, 288, 2399 });
	boss_animation.PushBack({ 1152, 0, 288, 2399 });
	boss_animation.PushBack({ 864, 0, 288, 2399 });
	boss_animation.PushBack({ 576, 0, 288, 2399 });
	boss_animation.PushBack({ 288, 0, 288, 2399 });
	boss_animation.speed = 0.1;


}

ModuleBoss::~ModuleBoss()
{}

// Load assets
bool ModuleBoss::Start()
{

	LOG("Loading background assets");

	pause = false;
	boss_speed = 0.22f;
	boss_x = -64;


	bosstexture = App->textures->Load("assets/background_sea_1.png");
	startplayer2texture = App->textures->Load("assets/ui.png");

	App->audio->LoadMusic("assets/Audio/boss.ogg");



	App->ui->destroyed = false;
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->player->Enable();

	if (App->characterselect->coop == true) {
		App->player2->Enable();
	}

	App->ui->Enable();




	//Enemy


	




	return true;
}

bool ModuleBoss::CleanUp()
{

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->ui->Disable();
	App->textures->Unload(bosstexture);
	App->textures->Unload(startplayer2texture);
	App->audio->UnloadMusic();
	App->boss->Disable();



	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleBoss::Update()
{

	// -------------------------------------- Draw everything --------------------------------------
	App->render->Blit(bosstexture, boss_x, -2372 + SCREEN_HEIGHT, &(boss_animation.GetCurrentFrame()), boss_speed);

	if (App->player->dead == false) {
		if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN || App->input->buttonStart == KEY_STATE::KEY_DOWN) {
			if (pause == false) {
				pause = true;
			}
			else if (pause == true) {
				pause = false;
			}
		}
	}
	if (pause == true) {
		App->render->camera.y -= SCROLL_SPEED;
		App->player->position.y += 1;
		App->player->camera_limits.y += 1;
	}

	//Background--------------------------
	


	if (delay > 5200) {
		if (boss_x < 0) {
			boss_x += 0.4;
		}

	}
	else {
		delay++;
	}


	//UI--------------------------


	if (App->render->camera.y <= 10000000) {
		App->render->camera.y += SCROLL_SPEED;
	}

	else {
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;

	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN) {
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}

	//ENEMIES--------------------------


	return UPDATE_CONTINUE;
}