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

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	
	camera_limits.y = 0;

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

	collision_animation.PushBack({ 0, 0, 31, 32 });
	collision_animation.PushBack({ 62, 0, 21, 32 });
	collision_animation.PushBack({ 0, 0, 31, 32 });
	collision_animation.PushBack({ 104, 0, 21, 32 });
	collision_animation.speed = 0.1f;

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

	valnus_bomb_animation.PushBack({1,1,580,576});
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
	valnus_bomb_animation.PushBack({ 1,578,580,576});
	valnus_bomb_animation.PushBack({ 1,578,580,576 });
	valnus_bomb_animation.PushBack({ 582,578,580,576 });
	valnus_bomb_animation.PushBack({ 582,578,580,576 });
	valnus_bomb_animation.PushBack({ 1163,578,580,576 });
	valnus_bomb_animation.PushBack({ 1163,578,580,576 });
	valnus_bomb_animation.PushBack({ 1744,578,580,576 });
	valnus_bomb_animation.PushBack({ 1744,578,580,576 });
	valnus_bomb_animation.speed = 0.4;

	valnus_bomb.PushBack({2331,638,43,39});
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

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	position.x = 100;
	position.y = (camera_limits.y + 300);
	lives = 2;
	if (App->characterselect->characterselected1 == 1) {
		graphics = App->textures->Load("assets/characters/ash.png");
		ash_bomb_texture = App->textures->Load("assets/ash_bomb.png");
	}
	else {
		graphics = App->textures->Load("assets/characters/valnus.png");
		valnus_bomb_texture = App->textures->Load("assets/valnus_bomb.png");
	}
	if (App->characterselect->characterselected1 == 1) {
		playerhitbox = App->collision->AddCollider({ position.x + 1, position.y, 13, 32 }, COLLIDER_PLAYER, this);
	}
	else {
		playerhitbox = App->collision->AddCollider({ position.x + 10, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	}
	audio_shot = App->audio->LoadFX("assets/Audio/shoot_ash.wav");
	score = 0;
	time.x = 0;
	max_bomb = 2;

	return ret;
}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(ash_bomb_texture);
	App->textures->Unload(valnus_bomb_texture);
	App->collision->EraseCollider(playerhitbox);



	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{

		Animation* current_animation = &idle;

    float speed = 3.5f;
	position.y -= 1;
	camera_limits.y -= 1;

	if (App->sea->pause == false) {
		if (dead == false) {
			//BOMB ----------------------
			if (bomb == false && max_bomb > 0) {
				bomb_position.y = position.y;
				if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_STATE::KEY_DOWN || App->input->buttonB == KEY_STATE::KEY_DOWN) {
					bomb = true;
					bomb_position.x = position.x;
					max_bomb--;
				}
			}

			if (App->characterselect->characterselected1 == 3 && bomb == true) {
				speed = 1.5f;
			}
		}
		//MOVEMENT

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT || App->input->dpadRight == KEY_STATE::KEY_REPEAT || App->input->joy_right == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &right;
			if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
				position.x += speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT || App->input->dpadLeft == KEY_STATE::KEY_REPEAT || App->input->joy_left == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &left;
			if (position.x > 0) {
				position.x -= speed - 0.5;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT || App->input->dpadUp == KEY_STATE::KEY_REPEAT || App->input->joy_up == KEY_STATE::KEY_REPEAT)
		{
			if (position.y > camera_limits.y + ASH_HEIGHT + 35) {
				position.y -= speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT || App->input->dpadDown == KEY_STATE::KEY_REPEAT || App->input->joy_down == KEY_STATE::KEY_REPEAT)
		{
			if (position.y < camera_limits.y + 273+ASH_HEIGHT) {
				position.y += speed;
			}
		}
		if (collision == false) {
			if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || 0 < delay || App->input->buttonA == KEY_STATE::KEY_DOWN)
			{
				shooting = true;
				if (powerUps == 0) {
					if (App->characterselect->characterselected1 == 1) {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser1_1, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser1_2, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser1_3, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser1_1, position.x + 8, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
						//App->audio->LoadFX("Audio/shoot_ash.wav");
					}
					else {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser1_valnus_1, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser1_valnus_2, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser1_valnus_3, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser1_valnus_1, position.x + 9, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
						//App->audio->LoadFX("Audio/shoot_ash.wav");
					}
				}
				if (powerUps == 1) {
					//App->audio->LoadFX("Audio/shoot_ash.wav");
					if (App->characterselect->characterselected1 == 1) {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser2_1, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser2_2, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser2_3, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser2_1, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
					}
					else {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser2_valnus_1, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser2_valnus_2, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser2_valnus_3, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser2_valnus_1, position.x + 4, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
					}
				}

				if (powerUps == 2) {
					//App->audio->LoadFX("Audio/shoot_ash.wav");
					if (App->characterselect->characterselected1 == 1) {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser3_1, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser3_2, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser3_3, position.x + 3, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							App->particles->AddParticle(App->particles->AshShootWave1, position.x + 15, position.y - 50, 0, -15, COLLIDER_PLAYER_SHOT);
							App->particles->AddParticle(App->particles->AshShootWave1, position.x - 8, position.y - 50, 0, -15, COLLIDER_PLAYER_SHOT);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
					}
					else {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser3_valnus_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser3_valnus_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser3_valnus_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							App->particles->AddParticle(App->particles->ValnusWave1_1, position.x - 39, position.y - 320, 0, 0, COLLIDER_VALNUS_LASER);
							App->particles->AddParticle(App->particles->ValnusWave1_2, position.x + 23, position.y - 320, 0, 0, COLLIDER_VALNUS_LASER);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser3_valnus_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
					}
				}

				if (powerUps == 3) {
					//App->audio->LoadFX("Audio/shoot_ash.wav");
					if (App->characterselect->characterselected1 == 1) {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser4_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser4_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							App->particles->AddParticle(App->particles->AshShootWave2, position.x + 16, position.y - 50, 0, -15, COLLIDER_PLAYER_SHOT);
							App->particles->AddParticle(App->particles->AshShootWave2, position.x - 20, position.y - 50, 0, -15, COLLIDER_PLAYER_SHOT);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
							shooting = false;
							delay = 0;
						}
						if (shooting == true) {
							delay++;
						}
					}
					else {
						if (delay == 0) {
							App->particles->AddParticle(App->particles->laser4_valnus_1, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 7) {
							App->particles->AddParticle(App->particles->laser4_valnus_2, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
						}
						if (delay == 14) {
							App->particles->AddParticle(App->particles->laser4_valnus_3, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							App->particles->AddParticle(App->particles->ValnusWave2_1, position.x - 54, position.y - 326, 0, 0, COLLIDER_VALNUS_LASER);
							App->particles->AddParticle(App->particles->ValnusWave2_2, position.x + 25, position.y - 326, 0, 0, COLLIDER_VALNUS_LASER);
							//App->input->buttonA = false;
						}
						if (delay == 21) {
							App->particles->AddParticle(App->particles->laser4_valnus_1, position.x - 7, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
							App->audio->PlayFX(audio_shot);
							//App->input->buttonA = false;
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
		}
		if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN) {
			if (godmode == true) {
				godmode = false;
			}
			else if (godmode == false) {
				godmode = true;
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
			if (max_bomb < 2) {
				max_bomb++;
			}
			else if (max_bomb == 2) {
				max_bomb = 0;
			}
		}

		if (App->player2->IsEnabled()) {}

		else {
			if (App->input->keyboard[SDL_SCANCODE_2]) {
				App->player2->Enable();
				App->player2->position.x = SCREEN_WIDTH / 2 + 10;
				App->player2->position.y = position.y;
			}
		}

	}
	if (App->characterselect->characterselected1 == 1) {
		playerhitbox->SetPos(position.x + 9, position.y - ASH_HEIGHT);
	}
	else{
		playerhitbox->SetPos(position.x + 6, position.y - ASH_HEIGHT);
	}
	


	// Draw everything --------------------------------------

	
	
	//BOMB------------------------
	if (App->characterselect->characterselected1 == 1) {
		if (bomb == true) {
			if (delay2 < 75) {
				App->render->Blit(ash_bomb_texture, bomb_position.x, bomb_position.y - 10, &(bomb_throw.GetCurrentFrame()));
				delay2++;
				bomb_position.y -= 1;
			}
			if (delay2 == 75) {
				bombhitbox = App->collision->AddCollider({ bomb_position.x, bomb_position.y, 254, 254 }, COLLIDER_ASH_BOMB, this);
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
	if (App->input->keyboard[SDL_SCANCODE_T] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->collision, position.x, position.y - 50, 0, 0);
	}


	//IMMORTAL ANIMATION---------------------

		if (time.x > 150 && dead == false) {
			//COLLISION
			if (collision == true) {
				current_animation = &collision_animation;
				SDL_Rect r = current_animation->GetCurrentFrame();
				if (timer2 == 0) {
					if (powerUps != 0) {
						powerUps--;
					}
					if (powerUps == 1) {
						powerUps = 0;
					}
					timer2++;
				}
				if (timer2 == 1) {
					App->particles->AddParticle(App->particles->collision, position.x, position.y - 50, 0, 0);
				}
				if (timer2 == 50) {
					collision = false;
					timer2 = 0;
					current_animation = &idle;
				}
				timer2++;
				App->render->Blit(graphics, position.x, position.y - r.h, &r);
			}
			else {
				SDL_Rect r = current_animation->GetCurrentFrame();
				App->render->Blit(graphics, position.x, position.y - r.h, &r);
			}
			
		}
		else {
			SDL_Rect r = current_animation->GetCurrentFrame();
			App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
			time.x++;
		}
	


	//DEAD
	if (dead == true) {
		powerUps = 0;
		if (lives >= 0) {
			if (delay2 < 150) {
				App->render->Blit(graphics, 55, position_immortal.y, &(immortal.GetCurrentFrame()));
				if (position_immortal.y != camera_limits.y + 243) {
					position_immortal.y -= 2;
				}
			}
			if (delay2 == 150) {
				position.x = 55;
				SDL_Rect r = current_animation->GetCurrentFrame();
				position.y = camera_limits.y + 277;
				App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
			}
			if (delay2 == 300) {
				if (App->characterselect->characterselected1 == 1) {
					playerhitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
				}
				else {
					playerhitbox = App->collision->AddCollider({ position.x, position.y, 31, 32 }, COLLIDER_PLAYER, this);
				}
				delay2 = 0;
				dead = false;
			}
			else
				delay2++;
		}
	}

	//BOMB VALNUS 

	if (App->characterselect->characterselected1 == 3) {
		if (bomb == true) {
			speed = 1.5;
			if (bomb == true) {
				if (delay2 == 0) {
					bombhitbox = App->collision->AddCollider({ position.x, position.y, 580, 150 }, COLLIDER_ASH_BOMB, this);
					bombhitbox2 = App->collision->AddCollider({ position.x, position.y, 150, 580}, COLLIDER_ASH_BOMB, this);
					delay2++;
				}
				if (delay2 < 105) {
					bombhitbox->SetPos(position.x - 275, position.y - 90);
					bombhitbox2->SetPos(position.x - 60, position.y - 275);
					App->render->Blit(valnus_bomb_texture, position.x -275 , position.y - 303 , &(valnus_bomb_animation.GetCurrentFrame()));
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

void  ModulePlayer::OnCollision(Collider *c1, Collider *c2) {


	if (App->sea->pause == false) {
		if (c1 == playerhitbox && App->ui->destroyed == false && App->fade->IsFading() == false)
		{

			if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {
				powerUps += 1;
			}

			else if (c2->type == COLLIDER_TYPE::COLLIDER_EXTRA_BOMB) {
				if (max_bomb<2)
				max_bomb +=1;
			}

			else if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY || c2->type == COLLIDER_TYPE::COLLIDER_BALLOON || c2->type == COLLIDER_TYPE::COLLIDER_BOMB) {
				collision = true;
			}
			else{
				if (godmode == false) {
						lives--;
						if (App->characterselect->characterselected1 == 1) {
							App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
						}
						else {
							App->particles->AddParticle(App->particles->dead_valnus, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
						}
						position.y = camera_limits.y + 800;
						position_immortal.y = camera_limits.y + 350;
						App->collision->EraseCollider(playerhitbox);
						dead = true;
					
				}
			}
		}
	}
}

