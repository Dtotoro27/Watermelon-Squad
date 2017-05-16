#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWelcome.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleSea.h"
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

	
	camera_limits.y = 0;
	pause_position.y = 0;

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
	ash_bomb_animation.speed = 0.7f;

	bomb_throw.PushBack({ 1868,428,10,14 });
	bomb_throw.PushBack({ 1881,428,10,13 });
	bomb_throw.PushBack({ 1894,428,10,11 });
	bomb_throw.PushBack({ 1907,428,10,10 });
	bomb_throw.PushBack({ 1920,428,10,7 });
	bomb_throw.PushBack({ 1933,428,10,5 });
	bomb_throw.speed = 0.08;

	game_over.PushBack({0,30,124,16});
	cont.PushBack({ 0,59,71,12 });

	time_background.PushBack({ 0,71,15,16 });
	time_background.PushBack({ 15,71,15,16 });
	time_background.PushBack({ 30,71,15,16 });
	time_background.PushBack({ 45,71,15,16 });
	time_background.PushBack({ 60,71,15,16 });
	time_background.PushBack({ 75,71,15,16 });
	time_background.PushBack({ 90,71,15,16 });
	time_background.PushBack({ 105,71,15,16 });
	time_background.PushBack({ 0,87,15,16 });
	time_background.PushBack({ 15,87,15,16 });
	time_background.PushBack({ 30,87,15,16 });
	time_background.PushBack({ 45,87,15,16 });
	time_background.PushBack({ 60,87,15,16 });
	time_background.PushBack({ 75,87,15,16 });
	time_background.PushBack({ 90,87,15,16 });
	time_background.PushBack({ 105,87,15,16 });
	time_background.speed = 0.217;

	life_indicator.PushBack({ 146,21,11,13 });

	coins_indicator.PushBack({ 69,8,38,8 });

	bomb_indicator.PushBack({ 107,0,12,15 });


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
	pause_position.y = 0;
	lives = 2;
	delay3 = 0;
	graphics = App->textures->Load("assets/characters/ash.png");
	ash_bomb_texture = App->textures->Load("assets/ash_bomb.png");
	ui = App->textures->Load("assets/ui.png");
	playerhitbox = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, this);
	font_score = App->fonts->Load("assets/numbers.png", "0123456789", 1);
	font_time = App->fonts->Load("assets/numbers_time.png", "0123456789", 1);
	font_coins = App->fonts->Load("assets/numbers_score.png", "0123456789", 1);
	audio_shot = App->audio->LoadFX("assets/Audio/shoot_ash.wav");
	score = 0;
	timer = 9;
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
	App->fonts->UnLoad(font_time);
	App->fonts->UnLoad(font_coins);


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

	if (App->sea->pause == false) {
		//BOMB ----------------------
		if (bomb == false && max_bomb>0) {
			bomb_position.y = position.y;
			if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN || App->input->buttonB == KEY_STATE::KEY_DOWN) {
				bomb = true;
				bomb_position.x = position.x;
				max_bomb--;				
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
				position.x -= 3;
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

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || 0 < delay || App->input->buttonA == KEY_STATE::KEY_DOWN)
		{
			shooting = true;
			if (powerUps == 0) {
				if (delay == 0) {
					App->particles->AddParticle(App->particles->laser1_1, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser1_2, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser1_3, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser1_1, position.x + 2, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser2_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser2_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser2_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 21) {
					App->particles->AddParticle(App->particles->laser2_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser3_1, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 7) {
					App->particles->AddParticle(App->particles->laser3_2, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					//App->input->buttonA = false;
				}
				if (delay == 14) {
					App->particles->AddParticle(App->particles->laser3_3, position.x, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->audio->PlayFX(audio_shot);
					App->particles->AddParticle(App->particles->AshShootWave1, position.x + 15, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave1, position.x - 8, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
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

			if (powerUps == 3) {
				//App->audio->LoadFX("Audio/shoot_ash.wav");

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
					App->particles->AddParticle(App->particles->AshShootWave2, position.x + 16, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->AshShootWave2, position.x - 20, position.y - 50, 0, -10, COLLIDER_PLAYER_SHOT);
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
			if (powerUps == 4) {
				powerUps--;
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

		if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
			if (max_bomb > 0) {
				max_bomb--;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN) {
			if (max_bomb < 2) {
				max_bomb++;
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

		if (delay2 == 209) {
			bomb = false;
			delay2 = 0;
			App->collision->EraseCollider(bombhitbox);

		}
		bomb_position.y -= 1;

	}


	sprintf_s(score_text, 10, "%7d", score);
	sprintf_s(gameover_time, 10, "%7d", timer);


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


	//Pause 
	if (App->sea->pause == true) {
		App->render->DrawQuad({ 0,pause_position.y,SCREEN_WIDTH,SCREEN_HEIGHT }, 0, 0, 0,100);
	}
	else {
		pause_position.y--;
	}

	//COINS
	if (App->input->keyboard[SDL_SCANCODE_5] == KEY_STATE::KEY_DOWN) {
		if (App->welcome->coins < 9) {
			App->welcome->coins++;
		}
	}

	char str3[10];
	sprintf_s(str3, "%i", App->welcome->coins);
	if (App->welcome->coins > 0) {
		if (App->sea->pause == false) {
			if (App->player2->IsEnabled()) {
				App->fonts->BlitText(120, 303, font_coins, str3);
				App->render->Blit(ui, 81, 306, &(coins_indicator.GetCurrentFrame()), 0);
			}
			else {
				App->fonts->BlitText(194, 303, font_coins, str3);
				App->render->Blit(ui, 155, 306, &(coins_indicator.GetCurrentFrame()), 0);
			}
		}
		else {
			App->fonts->BlitText(120, 303, font_coins, str3);
			App->render->Blit(ui, 81, 306, &(coins_indicator.GetCurrentFrame()), 0);
		}
	}

	//BOMBS
	if (App->player->max_bomb == 1) {
		App->render->Blit(ui, 6, 300, &(bomb_indicator.GetCurrentFrame()), 0);
	}
	if (App->player->max_bomb == 2) {
		App->render->Blit(ui, 6, 300, &(bomb_indicator.GetCurrentFrame()), 0);
		App->render->Blit(ui, 22, 300, &(bomb_indicator.GetCurrentFrame()), 0);
	}

	//DEAD
	if (dead == true) {
		if (lives == -1) {
			if (delay3 > 100) {
				App->particles->AddParticle(App->particles->dead, position.x - 5, position.y - 25, 0, 0, COLLIDER_NONE, 150);
				position.y = camera_limits.y + 800;
				position_immortal.y = camera_limits.y + 350;
				char str2[10];
				sprintf_s(str2, "%i", timer);
				App->render->Blit(ui, 50, pause_position.y + 104, &(game_over.GetCurrentFrame()));
				App->render->Blit(ui, 145, pause_position.y + 136, &(time_background.GetCurrentFrame()));
				App->render->Blit(ui, 50, pause_position.y + 140, &(cont.GetCurrentFrame()));
				App->fonts->BlitText(146, 137, font_time, str2);
				App->sea->pause = true;
				delay3++;
			}
			if (delay3 == 250) { timer--; }
			if (delay3 == 400) { timer--; }
			if (delay3 == 550) { timer--; }
			if (delay3 == 700) { timer--; }
			if (delay3 == 850) { timer--; }
			if (delay3 == 1000) { timer--; }
			if (delay3 == 1150) { timer--; }
			if (delay3 == 1300) { timer--; }
			if (delay3 == 1450){ timer--; }
			if (delay3 == 1600) {
				App->textures->Unload(graphics);
				App->fade->FadeToBlack((Module*)App->sea, (Module*)App->congrats);
				destroyed = true;
			}
			delay3++;
			 if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN) {
				lives = 2;
				score += 1;
				delay3 = 0;
				timer = 9;
				App->welcome->coins--;
				App->sea->pause = false;
			}
		}
		else {
			if (delay2 < 150) {
				App->render->Blit(graphics, 55, position_immortal.y, &(immortal.GetCurrentFrame()));
				if (position_immortal.y != camera_limits.y + 243) {
					position_immortal.y -= 2;
				}
			}
			if (delay2 == 150) {
				position.x = 55;
				position.y = camera_limits.y + 277;
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
	}

	return UPDATE_CONTINUE;
}

void  ModulePlayer::OnCollision(Collider *c1, Collider *c2) {


	if (App->sea->pause == false) {
		if (c1 == playerhitbox && destroyed == false && App->fade->IsFading() == false)
		{

			if (c2->type == COLLIDER_TYPE::COLLIDER_POWER_UP) {

				powerUps += 1;
			}

			else {
				if (godmode == false) {
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

