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



ModuleMine::ModuleMine()
{
	// Background 

}

ModuleMine::~ModuleMine()
{}

// Load assets
bool ModuleMine::Start()
{
	LOG("Loading background assets");

	mineworkeractive.y = 0;

	minetexture = App->textures->Load("background_mine.png");
	mineanimationtexture = App->textures->Load("background_mine_animation.png");
	startplayer2texture = App->textures->Load("ui.png");
	minetexture2 = App->textures->Load("background_mine_2.png");
	mineworkertexture = App->textures->Load("mineworker.png");
	

	App->player->Enable();
	App->player->destroyed = false;
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	mine.x = 0;
	mine.y = 0;
	mine.w = 234;
	mine.h = 3535;


	mineworkerwalkleft.PushBack({ 59, 8, 11, 22 });
	mineworkerwalkleft.PushBack({ 83, 8, 11, 23 });
	mineworkerwalkleft.PushBack({ 107, 8, 13, 22 });
	mineworkerwalkleft.PushBack({ 83, 8, 11, 23 });
	mineworkerwalkleft.speed = 0.08f;

	mineworkerwalkright.PushBack({ 61, 45, 11, 22 });
	mineworkerwalkright.PushBack({ 83, 45, 11, 23 });
	mineworkerwalkright.PushBack({ 107, 45, 12, 22 });
	mineworkerwalkright.speed = 0.08f;

	mineanimation.PushBack({ 13,27,175,85 });
	mineanimation.PushBack({ 197,27,175,85 });
	mineanimation.PushBack({ 392,27,175,85 });
	mineanimation.PushBack({ 585,27,175,85 });
	mineanimation.PushBack({ 8,131,175,85 });
	mineanimation.PushBack({ 197,131,175,85 });
	mineanimation.PushBack({ 392,123,175,85 });
	mineanimation.PushBack({ 585,131,175,85 });
	mineanimation.speed = 0.05f;

	mineworkerstand.PushBack({ 2,8,13,22 });
	mineworkerstand.PushBack({ 21,8,14,23 });
	mineworkerstand.PushBack({ 38,8,16,22 });
	mineworkerstand.PushBack({ 7,79,15,22 });
	mineworkerstand.PushBack({ 27,79,15,23 });
	mineworkerstand.PushBack({53,80,15,22 });
	mineworkerstand.PushBack({ 1,46,16,22 });
	mineworkerstand.PushBack({ 20,45,14,23 });
	mineworkerstand.PushBack({ 40,45,13,22 });
	mineworkerstand.speed = 0.03f;

	startplayer2animation.PushBack({ 6, 5, 68, 15 });
	startplayer2animation.PushBack({6, 28,68, 13 });
	startplayer2animation.PushBack({ 0,0,0,0 });
	startplayer2animation.speed = 0.02;

	p1.PushBack({ 10, 68, 15, 12});
	p2.PushBack({ 30,67,16,12 });

	App->audio->LoadMusic("Audio/mine.ogg");
	mineworker_x = 59;




	//Enemy

	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, 51, 10);

	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 137, -176);
	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 167, -196);
	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 197, -176);

	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 0, -136);
	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 30, -156);
	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE2, 60, -136);


	App->enemies->AddEnemy(ENEMY_TYPES::POWER_UP, 30, 30);


	return true;
}

bool ModuleMine::CleanUp()
{

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->textures->Unload(minetexture);
	App->textures->Unload(startplayer2texture);
	App->textures->Unload(minetexture2);
	App->textures->Unload(mineworkertexture);
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleMine::Update()
{

	// -------------------------------------- Draw everything --------------------------------------


	//Background
	App->render->Blit(minetexture, 0, -3535 + SCREEN_HEIGHT, &mine, 0.18f);
	App->render->Blit(mineanimationtexture, 16, -796, &(mineanimation.GetCurrentFrame()), 0.18f);
	App->render->Blit(minetexture2, 0, -3535 + SCREEN_HEIGHT, &mine, 0.22f);
	

	//Mineworkers
	if (mineworkeractive.y < 2500) {
		App->render->Blit(mineworkertexture, mineworker_x, 100, &(mineworkerwalkleft.GetCurrentFrame()), 0.22f);
		App->render->Blit(mineworkertexture, 16, -439, &(mineworkerstand.GetCurrentFrame()), 0.22f);
		App->render->Blit(mineworkertexture, 137, -460, &(mineworkerstand.GetCurrentFrame()), 0.22f);
		mineworker_x -= 0.10;
	}
	else {
		App->render->Blit(mineworkertexture, mineworker_x2, -460, &(mineworkerwalkright.GetCurrentFrame()), 0.22f);
		App->render->Blit(mineworkertexture, mineworker_x3, -439, &(mineworkerwalkleft.GetCurrentFrame()), 0.22f);
		mineworker_x2 += 0.1;
		mineworker_x3 -= 0.1;
	}
	
	//UI
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) {
		player2 = true;
	}

	if (player2 == true) {
		App->render->Blit(startplayer2texture, 116, 6, &(p2.GetCurrentFrame()), 0);
	}
	else {
		App->render->Blit(startplayer2texture, 118, 4, &(startplayer2animation.GetCurrentFrame()), 0);
	}

	App->render->Blit(startplayer2texture, 5, 6, &(p1.GetCurrentFrame()), 0);

	
	if (App -> render -> camera.y <= 14313) {
		App -> render -> camera.y += SCROLL_SPEED;
	}

	else {
		change = false;
		App -> fade -> FadeToBlack(this, App -> congrats, 1);
		change = true;
	}




	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

			change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}


	mineworkeractive.y += 1;
	


	




	return UPDATE_CONTINUE;
}