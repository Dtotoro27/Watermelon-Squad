#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer2.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"

#include<stdio.h>


ModulePlayer2::ModulePlayer2()
{
	position.x = 100;
	position.y = 220;

	camera_limitsp2.y = 0;

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

	position.x = 150;
	position.y = (App->player->camera_limits.y + 300);
	lives = 2;
	graphics = App->textures->Load("assets/characters/ash.png"); // arcade version
	ash_bomb_texture = App->textures->Load("assets/ash_bomb.png");
	ui = App->textures->Load("assets/ui.png");
	player2hitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	audio_shot = App->audio->LoadFX("assets/Audio/shoot_ash.wav");
	score = 0;
	time.x = 0;
	max_bomb = 2;
	delay3 = 0;

	return ret;
}

bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(ash_bomb_texture);
	App->collision->EraseCollider(player2hitbox);

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	
	float speed = 3.5f;
	camera_limitsp2 = App->player->camera_limits;

	if (App->sea->pause == false) {
		position.y -= 1;
		//BOMB ----------------------
		if (bomb == false && max_bomb>0) {
			bomb_position.y = position.y;
			if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || App->input->buttonB2 == KEY_STATE::KEY_DOWN) {
				bomb = true;
				bomb_position.x = position.x;
				max_bomb--;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->dpadRight2 == KEY_STATE::KEY_REPEAT || App->input->joy_right2 == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &right;
			if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
				position.x += speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->dpadLeft2 == KEY_STATE::KEY_REPEAT || App->input->joy_left2 == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &left;
			if (position.x > 0) {
				position.x -= speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->dpadUp2 == KEY_STATE::KEY_REPEAT || App->input->joy_up2 == KEY_STATE::KEY_REPEAT)
		{
			if (position.y > camera_limitsp2.y + ASH_HEIGHT + 35) {
				position.y -= speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->dpadDown2 == KEY_STATE::KEY_REPEAT || App->input->joy_down2 == KEY_STATE::KEY_REPEAT)
		{
			if (position.y < camera_limitsp2.y + SCREEN_HEIGHT) {
				position.y += speed;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_V] == KEY_STATE::KEY_DOWN || 0 < delay || App->input->buttonA2 == KEY_STATE::KEY_DOWN)
		{
			shooting = true;
			if (powerUps == 0) {
				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser1_1, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser1_2, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser1_3, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser1_1, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
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
			if (powerUps == 1) {
				//App->audio->LoadFX("Audio/shoot_ash.wav");

				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser2_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser2_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser2_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser2_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
					shooting = false;
					delay = 0;
				}
				if (shooting == true) {
					delay++;
				}
			}

			if (powerUps == 2) {
				//App->audio->LoadFX("Audio/shoot_ash.wav");

				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser3_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser3_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					App->particles->AddParticle(App->particles->AshShootWave1, position.x + 15, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave1, position.x - 8, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					//App->input->buttonA = false;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
					shooting = false;
					delay = 0;
				}
				if (shooting == true) {
					delay++;
				}
			}

			if (powerUps == 3) {
				//App->audio->LoadFX("Audio/shoot_ash.wav");

				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser4_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser4_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					App->particles->AddParticle(App->particles->AshShootWave2, position.x + 16, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave2, position.x - 20, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					//App->input->buttonA = false;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_2_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
					shooting = false;
					delay = 0;
				}
				if (shooting == true) {
					delay++;
				}
			}
			if (powerUps == 4) {
				powerUps--;
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
		if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN) {
			if (powerUps < 3) {
				powerUps++;
			}
			else if (powerUps == 3) {
				powerUps = 0;
			}			
		}
		if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN) {
			if (max_bomb < 2) {
				max_bomb++;
			}
			else if (max_bomb == 2) {
				max_bomb = 0;
			}
		}
	}

	player2hitbox->SetPos(position.x, position.y - ASH_HEIGHT);



	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

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
		bomb_position.y -= 1;

	}

	if (dead == true) {
		if (delay3 < 100) {
			App->render->Blit(graphics, 100, position_immortal.y, &(App->player->immortal.GetCurrentFrame()));
			if (position_immortal.y != App->player->camera_limits.y + 266) {
				position_immortal.y -= 2;
			}
		}
		if (delay3 == 100) {
			position.x = 100;
			position.y = App->player->camera_limits.y + 300;
			App->render->Blit(graphics, position.x, position.y - r.h, &(App->player->immortal.GetCurrentFrame()));
		}
		if (delay3 == 300) {
			player2hitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
			delay3 = 0;
			dead = false;
		}
		else
			delay3++;
	}

	if (dead == false) {
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	else {
		App->render->Blit(graphics, position.x, position.y - r.h, &(App->player->immortal.GetCurrentFrame()));
	}


	return UPDATE_CONTINUE;
}



void  ModulePlayer2::OnCollision(Collider *c1, Collider *c2) {


	if (App->sea->pause == false) {
		if (c1 == player2hitbox && destroyed == false && App->fade->IsFading() == false)
		{

			if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {

				powerUps += 1;
			}

			else {
				if (godmode2 == false) {
					lives--;
					App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
					position.y = App->player->camera_limits.y + 800;
					position_immortal.y = App->player->camera_limits.y + 350;
					App->collision->EraseCollider(player2hitbox);
					dead = true;

				}
			}
		}
	}
}



