#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleWelcome.h"
#include "ModuleCongrats.h"
#include "ModuleSea.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include <stdio.h>


ModuleCongrats::ModuleCongrats()
{
	// Background 
	congrats.x = 0;
	congrats.y = 0;
	congrats.w = 224;
	congrats.h = 320;

	p1.PushBack({ 8,30,55,20 });
	p2.PushBack({ 8,53,55,20 });

	gameover.PushBack({ 0,30,124,16 });
	gameover.PushBack({ 0,0,0,0 });
	gameover.speed = 0.05f;

	score_ranking.PushBack({ 6,3,114,21 });
}

ModuleCongrats::~ModuleCongrats()
{}

// Load assets
bool ModuleCongrats::Start()
{
 App->render->camera.x = App->render->camera.y = 0;
	LOG("Loading background assets");
	bool ret = true;
	congratstexture = App->textures->Load("assets/background_congrats.png");
	gameovertexture = App->textures->Load("assets/ui.png");
	rankingtexture = App->textures->Load("assets/game_over_ui.png");
	App->audio->LoadMusic("assets/Audio/scoreboard.ogg");
	font_score = App->fonts->Load("assets/numbers_score.png", "0123456789", 1);

	App->player->position.x = 100;
	App->player->position.y = (App->player->camera_limits.y + 300);
	App->player->lives = 2;
	App->player->score = 0;
	App->player->max_bomb = 2;
	App->sea->sea_x = -64;

	return ret;
}

bool ModuleCongrats::CleanUp()
{
	App->textures->Unload(congratstexture);
	App->textures->Unload(gameovertexture);
	App->textures->Unload(rankingtexture);
	App->audio->UnloadMusic();
	App->fonts->UnLoad(font_score);
	App->player->powerUps = 0;
	App->player2->powerUps = 0;
	App->congrats->Disable();
	LOG("Unloading stage");



	return true;
}

// Update: draw background
update_status ModuleCongrats::Update()
{
	char str[10];
	char str2[10];

	// Draw everything --------------------------------------


	App->render->Blit(congratstexture, 0, -320 + SCREEN_HEIGHT, &congrats, 0.75f);

	App->render->Blit(gameovertexture, 50, 136, &(gameover.GetCurrentFrame()), 0.22f);
	App->render->Blit(rankingtexture, 41, 52, &(p1.GetCurrentFrame()), 0.22f);
	App->render->Blit(rankingtexture, 39, 76, &(p2.GetCurrentFrame()), 0.22f);
	App->render->Blit(rankingtexture, 56, 17, &(score_ranking.GetCurrentFrame()), 0.22f);

	sprintf_s(str, "%i", App->player->score);
	sprintf_s(str2, "%i", App->player2->score);

	App->fonts->BlitText(136, 58, font_score, str);
	App->fonts->BlitText(136, 82, font_score, str2);


	if (App->input->keyboard[SDL_SCANCODE_F7] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->welcome, 1);
		change = true;
		//App->input->buttonA = false;

	}

	if (App->input->keyboard[SDL_SCANCODE_1] && change || App->input->buttonA == KEY_STATE::KEY_DOWN && change) {

		change = false;
		App->fade->FadeToBlack(this, App->welcome, 1);
		change = true;

	}



	return UPDATE_CONTINUE;
}