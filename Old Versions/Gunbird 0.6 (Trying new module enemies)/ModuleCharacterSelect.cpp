#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleWelcome.h"
#include "ModuleCharacterSelect.h"
#include "ModuleSea.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include <stdio.h>


ModuleCharacterSelect::ModuleCharacterSelect()
{
	// Background 
	background.x = 0;
	background.y = 0;
	background.w = 224;
	background.h = 320;

	//UI
	p1.PushBack({ 19,2,32,52 });
	p2.PushBack({ 76,2,32,52 });
	cloud1.PushBack({ 0,0,417,96 });
	cloud2.PushBack({ 0,0,417,96 });
	
	//Characters Faces
	ash_face.PushBack({8,8,96,96});
	marion_face.PushBack({ 8,112,96,96 });
	valnus_face.PushBack({ 8,216,96,96 });
	yuan_face.PushBack({ 8,320,96,96 });
	tetsu_face.PushBack({ 256,8,96,96 });

	//Character Names
	ash_name.PushBack({120,25,27,21});
	marion_name.PushBack({121,127,54,21});
	valnus_name.PushBack({121,231,53,22});
	yuan_name.PushBack({120,334,49,43});
	yuan_name_coop.PushBack({ 200,338,83,21 });
	tetsu_name.PushBack({368,24,44,20});

	//----------Character Animations----------

	//Ash
	ash_anim.PushBack({ 13,11,104,109 });
	ash_anim.PushBack({ 163,11,104,109 });
	ash_anim.PushBack({ 328,11,104,109 });
	ash_anim.PushBack({ 485,11,104,109 });
	ash_anim.speed = 0.15f;

	//Marion
	marion_anim.PushBack({ 17,140,128,103 });
	marion_anim.PushBack({ 235,140,128,104 });
	marion_anim.PushBack({ 455,140,128,105 });
	marion_anim.speed = 0.15f;

	//Valnus
	valnus_anim.PushBack({ 16,275,120,118 });
	valnus_anim.PushBack({ 168,275,120,118 });
	valnus_anim.PushBack({ 320,275,120,118 });
	valnus_anim.PushBack({ 471,275,120,118 });
	valnus_anim.speed = 0.5f;

	//Yuan Nang
	yuan_anim.PushBack({ 20,13,135,125 });
	yuan_anim.PushBack({ 162,13,135,125 });
	yuan_anim.PushBack({ 303,13,135,125 });
	yuan_anim.PushBack({ 450,13,135,125 });
	yuan_anim.PushBack({ 591,13,135,125 });
	yuan_anim.PushBack({ 732,13,135,125 });
	yuan_anim.PushBack({ 20,166,135,125 });
	yuan_anim.PushBack({ 158,165,135,125 });
	yuan_anim.speed = 0.2f;

	//Tetsu
	tetsu_anim1.PushBack({ 426,241,121,16});
	tetsu_anim1.PushBack({ 426,267,121,15 });
	tetsu_anim1.PushBack({ 426,292,121,14 });
	tetsu_anim1.PushBack({ 426,315,121,16 });
	tetsu_anim1.speed = 0.8f;

	tetsu_anim2.PushBack({ 1,318,125,101 });
	tetsu_anim2.PushBack({ 139,318,125,101 });
	tetsu_anim2.PushBack({ 279,318,125,101 });
	tetsu_anim2.speed = 0.1f;

	//----------Character Selection----------

	//Ash

	ash.PushBack({ 14, 13, 19, 32 });
	ash.PushBack({ 43, 13, 19, 32 });
	ash.speed = 0.2f;

	//Marion
	marion.PushBack({ 4, 67, 20, 30 });
	marion.PushBack({ 36, 67, 20, 30 });
	marion.PushBack({ 67, 67, 20, 30 });
	marion.PushBack({ 100, 67, 20, 30 });
	marion.speed = 0.2f;

	//Valnus
	valnus.PushBack({ 0,0,31,30 });
	valnus.PushBack({ 38,0, 31,30 });
	valnus.speed = 0.4f;

	//Yuan_Nang
	yuan.PushBack({ 9,6,27,48 });
	yuan.PushBack({ 53,6,27,48 });
	yuan.PushBack({ 107,7,27,48 });
	yuan.PushBack({ 159,5,27,48 });
	yuan.PushBack({ 14,95,27,48 });
	yuan.PushBack({ 61,96,27,48 });
	yuan.PushBack({ 112,97,27,48 });
	yuan.PushBack({ 163,99,27,48 });
	yuan.speed = 0.2f;

	//tetsu
	tetsu.PushBack({ 31,17,30,37 });
	tetsu.PushBack({ 71,17,30,37 });
	tetsu.PushBack({ 111,17,30,37 });
	tetsu.PushBack({ 151,17,30,37 });
	tetsu.PushBack({ 191,17,30,37 });
	tetsu.PushBack({ 31,64,30,37 });
	tetsu.PushBack({ 71,64,30,37 });
	tetsu.PushBack({ 111,64,30,37 });
	tetsu.PushBack({ 151,64,30,37 });
	tetsu.PushBack({ 191,64,30,37 });
	tetsu.PushBack({ 31,111,30,37 });
	tetsu.PushBack({ 71,111,30,37 });
	tetsu.PushBack({ 111,111,30,37 });
	tetsu.PushBack({ 149,111,30,37 });
	tetsu.PushBack({ 191,111,30,37 });
	tetsu.PushBack({ 31,158,30,37 });
	tetsu.PushBack({ 71,158,30,37 });
	tetsu.PushBack({ 111,158,30,37 });
	tetsu.PushBack({ 151,158,30,37 });
	tetsu.PushBack({ 191,158,30,37 });
	tetsu.PushBack({ 31,205,30,37 });
	tetsu.PushBack({ 71,205,30,37 });
	tetsu.PushBack({ 111,205,30,37 });
	tetsu.PushBack({ 151,205,30,37 });
	tetsu.speed = 0.5f;

	coins_indicator.PushBack({ 69,8,38,8 });
	time_indicator.PushBack({ 71,0,29,8 });
}

