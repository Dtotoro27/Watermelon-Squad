#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCharacterSelect.h"
#include "ModuleWelcome.h"
#include "ModuleSea.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"

#include<stdio.h>


ModuleWelcome::ModuleWelcome()
{
	// Background 
	welcome.x = 0;
	welcome.y = 0;
	welcome.w = 224;
	welcome.h = 320;

	//start animation
	gameover.PushBack({ 0,15,68,15 });
	gameover.PushBack({ 0,0,68,15 });
	gameover.PushBack({ 0,0,0,0 });
	gameover.PushBack({ 0,0,0,0 });
	gameover.speed = 0.05f;

	coins_indicator.PushBack({69,8,38,8});


}

ModuleWelcome::~ModuleWelcome()
{}

// Load assets
bool ModuleWelcome::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	coins = 1;
	font_coins = App->fonts->Load("assets/numbers_score.png", "0123456789", 1);
	welcometexture = App->textures->Load("assets/background_welcome.png");
	gameovertexture = App->textures->Load("assets/ui.png");
	insert_coin_audio = App->audio->LoadFX("assets/Audio/add_coin.wav");
	//App->audio->LoadMusic("assets/Audio/characterselection.ogg");
	


	return ret;
}

bool ModuleWelcome::CleanUp()
{
	App->textures->Unload(welcometexture);
	App->textures->Unload(gameovertexture);
	App->fonts->UnLoad(font_coins);
	App->audio->UnloadMusic();
	App->welcome->Disable();
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleWelcome::Update()
{

	// Draw everything --------------------------------------

	App->render->Blit(welcometexture, 0, -320 + SCREEN_HEIGHT, &welcome, 0.75f);

	App->render->Blit(gameovertexture, 75, 224, &(gameover.GetCurrentFrame()), 0.22f);
	App->render->Blit(gameovertexture, 81, 306, &(coins_indicator.GetCurrentFrame()), 0.22f);

	

	if (App->input->keyboard[SDL_SCANCODE_1] && change || App->input->buttonA == KEY_STATE::KEY_DOWN && change || App->input->keyboard [SDL_SCANCODE_F8] && change) {
		change = false;
		App->fade->FadeToBlack(this, App->characterselect, 1);
		change = true;
		//App->input->buttonA = false;
	}
	if (App->input->keyboard[SDL_SCANCODE_5] == KEY_STATE::KEY_DOWN || App->input->buttonY == KEY_STATE::KEY_DOWN && change) {
		if (coins < 9) {
			App->audio->PlayFX(insert_coin_audio);
			coins++;
		}
	}



	char str[10];
	sprintf_s(str, "%i", coins);
	App->fonts->BlitText(121, 303, font_coins, str);


	return UPDATE_CONTINUE;
}