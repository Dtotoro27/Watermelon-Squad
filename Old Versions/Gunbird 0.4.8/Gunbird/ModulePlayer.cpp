#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleMine.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "Enemy.h"
#include "PowerUp.h"

#include<stdio.h>

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;
	score = 0;

	camera_limits.y = 0;

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

	immortal.PushBack({ 14, 13, 19, 32 });
	immortal.PushBack({ 0,0,0,0 });
	immortal.speed = 0.1;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("assets/ash.png"); // arcade version
	playerhitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	font_score = App->fonts->Load("assets/numbers.png", "0123456789", 1);
	audio_shot = App->audio->LoadFX("assets/Audio/shoot_ash.wav");
	score = 0;
	time.x = 0;
	return ret;
}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->collision->EraseCollider(playerhitbox);
	App->fonts->UnLoad(font_score);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	char str[10];
	sprintf_s(str, "%i", score);
	App->fonts->BlitText(44, 7, font_score, str);

    float speed = 3.5f;
	position.y -= 1;
	camera_limits.y -= 1;

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &right;
		if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
			position.x += speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &left;
		if (position.x > 0) {
			position.x -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > camera_limits.y + ASH_HEIGHT + 35) {
			position.y -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y < camera_limits.y + SCREEN_HEIGHT) {
			position.y += speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (powerUps == 0) {
			App->particles->AddParticle(App->particles->laser, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
			App->audio->PlayFX(audio_shot);
			//App->audio->LoadFX("Audio/shoot_ash.wav");
		}
		if (powerUps == 1) {
			App->particles->AddParticle(App->particles->laser2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
			App->audio->PlayFX(audio_shot);
			//App->audio->LoadFX("Audio/shoot_ash.wav");
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN) {
		if (godmode == true) {
			godmode = false;
		}
		else if (godmode == false) {
			godmode = true;
		}
	}

	if (App->player2->IsEnabled()){}

	else {
		if (App->input->keyboard[SDL_SCANCODE_Q]) {
			App->player2->Enable();
			App->player2->position.x = SCREEN_WIDTH / 2 + 10;
			App->player2->position.y = position.y;
			App->player2->destroyed = false;
		}
	}



	playerhitbox->SetPos(position.x, position.y - ASH_HEIGHT);


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	sprintf_s(score_text, 10, "%7d", score);



	if (time.x > 150) {
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	else {
		App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
		time.x++;
	}

	return UPDATE_CONTINUE;
}

void  ModulePlayer::OnCollision(Collider *c1, Collider *c2) {


	if (c1 == playerhitbox && destroyed == false && App->fade->IsFading() == false)
	{

		if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {

			powerUps = 1;
 		}

		else {
			if (godmode == false) {
				App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
				App->textures->Unload(graphics);
				App->fade->FadeToBlack((Module*)App->mine, (Module*)App->congrats);
				destroyed = true;
			}
			else {}
		}
	}
}
