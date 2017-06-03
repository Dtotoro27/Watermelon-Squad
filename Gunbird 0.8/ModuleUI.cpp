#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSea.h"
#include "ModuleUI.h"
#include "ModuleBoss.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCharacterSelect.h"
#include "ModuleParticles.h"
#include "ModuleWelcome.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "ModuleFadeToBlack.h"

#include<stdio.h>

ModuleUI::ModuleUI(){
	life_indicator_ash.PushBack({ 77,46,11,13 });
	life_indicator_valnus.PushBack({ 88,47,15,12 });

	start_player.PushBack({ 0,15,68,15 });
	start_player.PushBack({ 0,0,68,15 });;
	start_player.PushBack({ 0,0,0,0 });
	start_player.PushBack({ 0,0,0,0 });
	start_player.speed = 0.05;

	insert_coin.PushBack({0,46,73,13});
	insert_coin.PushBack({ 0,0,0,0 });
	insert_coin.speed = 0.05;

	p1.PushBack({ 71, 17, 15, 12 });
	p2.PushBack({ 90,17,16,12 });

	bomb_indicator.PushBack({ 107,0,12,15 });

	coins_indicator.PushBack({ 69,8,38,8 });

	game_over.PushBack({ 0,30,124,16 });
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

	trumpanimationo.PushBack({0,0,224,320});
	trumpanimationo.PushBack({ 224,0,224,320 });
	trumpanimationo.PushBack({ 448,0,224,320 });
	trumpanimationo.PushBack({ 672,0,224,320 });
	trumpanimationo.PushBack({ 0,320,224,321 });
	trumpanimationo.speed = 0.3f;
	trumpanimationo.loop = false;

	trumpanimationc.PushBack({ 0,320,224,320 });
	trumpanimationc.PushBack({ 672,0,224,320 });
	trumpanimationc.PushBack({ 448,0,224,320 });
	trumpanimationc.PushBack({ 224,0,224,320 });
	trumpanimationc.PushBack({ 0,0,224,320 });
	trumpanimationc.PushBack({ 0,0,0,0 });
	trumpanimationc.loop = false;
	trumpanimationc.speed = 0.3f;


}

ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start(){
	bool ret = true;

	ui = App->textures->Load("assets/ui.png");
	trump = App->textures->Load("assets/trump.png");
	font_score = App->fonts->Load("assets/numbers.png", "0123456789", 1);
	font_coins = App->fonts->Load("assets/numbers_score.png", "0123456789", 1);
	font_time = App->fonts->Load("assets/numbers_time.png", "0123456789", 1);

	timer = 9;
	timer2 = 0;
	pause_position.y = 0;
	delay3 = 0;

	return ret;
}

bool ModuleUI::CleanUp(){
	bool ret = true;
	App->textures->Unload(ui);
	App->fonts->UnLoad(font_score);
	App->fonts->UnLoad(font_coins);
	App->fonts->UnLoad(font_time);
	return ret;
}