ModuleCharacterSelect::~ModuleCharacterSelect()
{}

// Load assets
bool ModuleCharacterSelect::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	font_time = App->fonts->Load("assets/numbers_time.png", "0123456789", 1);
	change_selection= App->audio->LoadFX("assets/Audio/change_character.wav"); 
	characterselecttexture = App->textures->Load("assets/character_selection/characterselection.png");
	characterfaces = App->textures->Load("assets/character_selection/character_faces.png");
	clouds = App->textures->Load("assets/character_selection/clouds.png");
	p1select = App->textures->Load("assets/character_selection/characterselection_ui.png");
	characteranimation1 = App->textures->Load("assets/character_selection/character_selection_animation_1.png");
	characteranimation2 = App->textures->Load("assets/character_selection/character_selection_animation_2.png");
	ash_texture= App->textures->Load("assets/characters/ash.png"); 
	marion_texture= App->textures->Load("assets/characters/marion.png");
	tetsu_texture= App->textures->Load("assets/characters/tetsu_idle.png");
	valnus_texture= App->textures->Load("assets/characters/valnus.png");
	yuan_texture= App->textures->Load("assets/characters/yuan_nang.png");

	font_coins = App->fonts->Load("assets/numbers_score.png", "0123456789", 1);
	ui= App->textures->Load("assets/ui.png");

	characterselected1 = 2;
	characterselected2 = 4;
	p1_x = 56;
	cloud1_x = 0;
	cloud2_x = 417;
	timer = 9;
	delay3 = 0;
	App->welcome->coins--;

	App->audio->LoadMusic("assets/Audio/characterselection.ogg");
	return ret;
}

bool ModuleCharacterSelect::CleanUp()
{
	LOG("Unloading stage");
	App->fonts->UnLoad(font_time);
	App->textures->Unload(characterselecttexture);
	App->textures->Unload(characterfaces);
	App->textures->Unload(clouds);
	App->textures->Unload(p1select);
	App->textures->Unload(characteranimation1);
	App->textures->Unload(characteranimation2);
	App->textures->Unload(ash_texture);
	App->textures->Unload(ui);
	App->fonts->UnLoad(font_coins);
	App->audio->UnloadMusic();
	App->textures->Unload(marion_texture);
	App->textures->Unload(tetsu_texture);
	App->textures->Unload(valnus_texture);
	App->textures->Unload(yuan_texture);
	App->characterselect->Disable();
	

	return true;
}

