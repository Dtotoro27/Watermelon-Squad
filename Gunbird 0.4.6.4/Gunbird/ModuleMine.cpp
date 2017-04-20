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
#include "Enemy_Balloon.h"
#include "ModuleCongrats.h"

float mineworker_x = 190;

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
	
	pw_pos.x = 190;
	pw_pos.y = 100;
	
	minetexture = App->textures->Load("background_mine.png");
	minetexture2 = App->textures->Load("background_mine_2.png");
	mineworkertexture = App->textures->Load("mineworker.png");
	pw_texture = App->textures->Load("power_up.png");
	pw_hitbox = App->collision->AddCollider({ pw_pos.x, pw_pos.y, 21, 12 }, COLLIDER_POWER_UP, this);
	
	App->player->Enable();
	App->player->destroyed = false;
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	mine.x = 0;
	mine.y = 0;
	mine.w = 234;
	mine.h = 3535;


	mineworker.PushBack({ 59, 8, 11, 22 });
	mineworker.PushBack({ 83, 8, 11, 23 });
	mineworker.PushBack({ 107, 8, 13, 22 });
	mineworker.PushBack({ 83, 8, 11, 23 });
	mineworker.speed = 0.08f;

	pw_anim.PushBack({ 4, 32, 21, 10 });
	pw_anim.PushBack({ 54, 31, 21, 12 });
	pw_anim.PushBack({ 104, 31, 21, 12 });
	pw_anim.PushBack({ 54, 47, 21, 12 });
	pw_anim.PushBack({ 104, 47, 21, 12 });
	pw_anim.PushBack({ 29, 64, 21, 12 });
	pw_anim.PushBack({ 104, 64, 21, 12 });
	pw_anim.PushBack({ 30, 83, 21, 12 });
	pw_anim.speed = 0.1f;

	
	App->audio->LoadMusic("Audio/mine.ogg");
	mineworker_x = 59;

	


	//Enemy

	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, 70, 38);
	App->enemies->AddEnemy(ENEMY_TYPES::FLYINGMACHINE, 150, 38);
	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 50, 56);

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
	App->textures->Unload(minetexture2);
	App->textures->Unload(mineworkertexture);
	App->textures->Unload(pw_texture);
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleMine::Update()
{

	// Draw everything --------------------------------------


	App->render->Blit(minetexture, 0, -3535 + SCREEN_HEIGHT, &mine, 0.18f);

	App->render->Blit(minetexture2, 0, -3535 + SCREEN_HEIGHT, &mine, 0.22f);

	App->render->Blit(mineworkertexture, mineworker_x, 100, &(mineworker.GetCurrentFrame()), 0.22f);

	App->render->Blit(pw_texture, pw_pos.x, pw_pos.y, &(pw_anim.GetCurrentFrame()), 0.22f);

	App->render->camera.y += SCROLL_SPEED;




	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}



	mineworker_x -= 0.10;


	pw_pos.y += 0.9;
	pw_hitbox->SetPos(pw_pos.x, pw_pos.y);




	return UPDATE_CONTINUE;
}