#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleWelcome.h"
#include "ModuleCongrats.h"
#include "ModuleMine.h"
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


}

ModuleCongrats::~ModuleCongrats()
{}

// Load assets
bool ModuleCongrats::Start()
{
	/*handout 2*/App->render->camera.x = App->render->camera.y = 0;
	LOG("Loading background assets");
	bool ret = true;
	congratstexture = App->textures->Load("background_congrats.png");
	gameovertexture = App->textures->Load("ui.png");
	rankingtexture = App->textures->Load("game_over_ui.png");
	App->audio->LoadMusic("Audio/stageclear.ogg");
	font_score = App->fonts->Load("numbers_score.png", "0123456789", 1);

	gameover.PushBack({ 2,91,124,31 });
	gameover.PushBack({ 0,0,0,0 });
	gameover.speed = 0.013f;

	p1.PushBack({ 8,30,55,20 });
	score_ranking.PushBack({ 6,3,114,21 });

	return ret;
}

bool ModuleCongrats::CleanUp()
{
	App->textures->Unload(congratstexture);
	App->textures->Unload(gameovertexture);
	App->fonts->UnLoad(font_score);
	LOG("Unloading stage");



	return true;
}

// Update: draw background
update_status ModuleCongrats::Update()
{
	char str[10];

	// Draw everything --------------------------------------


	App->render->Blit(congratstexture, 0, -320 + SCREEN_HEIGHT, &congrats, 0.75f);

	App->render->Blit(gameovertexture, 50, 136, &(gameover.GetCurrentFrame()), 0.22f);
	App->render->Blit(rankingtexture, 41, 52, &(p1.GetCurrentFrame()), 0.22f);
	App->render->Blit(rankingtexture, 56, 17, &(score_ranking.GetCurrentFrame()), 0.22f);

	sprintf_s(str, "%i", App->player->score);
	App->fonts->BlitText(136, 58, font_score, str);


	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->welcome, 1);
		change = true;

	}



	return UPDATE_CONTINUE;
}