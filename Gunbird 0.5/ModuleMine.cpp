#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"
#include "ModuleMine.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleCongrats.h"
#include "ModuleCharacterSelect.h"



ModuleMine::ModuleMine()
{
	// Background 

	sea_animation.PushBack({ 0, 0, 288, 2399 });
	sea_animation.PushBack({ 288, 0, 288, 2399 });
	sea_animation.PushBack({ 576, 0, 288, 2399 });
	sea_animation.PushBack({ 864, 0, 288, 2399 });
	sea_animation.PushBack({ 1152, 0, 288, 2399 });
	sea_animation.PushBack({ 864, 0, 288, 2399 });
	sea_animation.PushBack({ 576, 0, 288, 2399 });
	sea_animation.PushBack({ 288, 0, 288, 2399 });
	sea_animation.speed = 0.1;

	rock1.PushBack({0,0,46,175});
	rock1.PushBack({ 46,0,46,175 });
	rock1.PushBack({ 92,0,46,175 });
	rock1.PushBack({ 46,0,46,175 });
	rock1.speed = 0.06;

	rock2.PushBack({0,187,68,155});
	rock2.PushBack({ 68,187,68,155 });
	rock2.PushBack({ 137,187,68,155 });
	rock2.PushBack({ 206,187,68,155 });
	rock2.speed = 0.06;

	p1.PushBack({ 10, 68, 15, 12 });
	p2.PushBack({ 30,67,16,12 });

	startplayer2animation.PushBack({ 6, 5, 68, 15 });
	startplayer2animation.PushBack({ 6, 28,68, 13 });
	startplayer2animation.PushBack({ 0,0,0,0 });
	startplayer2animation.speed = 0.02;

	bomb_indicator.PushBack({ 59,67,12,15 });

}

ModuleMine::~ModuleMine()
{}

// Load assets
bool ModuleMine::Start()
{
	LOG("Loading background assets");

	App->player2->score = 0;
	pause = false;
	sea_speed = 0.22f;
	sea_x = -64;


	seatexture = App->textures->Load("assets/background_sea_1.png");
	rocktexture = App->textures->Load("assets/background_sea_2.png");
	startplayer2texture = App->textures->Load("assets/ui.png");

	//App->audio->LoadMusic(music_level1);


	App->player->Enable();
	if (App->characterselect->coop == true) {
		App->player2->Enable();
		player2 = true;
	}
	App->player->destroyed = false;
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	



	//Enemy

	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, 51, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::POWER_UP, 150, 10);
	

	

	return true;
}

bool ModuleMine::CleanUp()
{

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->textures->Unload(seatexture);	
	App->textures->Unload(rocktexture);
	App->textures->Unload(startplayer2texture);
	//App->audio->UnLoadMusic(music_level1);
	App->mine->Disable();
	
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleMine::Update()
{

	// -------------------------------------- Draw everything --------------------------------------


	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN || App->input->buttonStart == KEY_STATE::KEY_DOWN) {
		if (pause == false) {
			pause = true;
		}
		else if (pause == true) {
			pause = false;
		}
	}

	if (pause == true) {
		App->render->camera.y -= SCROLL_SPEED;
		App->player->position.y += 1;
		App->player->camera_limits.y += 1;
	}

	//Background--------------------------
	App->render->Blit(seatexture, sea_x, -2372 + SCREEN_HEIGHT, &(sea_animation.GetCurrentFrame()), sea_speed);
	App->render->Blit(rocktexture, 0, 44, &(rock1.GetCurrentFrame()), sea_speed);
	App->render->Blit(rocktexture, 156, 163, &(rock2.GetCurrentFrame()), sea_speed);

	if (delay > 5200) {
		if (sea_x < 0) {
			sea_x += 0.4;
		}
		
	}
	else {
		delay++;
	}



	//UI--------------------------

	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) {
		player2 = true;
	}

	if (player2 == true) {
		App->render->Blit(startplayer2texture, 116, 6, &(p2.GetCurrentFrame()), 0);
	}
	else {
		App->render->Blit(startplayer2texture, 118, 4, &(startplayer2animation.GetCurrentFrame()), 0);
	}

	if (App->player->max_bomb == 1) {
		App->render->Blit(startplayer2texture, 6, 300, &(bomb_indicator.GetCurrentFrame()),0);
	}
	if (App->player->max_bomb == 2) {
		App->render->Blit(startplayer2texture, 6, 300, &(bomb_indicator.GetCurrentFrame()),0);
		App->render->Blit(startplayer2texture, 22, 300, &(bomb_indicator.GetCurrentFrame()), 0);
	}

	App->render->Blit(startplayer2texture, 5, 6, &(p1.GetCurrentFrame()), 0);


	if (App->render->camera.y <= 100000) {
		App->render->camera.y += SCROLL_SPEED;
	}

	else {
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;		

	}
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN) {
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}

	//ENEMIES--------------------------
	
	if (App->render->camera.y == 1200) {
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 127, -650);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 157, -670);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 187, -650);

		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 1, -630);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 30, -650);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 60, -630);

	}

	if (App->render->camera.y == 2850) {
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 1, -1502);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 30, -1522);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 60, -1502);

		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 127, -1462);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 157, -1482);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 187, -1462);
	}


	if (App->render->camera.y == 4120) {
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 127, -2114);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 157, -2134);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 187, -2114);

		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 1, -2094);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 30, -2114);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 60, -2094);
	}

	if (App->render->camera.y == 5500) {
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 1, -2774);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 30, -2794);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 60, -2774);

		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 127, -2774);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 157, -2794);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 187, -2774);
	}

	if (App->render->camera.y == 9100) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 90, -4554);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 60, -4574);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 30, -4594);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 1, -4614);

		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 102, -4554);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 132, -4574);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 162, -4594);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 192, -4614);

	}








	return UPDATE_CONTINUE;
}