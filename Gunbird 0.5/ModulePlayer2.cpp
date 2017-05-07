#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer2.h"
#include "ModulePlayer.h"
#include "ModuleMine.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"

#include<stdio.h>


ModulePlayer2::ModulePlayer2()
{
	position.x = 100;
	position.y = 220;
	score = 0;


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
	graphics = App->textures->Load("assets/characters/ash.png"); // arcade version
	player2hitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	font_score = App->fonts->Load("assets/numbers.png", "0123456789", 1);
	audio_shot = App->audio->LoadFX("assets/Audio/shoot_ash.wav");
	score = 0;
	return ret;
}

bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	App->fonts->UnLoad(font_score);

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	char str[10];
	sprintf_s(str, "%i", score);
	App->fonts->BlitText(180, 7, font_score, str);

	int speed = 2;
	position.y -= 1;
	camera_limitsp2 = App->player->camera_limits;

	if (App->mine->pause == false) {

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
			if (position.y > camera_limitsp2.y + ASH_HEIGHT + 35) {
				position.y -= speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			if (position.y < camera_limitsp2.y + SCREEN_HEIGHT) {
				position.y += speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN || 0 < delay)
		{
			shooting = true;
			if (powerUps == 0) {
				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					shooting = false;
					delay = 0;
				}
				if (shooting == true) {
					delay++;
				}
				//App->audio->LoadFX("Audio/shoot_ash.wav");
			}
			if (powerUps == 1) {
				//App->audio->LoadFX("Audio/shoot_ash.wav");

				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					shooting = false;
					delay = 0;
				}
				if (shooting == true) {
					delay++;
				}
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_F3]) {
			if (godmode2 == true) {
				godmode2 = false;
			}
			else if (godmode2 == false) {
				godmode2 = true;
			}
		}
	}


	player2hitbox->SetPos(position.x, position.y - ASH_HEIGHT);

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	sprintf_s(score_text, 10, "%7d", score);

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void  ModulePlayer2::OnCollision(Collider *c1, Collider *c2) {


	if (c1 == player2hitbox && destroyed == false && App->fade->IsFading() == false)
	{

		if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {

			powerUps = 1;
		}

		else {
			if (godmode2 == false) {

				App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150); 
				App->textures->Unload(graphics);
				App->fade->FadeToBlack((Module*)App->mine, (Module*)App->congrats);


				destroyed = true;
			}
			else {}
		}
	}
}



