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
	ash_bomb_animation.PushBack({ 0,0,0,0 });
	ash_bomb_animation.speed = 0.7f;

	bomb_throw.PushBack({ 1868,428,10,14 });
	bomb_throw.PushBack({ 1881,428,10,13 });
	bomb_throw.PushBack({ 1894,428,10,11 });
	bomb_throw.PushBack({ 1907,428,10,10 });
	bomb_throw.PushBack({ 1920,428,10,7 });
	bomb_throw.PushBack({ 1933,428,10,5 });
	bomb_throw.speed = 0.08;

	life_indicator.PushBack({ 146,21,11,13 });
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	position.x = 100;
	position_lives = 21;
	position.y = (camera_limits.y + 300);
	lives = 2;

	graphics = App->textures->Load("assets/characters/ash.png");
	ash_bomb_texture = App->textures->Load("assets/ash_bomb.png");
	playerhitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	font_score = App->fonts->Load("assets/numbers.png", "0123456789", 1);
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

	if (App->mine->pause == false) {
		//BOMB ----------------------
		if (bomb == false && max_bomb>0) {
			bomb_position.y = position.y;
			if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN) {
				bomb = true;
				bomb_position.x = position.x;
				max_bomb--;				
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &right;
			if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
				position.x += speed;
			}
		//	App->input->dpad_state = DPAD_STATE::DPAD_IDLE;
		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			current_animation = &left;
			if (position.x > 0) {
				position.x -= speed;
			}
		//	App->input->dpad_state = DPAD_STATE::DPAD_IDLE;
		}

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
		{
			if (position.y > camera_limits.y + ASH_HEIGHT + 35) {
				position.y -= speed;
			}
		//	App->input->dpad_state = DPAD_STATE::DPAD_IDLE;
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			if (position.y < camera_limits.y + SCREEN_HEIGHT) {
				position.y += speed;
			}
		//	App->input->dpad_state = DPAD_STATE::DPAD_IDLE;
		}

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || 0 < delay)
		{
			shooting = true;
			if (powerUps == 0) {
				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser1_1, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser1_2, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser1_3, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser1_1, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->state == GC_STATE::GC_IDLE;
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
					App->particles->AddParticle(App->particles->laser2_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser2_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//		App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser2_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser2_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
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
					App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser3_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave1, position.x+20, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave1, position.x-15, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//		App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser3_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
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
					App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser4_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave2, position.x + 20, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave2, position.x - 15, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//		App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser4_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser4_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//	App->input->state == GC_STATE::GC_IDLE;
					shooting = false;
					delay = 0;
				}
				if (shooting == true) {
					delay++;
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
		}

		if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN) {
			if (powerUps > 0) {
				powerUps--;
			}
		}

		if (App->player2->IsEnabled()) {}

		else {
			if (App->input->keyboard[SDL_SCANCODE_Q]) {
				App->player2->Enable();
				App->player2->position.x = SCREEN_WIDTH / 2 + 10;
				App->player2->position.y = position.y;
				App->player2->destroyed = false;
			}
		}

	}

	playerhitbox->SetPos(position.x, position.y - ASH_HEIGHT);
	


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//BOMB------------------------

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

		if (delay2 == 205) {
			bomb = false;
			delay2 = 0;
			App->collision->EraseCollider(bombhitbox);

		}
		bomb_position.y -= 1;

	}

	if (dead == true) {
		if (delay2 < 100) {
			App->render->Blit(graphics, 100, position_immortal.y, &(immortal.GetCurrentFrame()));
			if (position_immortal.y != camera_limits.y + 266) {
				position_immortal.y -= 2;
			}
		}
		if (delay2 == 100) {
			position.x = 100;
			position.y =camera_limits.y + 300;
			App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
		}
		if (delay2 == 300) {
			playerhitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
			delay2 = 0;
			dead = false;
		}
		else
			delay2++;
	}

	sprintf_s(score_text, 10, "%7d", score);

	//IMMORTAL ANIMATION---------------------

	if (time.x > 150 && dead == false) {
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	else {
		App->render->Blit(graphics, position.x, position.y - r.h, &(immortal.GetCurrentFrame()));
		time.x++;
	}

	

	// PLAYER LIVES

	if (lives == 2) {
		App->render->Blit(graphics, 6, camera_limits.y + 21, &(life_indicator.GetCurrentFrame()));
		App->render->Blit(graphics, 22, camera_limits.y + 21, &(life_indicator.GetCurrentFrame()));
	}
	if (lives == 1) {
		App->render->Blit(graphics, 6, camera_limits.y+21, &(life_indicator.GetCurrentFrame()));
	}


	

	return UPDATE_CONTINUE;
}

void  ModulePlayer::OnCollision(Collider *c1, Collider *c2) {


	if (App->mine->pause == false) {
		if (c1 == playerhitbox && destroyed == false && App->fade->IsFading() == false)
		{

			if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {

				powerUps += 1;
			}

			else {
				if (godmode == false) {
					if (lives == 0) {
						App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
						App->textures->Unload(graphics);
						App->fade->FadeToBlack((Module*)App->mine, (Module*)App->congrats);
						destroyed = true;
					}
					else {
						lives--;
						App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
						position.y = camera_limits.y + 800;
						position_immortal.y = camera_limits.y + 350;
						App->collision->EraseCollider(playerhitbox);
						dead = true;
					}
				}
			}
		}
	}
}

