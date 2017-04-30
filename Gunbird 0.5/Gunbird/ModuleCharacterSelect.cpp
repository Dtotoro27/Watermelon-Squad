#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleWelcome.h"
#include "ModuleCharacterSelect.h"
#include "ModuleMine.h"
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
	tetsu_name.PushBack({368,24,44,20});

	//----------Character Animations----------

	//Ash
	ash_anim.PushBack({ 13,11,104,109 });
	ash_anim.PushBack({ 163,11,104,109 });
	ash_anim.PushBack({ 328,11,104,109 });
	ash_anim.PushBack({ 485,11,104,109 });
	ash_anim.speed = 0.1f;

	//Marion
	marion_anim.PushBack({ 17,140,128,103 });
	marion_anim.PushBack({ 235,140,128,104 });
	marion_anim.PushBack({ 455,140,128,105 });
	marion_anim.speed = 0.1f;

	//Valnus
	valnus_anim.PushBack({ 16,275,120,118 });
	valnus_anim.PushBack({ 168,275,120,118 });
	valnus_anim.PushBack({ 320,275,120,118 });
	valnus_anim.PushBack({ 471,275,120,118 });
	valnus_anim.speed = 0.1f;

	//Yuan Nang
	yuan_anim.PushBack({ 20,13,135,125 });
	yuan_anim.PushBack({ 162,13,135,125 });
	yuan_anim.PushBack({ 303,13,135,125 });
	yuan_anim.PushBack({ 450,13,135,125 });
	yuan_anim.PushBack({ 591,13,135,125 });
	yuan_anim.PushBack({ 732,13,135,125 });
	yuan_anim.PushBack({ 20,166,135,125 });
	yuan_anim.PushBack({ 158,165,135,125 });
	yuan_anim.speed = 0.1f;
}

ModuleCharacterSelect::~ModuleCharacterSelect()
{}

// Load assets
bool ModuleCharacterSelect::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	characterselecttexture = App->textures->Load("assets/character_selection/characterselection.png");
	characterfaces = App->textures->Load("assets/character_selection/character_faces.png");
	clouds = App->textures->Load("assets/character_selection/clouds.png");
	p1select = App->textures->Load("assets/character_selection/characterselection_ui.png");
	characteranimation1 = App->textures->Load("assets/character_selection/ash_marion_valnus_selection_animation.png");
	tetsuanimation = App->textures->Load("assets/character_selection/tetsu_selection_animation.png");
	yuananimation = App->textures->Load("assets/character_selection/yuan_selection_animation.png");
	characterselected = 2;
	p1_x = 56;

	return ret;
}

bool ModuleCharacterSelect::CleanUp()
{
	App->textures->Unload(characterselecttexture);
	App->textures->Unload(characterfaces);
	App->textures->Unload(clouds);
	App->textures->Unload(p1select);
	App->textures->Unload(characteranimation1);
	App->textures->Unload(tetsuanimation);
	App->textures->Unload(yuananimation);
	App->characterselect->Disable();
	LOG("Unloading stage");

	return true;
}

// Update: draw background
update_status ModuleCharacterSelect::Update()
{
	int cloud1_x = 0;
	int cloud2_x = 417;
	// Draw everything --------------------------------------


	App->render->Blit(characterselecttexture, 0, -320 + SCREEN_HEIGHT, &background, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {
		if (p1_x < 176) {
			p1_x += 40;
			characterselected++;
		}
		else if(p1_x==176) {
			p1_x = 16;
			characterselected = 1;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {
		if (p1_x > 16) {
			p1_x -= 40;
			characterselected--;
		}
		else if (p1_x == 16) {
			p1_x = 176;
			characterselected = 5;
		}
	}


	if (App->input->keyboard[SDL_SCANCODE_P] && change) {

		change = false;
		App->fade->FadeToBlack(this, App->mine, 1);
		change = true;
	}

	if (characterselected == 1) {
		App->render->Blit(characterfaces, 12, 32, &(ash_face.GetCurrentFrame()), 0.22f);
		App->render->Blit(characterfaces, 51, 165, &(ash_name.GetCurrentFrame()), 0.22f);
		App->render->Blit(characteranimation1, 96, 129, &(ash_anim.GetCurrentFrame()), 0.22f);
	}
	if (characterselected == 2) {
		App->render->Blit(characterfaces, 12, 32, &(marion_face.GetCurrentFrame()), 0.22f);
		App->render->Blit(characterfaces, 21, 165, &(marion_name.GetCurrentFrame()), 0.22f);
		App->render->Blit(characteranimation1, 80, 132, &(marion_anim.GetCurrentFrame()), 0.22f);
	}
	if (characterselected == 3) {
		App->render->Blit(characterfaces, 12, 32, &(valnus_face.GetCurrentFrame()), 0.22f);
		App->render->Blit(characterfaces, 22, 165, &(valnus_name.GetCurrentFrame()), 0.22f);
		App->render->Blit(characteranimation1, 90, 117, &(valnus_anim.GetCurrentFrame()), 0.22f);
	}
	if (characterselected == 4) {
		App->render->Blit(characterfaces, 12, 32, &(yuan_face.GetCurrentFrame()), 0.22f);
		App->render->Blit(characterfaces, 19, 165, &(yuan_name.GetCurrentFrame()), 0.22f);
		App->render->Blit(yuananimation, 72, 128, &(yuan_anim.GetCurrentFrame()), 0.22f);
	}
	if (characterselected == 5) {
		App->render->Blit(characterfaces, 12, 32, &(tetsu_face.GetCurrentFrame()), 0.22f);
		App->render->Blit(characterfaces, 43, 166, &(tetsu_name.GetCurrentFrame()), 0.22f);
	}


	App->render->Blit(p1select, p1_x, 244, &(p1.GetCurrentFrame()), 0.22f);

	return UPDATE_CONTINUE;
}