update_status ModuleUI::Update() {

	//START PLAYERS-----------------

	if (App->player2->IsEnabled()) {}
	else {
		if (App->welcome->coins > 0) {
			App->render->Blit(ui, 118, 4, &(start_player.GetCurrentFrame()), 0);
		}
		else {
			App->render->Blit(ui, 118, 4, &(insert_coin.GetCurrentFrame()), 0);
		}
	}

	//SCORE-----------------

	char str[10];
	sprintf_s(str, "%i", App->player->score);
	App->fonts->BlitText(44, 7, font_score, str);
	App->render->Blit(ui, 5, 6, &(p1.GetCurrentFrame()), 0);

	if (App->player2->IsEnabled()) {
		char str2[10];
		sprintf_s(str2, "%i", App->player2->score);
		App->fonts->BlitText(180, 7, font_score, str2);
		App->render->Blit(ui, 116, 6, &(p2.GetCurrentFrame()), 0);
	}

	//PLAYERS LIVES-----------------

	if (App->player2->IsEnabled()) {
		if (App->characterselect->characterselected2 == 1) {
			if (App->player2->lives == 2) {
				App->render->Blit(ui, 117, 21, &(life_indicator_ash.GetCurrentFrame()), 0);
				App->render->Blit(ui, 133, 21, &(life_indicator_ash.GetCurrentFrame()), 0);
			}
			if (App->player2->lives == 1) {
				App->render->Blit(ui, 117, 21, &(life_indicator_ash.GetCurrentFrame()), 0);
			}
		}
		else {
			if (App->player2->lives == 2) {
				App->render->Blit(ui, 117, 21, &(life_indicator_valnus.GetCurrentFrame()), 0);
				App->render->Blit(ui, 133, 21, &(life_indicator_valnus.GetCurrentFrame()), 0);
			}
			if (App->player2->lives == 1) {
				App->render->Blit(ui, 117, 21, &(life_indicator_valnus.GetCurrentFrame()), 0);
			}
		}
	}

	if (App->characterselect->characterselected1 == 1) {
		if (App->player->lives == 2) {
			App->render->Blit(ui, 6, 21, &(life_indicator_ash.GetCurrentFrame()), 0);
			App->render->Blit(ui, 22, 21, &(life_indicator_ash.GetCurrentFrame()), 0);
		}
		if (App->player->lives == 1) {
			App->render->Blit(ui, 6, 21, &(life_indicator_ash.GetCurrentFrame()), 0);
		}
	}
	else {
		if (App->player->lives == 2) {
			App->render->Blit(ui, 6, 21, &(life_indicator_valnus.GetCurrentFrame()), 0);
			App->render->Blit(ui, 22, 21, &(life_indicator_valnus.GetCurrentFrame()), 0);
		}
		if (App->player->lives == 1) {
			App->render->Blit(ui, 6, 21, &(life_indicator_valnus.GetCurrentFrame()), 0);
		}
	}
	//BOMB-----------------

		if (App->player->max_bomb == 1) {
			App->render->Blit(ui, 6, 300, &(bomb_indicator.GetCurrentFrame()), 0);
		}
		if (App->player->max_bomb == 2) {
			App->render->Blit(ui, 6, 300, &(bomb_indicator.GetCurrentFrame()), 0);
			App->render->Blit(ui, 22, 300, &(bomb_indicator.GetCurrentFrame()), 0);
		}
		if (App->player2->IsEnabled()) {
			if (App->player2->max_bomb_p2 == 1) {
				App->render->Blit(ui, 118, 300, &(bomb_indicator.GetCurrentFrame()), 0);
			}
			if (App->player2->max_bomb_p2 == 2) {
				App->render->Blit(ui, 118, 300, &(bomb_indicator.GetCurrentFrame()), 0);
				App->render->Blit(ui, 134, 300, &(bomb_indicator.GetCurrentFrame()), 0);
			}
		}
	//CREDITS-----------------
		if (App->input->keyboard[SDL_SCANCODE_5] == KEY_STATE::KEY_DOWN) {
			if (App->welcome->coins < 9) {
				App->welcome->coins++;
			}
		}
		char str3[10];
		sprintf_s(str3, "%i", App->welcome->coins);

		if (App->welcome->coins > 0) {
			if (App->player2->IsEnabled()) {}
			else {
				if (App->sea->pause == false) {
					App->fonts->BlitText(194, 303, font_coins, str3);
					App->render->Blit(ui, 155, 306, &(coins_indicator.GetCurrentFrame()), 0);

				}
				else {
					App->fonts->BlitText(120, 303, font_coins, str3);
					App->render->Blit(ui, 81, 306, &(coins_indicator.GetCurrentFrame()), 0);
				}
			}
		}

	//PAUSE-----------------

		if (App->sea->pause == true) {
			App->render->DrawQuad({ 0,pause_position.y,SCREEN_WIDTH,SCREEN_HEIGHT }, 0, 0, 0, 100);
		}
		else {
			pause_position.y--;
		}

		if (App->player->lives == -1) {
			if (delay3 > 100) {
				App->particles->AddParticle(App->particles->dead, App->player->position.x - 5, App->player->position.y - 25, 0, 0, COLLIDER_NONE, 150);
				App->player->position.y = App->player->camera_limits.y + 800;
				App->player->position_immortal.y = App->player->camera_limits.y + 350;
				char str4[10];
				sprintf_s(str4, "%i", timer);
				App->render->Blit(ui, 50, pause_position.y + 104, &(game_over.GetCurrentFrame()));
				App->render->Blit(ui, 145, pause_position.y + 136, &(time_background.GetCurrentFrame()));
				App->render->Blit(ui, 50, pause_position.y + 140, &(cont.GetCurrentFrame()));
				App->fonts->BlitText(146, 137, font_time, str4);
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
			if (delay3 == 1450) { timer--; }
			if (delay3 == 1600) {
				App->textures->Unload(App->player->graphics);
				App->fade->FadeToBlack((Module*)App->sea, (Module*)App->congrats);
				destroyed = true;
			}
			delay3++;
			if (delay3 < 1600) {
				if (App->welcome->coins > 0) {
					if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN) {
						App->player->lives = 2;
						App->player->score += 1;
						delay3 = 0;
						timer = 9;
						App->welcome->coins--;
						App->sea->pause = false;
					}
				}
			
			}

		}

		//Trump
		if (App->sea->bossstart == true) {
			if (timer2 < 300) {
				App->render->Blit(trump, 0, pause_position.y, &(trumpanimationo.GetCurrentFrame()));
				timer2++;
			}
			else if (timer2 >= 300){
				App->render->Blit(trump, 0, pause_position.y, &(trumpanimationc.GetCurrentFrame()));
				timer2++;
			}
			if (timer2 == 310) {
				App->sea->bossstart = false;
				App->boss->spawnship = true;
			}
		}
	return UPDATE_CONTINUE;
}
