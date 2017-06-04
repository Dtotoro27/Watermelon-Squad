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

	bird_dead.PushBack({1645,33,187,107});

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

	App->collision->shipturret1 = false;
	App->collision->shipturret2 = false;
	App->collision->deadbird = false;
	App->collision->rwing = false;

	pause = false;
	boss_speed = 0.22f;
	boss_y = -640;
	boss_y2 = -1280;


	bosstexture = App->textures->Load("assets/boss_background.png");
	startplayer2texture = App->textures->Load("assets/ui.png");
	bossdead = App->textures->Load("assets/particles.png");

	App->audio->LoadMusic("assets/Audio/boss.ogg");

	collision= App->collision->AddCollider({ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT }, COLLIDER_ASH_BOMB, this);

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
	App->textures->Unload(bossdead);
	App->audio->UnloadMusic();
	App->boss->Disable();



	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleBoss::Update()
{
// PAUSE

	if (App->player->dead == false) {
		if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN || App->input->buttonStart == KEY_STATE::KEY_DOWN|| App->input->buttonStart2 == KEY_STATE::KEY_DOWN) {
			if (App->sea->pause == false) {
				App->sea->pause = true;
			}
			else if (App->sea->pause == true) {
				App->sea->pause = false;
			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RGUI] == KEY_STATE::KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_STATE::KEY_DOWN) {
		App->sea->pause = true;
	}


	if (App->sea->pause == true) {
		App->render->camera.y -= SCROLL_SPEED;
		App->player->position.y += 1;
		App->player2->position.y += 1;
		App->player->camera_limits.y += 1;
	}

	// -------------------------------------- Draw everything --------------------------------------
	App->render->Blit(bosstexture, -64, boss_y + SCREEN_HEIGHT, &(boss_animation.GetCurrentFrame()), boss_speed);
	App->render->Blit(bosstexture, -64, boss_y2 + SCREEN_HEIGHT, &(boss_animation.GetCurrentFrame()), boss_speed);



	//Background--------------------------

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
	if (App->input->keyboard[SDL_SCANCODE_F8] == KEY_STATE::KEY_DOWN) {
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}

	if (spawnbird == true) {
		spawnbird = false;
			App->enemies->AddEnemy(ENEMY_TYPES::BIRDBODY, -18, App->player->camera_limits.y + 35);
			App->enemies->AddEnemy(ENEMY_TYPES::LEFTWINGBIRD, -26, App->player->camera_limits.y + 87);
			App->enemies->AddEnemy(ENEMY_TYPES::RIGHTWINGBIRD, 115, App->player->camera_limits.y + 87);

		
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
		if (timer == 40) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 20, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 50, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 150, App->player->camera_limits.y + 150, 0, 0, COLLIDER_NONE);
		}
		if (timer == 50) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 120, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 150, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 200, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 150, App->player->camera_limits.y + 250, 0, 0, COLLIDER_NONE);

		}
		if (timer == 60) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 20, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 50, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 10, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->explosion, 150, App->player->camera_limits.y + 150, 0, 0, COLLIDER_NONE);

		}
		if (timer == 70) {
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
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 170, -550);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 10, -478);
	}
	if (App->render->camera.y == 1400)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 180, -820);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE3, 20, -880);
	}

	if (App->render->camera.y == 1900)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 190, -1200);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 190, -1080);
	}

	if (App->render->camera.y == 2400)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE4, 175, -1350);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE3, 7, -1280);
	}

	if (App->render->camera.y == 2800)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 185, -1450);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE3, 20, -1480);
	}

	if (App->render->camera.y == 3200)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 185, -1650);
		App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 10, -1610);
	}


	if (App->collision->deadbird == true) {

		collision->SetPos(0, App->player->camera_limits.y);

		if (timer2 > 250) {
			App->player2->position.y -= 3;
			App->player->position.y -= 3;
			App->player->camera_limits.y -= 3;
		}
		if (timer2 == 0) {
			App->particles->AddParticle(App->particles->bird_explosion, 3, App->player->camera_limits.y+38, 0, -1, COLLIDER_NONE);

		}
		if (timer2 == 30) {
			App->particles->AddParticle(App->particles->explosion, 20, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);

		}
		if (timer2 == 40) {
			App->particles->AddParticle(App->particles->explosion, 50, App->player->camera_limits.y + 120, 0, 0, COLLIDER_NONE);

		}
		if (timer2 == 50) {
			App->particles->AddParticle(App->particles->explosion, 70, App->player->camera_limits.y + 100, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->smoke, 60, App->player->camera_limits.y + 140, 0, -0.8f, COLLIDER_NONE);
		}
		if (timer2 == 60) {
			App->particles->AddParticle(App->particles->explosion, 20, App->player->camera_limits.y + 120, 0, 0, COLLIDER_NONE);
			App->particles->AddParticle(App->particles->smoke,20, App->player->camera_limits.y + 120, 0, -0.8f, COLLIDER_NONE);

		}
		if (timer2 == 70) {
			App->particles->AddParticle(App->particles->smoke, 50, App->player->camera_limits.y + 140, 0, -0.8f, COLLIDER_NONE);
		}
		if (timer2 == 80) {
			App->particles->AddParticle(App->particles->smoke,126, App->player->camera_limits.y + 150, 0, -0.8f, COLLIDER_NONE);
		}
		if (timer2 == 90) {
			App->particles->AddParticle(App->particles->smoke, 105, App->player->camera_limits.y + 100, 0, -0.8f, COLLIDER_NONE);
		}
		if (timer2 ==100) {
			App->particles->AddParticle(App->particles->smoke,20, App->player->camera_limits.y + 140, 0, -0.8f, COLLIDER_NONE);
		}
		if (timer2 > 0) {
			App->render->Blit(bossdead, 20, 100, &(bird_dead.GetCurrentFrame()), 0);
		}
		timer2++;
		if (timer2 == 350) {
			change = false;
			App->fade->FadeToBlack(this, App->congrats, 1);
			change = true;
			timer2 = 0;
			App->collision->deadbird = false;
		}
	}
	

	return UPDATE_CONTINUE;
}