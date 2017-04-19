#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer2.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"


ModulePlayer2::ModulePlayer2()
{
	position.x = 100;
	position.y = 220;


	// idle animation
	idle.PushBack({ 14, 13, 19, 32 });
	idle.PushBack({ 43, 13, 19, 32 });
	idle.speed = 0.1f;

	// move left animation 
	left.PushBack({ 16, 55, 17, 32 });
	left.PushBack({ 43, 55, 17, 32 });
	left.speed = 0.1f;

	// move right animation
	right.PushBack({ 63, 97, 17, 32 });
	right.PushBack({ 90, 97, 17, 32 });
	right.speed = 0.1f;

}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ash.png"); // arcade version
	player2hitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	return ret;
}

bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	int speed = 5;
	position.y -= 1;
	camera_limitsp2 = App->player->camera_limits;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &right;
		if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
			position.x += speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &left;
		if (position.x > 0) {
			position.x -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > camera_limitsp2.y + ASH_HEIGHT) {
			position.y -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y < camera_limitsp2.y + SCREEN_HEIGHT) {
			position.y += speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 4, position.y - 50, COLLIDER_PLAYER_SHOT);
		App->audio->LoadFX("Audio/shoot_ash.wav");
	}

	if (App->input->keyboard[SDL_SCANCODE_F2]) {
		if (godmode == true) {
			godmode = false;
		}
		else if (godmode == false) {
			godmode = true;
		}
	}



	player2hitbox->SetPos(position.x, position.y - ASH_HEIGHT);

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void  ModulePlayer2::OnCollision(Collider *c1, Collider *c2) {


	if (c1 == player2hitbox && destroyed == false && App->fade->IsFading() == false && godmode == false)
	{

		App->fade->FadeToBlack((Module*)App->mine, (Module*)App->congrats);

		App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE, 150);


		destroyed = true;


	}

}

