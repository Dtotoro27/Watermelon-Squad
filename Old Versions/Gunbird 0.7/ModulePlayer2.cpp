#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleCharacterSelect.h"
#include "ModuleSea.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "Enemy.h"
#include "ModuleUI.h"
#include "PowerUp.h"


#include<stdio.h>

ModulePlayer2::ModulePlayer2()
{
	position.x = 100;
	position.y = 220;


	camera_limits2.y = 0;

	// idle animation
	idle.PushBack({ 0, 0, 31, 32 });
	idle.PushBack({ 31, 0, 31, 32 });
	idle.speed = 0.1f;


	// move left animation 
	left.PushBack({ 62, 0, 21, 32 });
	left.PushBack({ 83, 0, 21, 32 });
	left.speed = 0.1f;

	// move right animation
	right.PushBack({ 104, 0, 21, 32 });
	right.PushBack({ 125, 0, 21, 32 });
	right.speed = 0.1f;

	immortal.PushBack({ 0, 0, 31, 32 });
	immortal.PushBack({ 31, 0, 31, 32 });
	immortal.PushBack({ 0,0,0,0 });
	immortal.speed = 0.1;

	ash_bomb_animation.PushBack({ 0,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 256,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,0,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 0,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 256,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 0,256,254,254 });
	ash_bomb_animation.PushBack({ 256,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 0,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 256,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 0,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 256,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,256,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 256,513,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,513,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,513,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,513,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,513,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,513,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 0,769,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 256,769,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 512,769,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 768,769,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1024,769,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1280,769,254,254 });
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.PushBack({ 1536,769,254,254 });
	ash_bomb_animation.speed = 0.7f;

	valnus_bomb_animation.PushBack({ 1,1,580,576 });
	valnus_bomb_animation.PushBack({ 1,1,580,576 });
	valnus_bomb_animation.PushBack({ 582,1,580,576 });
	valnus_bomb_animation.PushBack({ 582,1,580,576 });
	valnus_bomb_animation.PushBack({ 1163,1,580,576 });
	valnus_bomb_animation.PushBack({ 1163,1,580,576 });
	valnus_bomb_animation.PushBack({ 1744,1,580,576 });
	valnus_bomb_animation.PushBack({ 1744,1,580,576 });

	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });

	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });

	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });

	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });

	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });

	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2325,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });

	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 2906,1,580,576 });
	valnus_bomb_animation.PushBack({ 1,578,580,576 });
	valnus_bomb_animation.PushBack({ 1,578,580,576 });
	valnus_bomb_animation.PushBack({ 582,578,580,576 });
	valnus_bomb_animation.PushBack({ 582,578,580,576 });
	valnus_bomb_animation.PushBack({ 1163,578,580,576 });
	valnus_bomb_animation.PushBack({ 1163,578,580,576 });
	valnus_bomb_animation.PushBack({ 1744,578,580,576 });
	valnus_bomb_animation.PushBack({ 1744,578,580,576 });
	valnus_bomb_animation.speed = 0.4;

	valnus_bomb.PushBack({ 2331,638,43,39 });
	valnus_bomb.PushBack({ 2376,638,43,39 });
	valnus_bomb.PushBack({ 2421,638,43,39 });
	valnus_bomb.PushBack({ 2464,638,43,39 });
	valnus_bomb.speed = 0.1f;

	bomb_throw.PushBack({ 1868,428,10,14 });
	bomb_throw.PushBack({ 1881,428,10,13 });
	bomb_throw.PushBack({ 1894,428,10,11 });
	bomb_throw.PushBack({ 1907,428,10,10 });
	bomb_throw.PushBack({ 1920,428,10,7 });
	bomb_throw.PushBack({ 1933,428,10,5 });
	bomb_throw.speed = 0.08;

}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	position.x = 100;
	position.y = (camera_limits2.y + 300);
	lives = 2;
	if (App->characterselect->characterselected2 == 1) {
		graphics = App->textures->Load("assets/characters/ash.png");
		ash_bomb_texture = App->textures->Load("assets/ash_bomb.png");
	}
	else {
		graphics = App->textures->Load("assets/characters/valnus.png");
		valnus_bomb_texture = App->textures->Load("assets/valnus_bomb.png");
	}
	if (App->characterselect->characterselected2 == 1) {
		player2hitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	}
	else {
		player2hitbox = App->collision->AddCollider({ position.x, position.y, 31, 32 }, COLLIDER_PLAYER, this);
	}
	audio_shot = App->audio->LoadFX("assets/Audio/shoot_ash.wav");
	score = 0;
	time.x = 0;
	max_bomb_p2 = 2;

	return ret;
}

bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(ash_bomb_texture);
	App->textures->Unload(valnus_bomb_texture);
	App->collision->EraseCollider(player2hitbox);



	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{

	Animation* current_animation = &idle;

	float speed = 3.5f;
	position.y -= 1;
	camera_limits2.y -= 1;

	if (App->sea->pause == false) {
		if (dead == false) {
			//BOMB ----------------------
			if (bomb == false && max_bomb_p2 > 0) {
				bomb_position.y = position.y;
				if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN || App->input->buttonB2 == KEY_STATE::KEY_DOWN) {
					bomb = true;
					bomb_position.x = position.x;
					max_bomb_p2--;
				}
			}

			if (App->characterselect->characterselected2 == 3 && bomb == true) {
				speed = 1.5f;
			}
		}
		//MOVEMENT

		if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_REPEAT || App->input->dpadRight2 == KEY_STATE::KEY_REPEAT || App->input->joy_right2 == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &right;
			if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
				position.x += speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->dpadLeft2 == KEY_STATE::KEY_REPEAT || App->input->joy_left2 == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &left;
			if (position.x > 0) {
				position.x -= speed - 0.5;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_R] == KEY_STATE::KEY_REPEAT || App->input->dpadUp2 == KEY_STATE::KEY_REPEAT || App->input->joy_up2 == KEY_STATE::KEY_REPEAT)
		{
			if (position.y > camera_limits2.y + ASH_HEIGHT + 35) {
				position.y -= speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_REPEAT || App->input->dpadDown2 == KEY_STATE::KEY_REPEAT || App->input->joy_down2 == KEY_STATE::KEY_REPEAT)
		{
			if (position.y < camera_limits2.y + 273 + ASH_HEIGHT) {
				position.y += speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN || 0 < delay || App->input->buttonA2 == KEY_STATE::KEY_DOWN)
		{
			shooting = true;
			if (powerUps == 0) {
				if (App->characterselect->characterselected2 == 1) {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser1_1, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser1_2, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser1_3, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser1_1, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
				else {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser1_valnus_1, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser1_valnus_2, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser1_valnus_3, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser1_valnus_1, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
			}
			if (powerUps == 1) {
				if (App->characterselect->characterselected1 == 1) {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser2_1, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser2_2, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser2_3, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser2_1, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
				else {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser2_valnus_1, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser2_valnus_2, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser2_valnus_3, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser2_valnus_1, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
			}

			if (powerUps == 2) {
				if (App->characterselect->characterselected1 == 1) {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser3_1, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser3_2, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser3_3, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						App->particles->AddParticle(App->particles->AshShootWave1, position.x + 15, position.y - 50, 0, -15, COLLIDER_PLAYER_2_SHOT);
						App->particles->AddParticle(App->particles->AshShootWave1, position.x - 8, position.y - 50, 0, -15, COLLIDER_PLAYER_2_SHOT);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
				else {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser3_valnus_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser3_valnus_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser3_valnus_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						App->particles->AddParticle(App->particles->ValnusWave1_1, position.x - 39, position.y - 320, 0, 0, COLLIDER_VALNUS_2_LASER);
						App->particles->AddParticle(App->particles->ValnusWave1_2, position.x + 23, position.y - 320, 0, 0, COLLIDER_VALNUS_2_LASER);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser3_valnus_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
			}

			if (powerUps == 3) {
				if (App->characterselect->characterselected1 == 1) {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser4_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser4_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						App->particles->AddParticle(App->particles->AshShootWave2, position.x + 16, position.y - 50, 0, -15, COLLIDER_PLAYER_2_SHOT);
						App->particles->AddParticle(App->particles->AshShootWave2, position.x - 20, position.y - 50, 0, -15, COLLIDER_PLAYER_2_SHOT);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
				else {
					if (delay == 0) {
						App->particles->AddParticle(App->particles->laser4_valnus_1, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 7) {
						App->particles->AddParticle(App->particles->laser4_valnus_2, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
					}
					if (delay == 14) {
						App->particles->AddParticle(App->particles->laser4_valnus_3, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						App->particles->AddParticle(App->particles->ValnusWave2_1, position.x - 54, position.y - 326, 0, 0, COLLIDER_VALNUS_2_LASER);
						App->particles->AddParticle(App->particles->ValnusWave2_2, position.x + 25, position.y - 326, 0, 0, COLLIDER_VALNUS_2_LASER);
					}
					if (delay == 21) {
						App->particles->AddParticle(App->particles->laser4_valnus_1, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
						App->audio->PlayFX(audio_shot);
						shooting = false;
						delay = 0;
					}
					if (shooting == true) {
						delay++;
					}
				}
			}
			if (powerUps == 4) {
				powerUps--;
			}



		}

		if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN) {
			if (godmode2 == true) {
				godmode2 = false;
			}
			else if (godmode2 == false) {
				godmode2 = true;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN) {
			if (powerUps < 3) {
				powerUps++;
			}
			else if (powerUps == 3) {
				powerUps = 0;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
			if (max_bomb_p2 < 2) {
				max_bomb_p2++;
			}
			else if (max_bomb_p2 == 2) {
				max_bomb_p2 = 0;
			}
		}
	}
	if (App->characterselect->characterselected1 == 1) {
		player2hitbox->SetPos(position.x + 6, position.y - ASH_HEIGHT);
	}
	else {
		player2hitbox->SetPos(position.x, position.y - ASH_HEIGHT);
	}



	// Draw everything --------------------------------------

	SDL_Rect r = current_animation->GetCurrentFrame();

	//BOMB------------------------
	if (App->characterselect->characterselected2 == 1) {
		if (bomb == true) {
			if (delay2 < 75) {
				App->render->Blit(ash_bomb_texture, bomb_position.x, bomb_position.y - 10, &(bomb_throw.GetCurrentFrame()));
				delay2++;
				bomb_position.y -= 1;
			}
			if (delay2 == 75) {
				bombhitbox = App->collision->AddCollider({ bomb_position.x, bomb_position.y, 254, 254 }, COLLIDER_ASH_BOMB_2, this);
			}
			if (delay2 >= 75) {
				bombhitbox->SetPos(bomb_position.x - 124, bomb_position.y - 124);
				App->render->Blit(ash_bomb_texture, bomb_position.x - 124, bomb_position.y - 124, &(ash_bomb_animation.GetCurrentFrame()));
				delay2++;

			}

			if (delay2 == 209) {
				bomb = false;
				delay2 = 0;
				App->collision->EraseCollider(bombhitbox);

			}
			if (App->sea->pause == false) {
				bomb_position.y -= 1;
			}

		}
	}

	//IMMORTAL ANIMATION---------------------

	if (time.x > 150 && dead == false) {
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	else {
		App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
		time.x++;
	}






	//DEAD
	if (dead == true) {
		if (lives >= 0) {
			if (delay2 < 150) {
				App->render->Blit(graphics, 55, position_immortal.y, &(immortal.GetCurrentFrame()));
				if (position_immortal.y != camera_limits2.y + 243) {
					position_immortal.y -= 2;
				}
			}
			if (delay2 == 150) {
				position.x = 55;
				position.y = camera_limits2.y + 277;
				App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
			}
			if (delay2 == 300) {
				if (App->characterselect->characterselected1 == 1) {
					player2hitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
				}
				else {
					player2hitbox = App->collision->AddCollider({ position.x, position.y, 31, 32 }, COLLIDER_PLAYER, this);
				}
				delay2 = 0;
				dead = false;
			}
			else
				delay2++;
		}
		else {
			this->Disable();
		}
	}

	//BOMB VALNUS 

	if (App->characterselect->characterselected2 == 3) {
		if (bomb == true) {
			speed = 1.5;
			if (bomb == true) {
				if (delay2 == 0) {
					bombhitbox = App->collision->AddCollider({ position.x, position.y, 580, 150 }, COLLIDER_ASH_BOMB_2, this);
					bombhitbox2 = App->collision->AddCollider({ position.x, position.y, 150, 580 }, COLLIDER_ASH_BOMB_2, this);
					delay2++;
				}
				if (delay2 < 105) {
					bombhitbox->SetPos(position.x - 275, position.y - 90);
					bombhitbox2->SetPos(position.x - 60, position.y - 275);
					App->render->Blit(valnus_bomb_texture, position.x - 275, position.y - 303, &(valnus_bomb_animation.GetCurrentFrame()));
					App->render->Blit(valnus_bomb_texture, position.x - 5.5f, position.y - 37, &(valnus_bomb.GetCurrentFrame()));
					delay2++;
				}
				if (delay2 == 105) {
					bomb = false;
					delay2 = 0;
					App->collision->EraseCollider(bombhitbox);
					App->collision->EraseCollider(bombhitbox2);
				}
			}

		}
	}

	return UPDATE_CONTINUE;
}

void  ModulePlayer2::OnCollision(Collider *c1, Collider *c2) {


	if (App->sea->pause == false) {
		if (c1 == player2hitbox && App->ui->destroyed == false && App->fade->IsFading() == false)
		{

			if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {

				powerUps += 1;
			}

			else {
				if (godmode2 == false) {
					lives--;
					if (App->characterselect->characterselected2 == 1) {
						App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
					}
					else {
						App->particles->AddParticle(App->particles->dead_valnus, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
					}
					position.y = camera_limits2.y + 800;
					position_immortal.y = camera_limits2.y + 350;
					App->collision->EraseCollider(player2hitbox);
					dead = true;

				}
			}
		}
	}
}

