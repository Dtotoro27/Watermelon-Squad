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

	boss_animation.PushBack({ 0, 0, 288, 640 });
	boss_animation.PushBack({ 288, 0, 288, 640 });
	boss_animation.PushBack({ 576, 0, 288, 640 });
	boss_animation.PushBack({ 864, 0, 288, 640 });
	boss_animation.PushBack({ 1152, 0, 288, 640 });
	boss_animation.PushBack({ 864, 0, 288, 640 });
	boss_animation.PushBack({ 576, 0, 288, 640 });
	boss_animation.PushBack({ 288, 0, 288, 640 });
	boss_animation.speed = 0.1;


	boss_animation2.PushBack({ 0, 0, 288, 640 });
	boss_animation2.PushBack({ 288, 0, 288, 640 });
	boss_animation2.PushBack({ 576, 0, 288, 640 });
	boss_animation2.PushBack({ 864, 0, 288, 640 });
	boss_animation2.PushBack({ 1152, 0, 288, 640 });
	boss_animation2.PushBack({ 864, 0, 288, 640 });
	boss_animation2.PushBack({ 576, 0, 288, 640 });
	boss_animation2.PushBack({ 288, 0, 288, 640 });
	boss_animation2.speed = 0.1;



}

ModuleBoss::~ModuleBoss()
{}

// Load assets
bool ModuleBoss::Start()
{

	LOG("Loading background assets");

	pause = false;
	boss_speed = 0.22f;
	boss_y = -640;
	boss_y2 = -1280;


	bosstexture = App->textures->Load("assets/boss_background.png");
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
	App->render->Blit(bosstexture, -64, boss_y + SCREEN_HEIGHT, &(boss_animation.GetCurrentFrame()), boss_speed);
	App->render->Blit(bosstexture, -64, boss_y2 + SCREEN_HEIGHT, &(boss_animation.GetCurrentFrame()), boss_speed);

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

	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN) {
		App->enemies->AddEnemy(ENEMY_TYPES::BIRDBODY, App->player->position.x, App->player->position.y);
		App->enemies->AddEnemy(ENEMY_TYPES::LEFTWINGBIRD, SCREEN_WIDTH / 2 - 52, 102);
		App->enemies->AddEnemy(ENEMY_TYPES::RIGHTWINGBIRD, SCREEN_WIDTH / 2 + 89, 102);
	}

	if (pause == true) {
		App->render->camera.y -= SCROLL_SPEED;
		App->player->position.y += 1;
		App->player->camera_limits.y += 1;
	}

	//Background--------------------------

	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN) {
		LOG("%i", App->render->camera.y);
	}

	if (App->render->camera.y == 5800)
	{
		boss_y -= 1280;
	}
	if (App->render->camera.y == 11600)
	{
		boss_y2 -= 1280;
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
		polla = App->render->camera.y;
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}

	if (spawnbird == true) {
		spawnbird = false;
			App->enemies->AddEnemy(ENEMY_TYPES::BIRDBODY, -18, App->player->camera_limits.y + 35);
			App->enemies->AddEnemy(ENEMY_TYPES::LEFTWINGBIRD, -26, App->player->camera_limits.y + 87);
			App->enemies->AddEnemy(ENEMY_TYPES::RIGHTWINGBIRD, 116, App->player->camera_limits.y + 87);

		
	}

	if (spawnship == true) {
		spawnship = false;
		//Enemy
		App->enemies->AddEnemy(ENEMY_TYPES::SHIP, 10, App->player->camera_limits.y -407);

		//SECOND STATE

		App->enemies->AddEnemy(ENEMY_TYPES::SHIPVERTICALCANON2, 67, App->player->camera_limits.y -279);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPVERTICALCANON3, 113, App->player->camera_limits.y -280);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPVERTICALCANONLITTLE, 91, App->player->camera_limits.y -276);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPBACKTURRET, 37, App->player->camera_limits.y -438);


		//FIRST STATE

		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 16, App->player->camera_limits.y -288);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 146, App->player->camera_limits.y -288);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 9, App->player->camera_limits.y -177);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 152, App->player->camera_limits.y -177);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 124, App->player->camera_limits.y -151);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 38, App->player->camera_limits.y -151);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 50, App->player->camera_limits.y - 73);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPTURRET, 112, App->player->camera_limits.y -73);

		App->enemies->AddEnemy(ENEMY_TYPES::SHIPBIGMIDDLETURRET, 28, App->player->camera_limits.y -276);

		App->enemies->AddEnemy(ENEMY_TYPES::SHIPVERTICALCANON, 66, App->player->camera_limits.y -192);
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPVERTICALCANON, 116, App->player->camera_limits.y -192);

		App->enemies->AddEnemy(ENEMY_TYPES::SHIPHORIZONTALCANON, 86, App->player->camera_limits.y -144);

		
	}

	

	if (App->collision->shipturret2 == true) {
		if (timer == 0) {
			App->particles->AddParticle(App->particles->explosion, 50 , App->player->camera_limits.y + 20, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 50, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 150, App->player->camera_limits.y + 150, 0, 0, COLLIDER_NONE);

			App->particles->AddParticle(App->particles->explosion, 0, App->player->camera_limits.y + 20, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 30, App->player->camera_limits.y + 75, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 30, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 50, 0, 0, COLLIDER_NONE);
		}
		if (timer == 10) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 120, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 150, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 200, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 150, App->player->camera_limits.y + 250, 0, 0, COLLIDER_NONE);

		}
		if (timer == 20) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 20, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 50, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 150, App->player->camera_limits.y + 150, 0, 0, COLLIDER_NONE);

		}
		if (timer == 30) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 70, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 90, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 80, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);
		}
		timer++;
	}


	//ENEMIES--------------------------
	
	if (App->render->camera.y == 900)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 150, -550);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 30, -478);
	}
	if (App->render->camera.y == 1400)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 180, -820);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE3, 20, -880);
	}

	if (App->render->camera.y == 1900)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 140, -1200);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 140, -1080);
	}

	if (App->render->camera.y == 2400)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 175, -1350);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE3, 40, -1280);
	}

	if (App->render->camera.y == 2800)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 175, -1450);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE3, 40, -1480);
	}

	if (App->render->camera.y == 3200)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 155, -1650);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 20, -1610);
	}
	

	return UPDATE_CONTINUE;
}