// Update: draw background
update_status ModuleCharacterSelect::Update()
{

	// Draw everything --------------------------------------

	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN || App->input->buttonStart2 == KEY_STATE::KEY_DOWN) {
		coop = true;
		if (characterselected1 == 4) {
			characterselected2 = 2;
		}
		else {
			characterselected2 == 4;
		}
	}

	App->render->Blit(characterselecttexture, 0, -320 + SCREEN_HEIGHT, &background, 0.75f);
	
	// Clouds 

	if (cloud2_x == 0) {
		cloud1_x = 417;
	}
	if (cloud1_x == 0) {
		cloud2_x = 417;
	}
	
	App->render->Blit(clouds, cloud1_x, 144, &(cloud1.GetCurrentFrame()), 0.22f);
	App->render->Blit(clouds, cloud2_x, 144, &(cloud2.GetCurrentFrame()), 0.22f);

	cloud1_x-=0.5f;
	cloud2_x-=0.5f;

	// MOVEMENT

	//Player1
	if (coop == false) {
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN || App->input->dpadRight == KEY_STATE::KEY_DOWN || App->input->joy_right == KEY_STATE::KEY_DOWN) {
			if (characterselected1 < 5) {
				characterselected1 += 1;
			}
			else if (characterselected1 == 5) {
				characterselected1 = 1;
			}
			App->audio->PlayFX(change_selection);
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN || App->input->dpadLeft == KEY_STATE::KEY_DOWN || App->input->joy_left == KEY_STATE::KEY_DOWN) {
			if (characterselected1 > 1) {
				characterselected1 -= 1;				
			}
			else {
				characterselected1 = 5;
			}
			App->audio->PlayFX(change_selection);

		}
	}
	//Player2

	if (coop == true) {
		//Player 1

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN || App->input->dpadRight == KEY_STATE::KEY_DOWN || App->input->joy_right == KEY_STATE::KEY_DOWN) {
			if (characterselected1 < 5) {
				if (characterselected1 == characterselected2 - 1) {
					characterselected1 += 2;
				}
				else {
					characterselected1 += 1;
				}
			}
			else if (characterselected1 == 5) {
				if (characterselected2 == 1) {
					characterselected1 = 2;
				}
				else {
					characterselected1 = 1;
				}
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN || App->input->dpadLeft == KEY_STATE::KEY_DOWN || App->input->joy_left == KEY_STATE::KEY_DOWN) {
			if (characterselected1 > 1) {
				if (characterselected1 == characterselected2 + 1) {
					characterselected1 -= 2;
				}
				else {
					characterselected1 -= 1;
				}
			}
			else if (characterselected1 == 1) {
				if (characterselected2 == 5) {
					characterselected1 = 4;
				}
				else {
					characterselected1 = 5;
				}
			}
		}

		//Player 2

		if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN || App->input->dpadRight2 == KEY_STATE::KEY_DOWN || App->input->joy_right2 == KEY_STATE::KEY_DOWN) {
			if (characterselected2 < 5) {
				if (characterselected2 == characterselected1 - 1) {
					characterselected2 += 2;
				}
				else {
					characterselected2 += 1;
				}
			}
			else if (characterselected2 == 5) {
				if (characterselected1 == 1) {
					characterselected2 = 2;
				}
				else {
					characterselected2 = 1;
				}
			}
			
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN || App->input->dpadLeft2 == KEY_STATE::KEY_DOWN || App->input->joy_left2 == KEY_STATE::KEY_DOWN) {
			if (characterselected2 > 1) {
				if (characterselected2 == characterselected1 + 1) {
					characterselected2 -= 2;
				}
				else {
					characterselected2 -= 1;
				}
			}
			
			else if (characterselected2 == 1) {
				if (characterselected1 == 5) {
					characterselected2 = 4;
				}
				else {
					characterselected2 = 5;
				}
			}
		}
	}

	if (characterselected1 == 6) {
		characterselected1 =1;
	}
	if (characterselected1 == 0) {
		characterselected1 = 5;
	}
	if (characterselected2 == 6) {
		characterselected2 = 1;
	}
	if (characterselected2 == 0) {
		characterselected2 = 5;
	}

	// SELECTOR POSITION

	if (characterselected1 == 1) { p1_x =16; }
	if (characterselected1 == 2) { p1_x = 56; }
	if (characterselected1 == 3) { p1_x = 96; }
	if (characterselected1 == 4) { p1_x = 136; }
	if (characterselected1 == 5) { p1_x =176; }

	if (characterselected2 == 1) { p2_x = 16; }
	if (characterselected2 == 2) { p2_x = 56; }
	if (characterselected2 == 3) { p2_x = 96; }
	if (characterselected2 == 4) { p2_x = 136; }
	if (characterselected2 == 5) { p2_x = 176; }

	if (App->input->keyboard[SDL_SCANCODE_P] && change || App->input->buttonA == KEY_STATE::KEY_DOWN && change) {

		change = false;
		App->fade->FadeToBlack(this, App->sea, 1);
		change = true;
		//App->input->buttonA = false;
		
	}






	//SELECTOR
	
	if (coop == false) {

		if (characterselected1 == 1) {
			App->render->Blit(characterfaces, 12, 32, &(ash_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 51, 165, &(ash_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 96, 129, &(ash_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 2) {
			App->render->Blit(characterfaces, 12, 32, &(marion_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 21, 165, &(marion_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 80, 132, &(marion_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 3) {
			App->render->Blit(characterfaces, 12, 32, &(valnus_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 22, 165, &(valnus_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 90, 117, &(valnus_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 4) {
			App->render->Blit(characterfaces, 12, 32, &(yuan_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 19, 165, &(yuan_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 72, 117, &(yuan_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 5) {
			App->render->Blit(characterfaces, 12, 32, &(tetsu_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 43, 166, &(tetsu_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 91, 140, &(tetsu_anim2.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 99, 129, &(tetsu_anim1.GetCurrentFrame()), 0.22f);

		}
	}

	if (coop == true) {
		//Player1
		if (characterselected1 == 1) {
			App->render->Blit(characterfaces, 12, 32, &(ash_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 47, 5, &(ash_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1,8, 129, &(ash_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 2) {
			App->render->Blit(characterfaces, 12, 32, &(marion_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 34, 5, &(marion_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 0, 134, &(marion_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 3) {
			App->render->Blit(characterfaces, 12, 32, &(valnus_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 34, 5, &(valnus_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 2, 118, &(valnus_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 4) {
			App->render->Blit(characterfaces, 12, 32, &(yuan_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 19, 5, &(yuan_name_coop.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 0, 117, &(yuan_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected1 == 5) {
			App->render->Blit(characterfaces, 12, 32, &(tetsu_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 39, 6, &(tetsu_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 3, 140, &(tetsu_anim2.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 11, 129, &(tetsu_anim1.GetCurrentFrame()), 0.22f);

		}

		//Player2
		if (characterselected2 == 1) {
			App->render->Blit(characterfaces,116, 32, &(ash_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 151, 5, &(ash_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 120, 129, &(ash_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected2 == 2) {
			App->render->Blit(characterfaces, 116, 32, &(marion_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 138, 5, &(marion_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 112, 134, &(marion_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected2 == 3) {
			App->render->Blit(characterfaces, 116, 32, &(valnus_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 138, 5, &(valnus_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation1, 114, 118, &(valnus_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected2 == 4) {
			App->render->Blit(characterfaces, 116, 32, &(yuan_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 123, 5, &(yuan_name_coop.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 104, 117, &(yuan_anim.GetCurrentFrame()), 0.22f);
		}
		if (characterselected2 == 5) {
			App->render->Blit(characterfaces, 116, 32, &(tetsu_face.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterfaces, 143, 6, &(tetsu_name.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 111, 140, &(tetsu_anim2.GetCurrentFrame()), 0.22f);
			App->render->Blit(characteranimation2, 119, 129, &(tetsu_anim1.GetCurrentFrame()), 0.22f);

		}

	}


	//Characters
	App->render->Blit(ash_texture, 23, 256, &(ash.GetCurrentFrame()), 0.22f);
	App->render->Blit(marion_texture, 63, 254, &(marion.GetCurrentFrame()), 0.22f);
	App->render->Blit(valnus_texture, 97, 255, &(valnus.GetCurrentFrame()), 0.22f);
	App->render->Blit(yuan_texture, 137, 249, &(yuan.GetCurrentFrame()), 0.22f);
	App->render->Blit(tetsu_texture, 178, 254, &(tetsu.GetCurrentFrame()), 0.22f);
	//Selectors
	App->render->Blit(p1select, p1_x, 244, &(p1.GetCurrentFrame()), 0.22f);
	if (coop == true) {
		App->render->Blit(p1select, p2_x, 244, &(p2.GetCurrentFrame()), 0.22f);
	}

	
	//COINS
	if (App->input->keyboard[SDL_SCANCODE_5] == KEY_STATE::KEY_DOWN) {
		if (App->welcome->coins < 9) {
			App->welcome->coins++;
		}
	}
	char str[10];
	sprintf_s(str, "%i", App->welcome->coins);
	if (App->welcome->coins > 0) {
		App->fonts->BlitText(194, 303, font_coins, str);
		App->render->Blit(ui, 155, 306, &(coins_indicator.GetCurrentFrame()), 0.22f);
	}

	//TIME 

	App->render->Blit(ui, 89, 306, &(time_indicator.GetCurrentFrame()), 0.22f);
	char str2[10];
	sprintf_s(str2, "%i", timer);
	App->fonts->BlitText(122, 301, font_time, str2);

	if (delay3 == 100) { timer--; }
	if (delay3 == 200) { timer--; }
	if (delay3 == 300) { timer--; }
	if (delay3 == 400) { timer--; }
	if (delay3 == 500) { timer--; }
	if (delay3 == 600) { timer--; }
	if (delay3 == 700) { timer--; }
	if (delay3 == 800) { timer--; }
	if (delay3 == 900) {
		timer--;
		change = false;
		App->fade->FadeToBlack(this, App->sea, 1);
		change = true;
	}
	delay3++;


	return UPDATE_CONTINUE;
}