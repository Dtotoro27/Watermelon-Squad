#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleWelcome.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"
#include "ModuleSea.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleCongrats.h"
#include "ModuleCharacterSelect.h"
#include "ModuleUI.h"


ModuleSea::ModuleSea()
{
	// Background 

	sea_animation.PushBack({ 0, 0, 288, 2399 });
	sea_animation.PushBack({ 288, 0, 288, 2399 });
	sea_animation.PushBack({ 576, 0, 288, 2399 });
	sea_animation.PushBack({ 864, 0, 288, 2399 });
	sea_animation.PushBack({ 1152, 0, 288, 2399 });
	sea_animation.PushBack({ 864, 0, 288, 2399 });
	sea_animation.PushBack({ 576, 0, 288, 2399 });
	sea_animation.PushBack({ 288, 0, 288, 2399 });
	sea_animation.speed = 0.1;

	rock1.PushBack({0,0,46,175});
	rock1.PushBack({ 46,0,46,175 });
	rock1.PushBack({ 92,0,46,175 });
	rock1.PushBack({ 46,0,46,175 });
	rock1.speed = 0.06;

	rock2.PushBack({0,187,68,155});
	rock2.PushBack({ 68,187,68,155 });
	rock2.PushBack({ 137,187,68,155 });
	rock2.PushBack({ 206,187,68,155 });
	rock2.speed = 0.06;

	rock3.PushBack({ 320,5,14,117 });
	rock3.PushBack({ 337,5,14,117 });
	rock3.PushBack({ 353,5,14,117 });
	rock3.PushBack({ 367,5,14,117 });
	rock3.PushBack({ 382,5,14,117 });
	rock3.PushBack({ 398,5,14,117 });
	rock3.PushBack({ 413,5,14,117 });
	rock3.PushBack({ 398,5,14,117 });
	rock3.PushBack({ 382,5,14,117 });
	rock3.PushBack({ 367,5,14,117 });
	rock3.PushBack({ 353,5,14,117 });
	rock3.PushBack({ 337,5,14,117 });
	rock3.speed = 0.1;
}

ModuleSea::~ModuleSea()
{}

// Load assets
bool ModuleSea::Start()
{
	LOG("Loading background assets");

	App->player2->score = 0;
	pause = false;
	sea_speed = 0.22f;
	sea_x = -64;


	seatexture = App->textures->Load("assets/background_sea_1.png");
	rocktexture = App->textures->Load("assets/background_sea_2.png");
	startplayer2texture = App->textures->Load("assets/ui.png");

	App->audio->LoadMusic("assets/Audio/mine.ogg");


	App->player->Enable();
	if (App->characterselect->coop == true) {
		App->player2->Enable();
	}
	App->ui->destroyed = false;
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->ui->Enable();
	



	//Enemy


	App->enemies->AddEnemy(ENEMY_TYPES::POWER_UP, 150, 10);
	

	

	return true;
}

bool ModuleSea::CleanUp()
{

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->ui->Disable();
	App->textures->Unload(seatexture);	
	App->textures->Unload(rocktexture);
	App->textures->Unload(startplayer2texture);
	App->audio->UnloadMusic();
	App->sea->Disable();


	
	LOG("Unloading stage");
	return true;
}

// Update: draw background
update_status ModuleSea::Update()
{

	// -------------------------------------- Draw everything --------------------------------------

	if (App->player->dead == false) {
		if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN || App->input->buttonStart == KEY_STATE::KEY_DOWN) {
			if (pause == false) {
				pause = true;
			}
			else if (pause == true) {
				pause = false;
			}
		}
	}
	if (pause == true) {
		App->render->camera.y -= SCROLL_SPEED;
		App->player->position.y += 1;
		App->player->camera_limits.y += 1;
	}

	//Background--------------------------
	App->render->Blit(seatexture, sea_x, -2372 + SCREEN_HEIGHT, &(sea_animation.GetCurrentFrame()), sea_speed);
	App->render->Blit(rocktexture, 0, 44, &(rock1.GetCurrentFrame()), sea_speed);
	App->render->Blit(rocktexture, 156, 163, &(rock2.GetCurrentFrame()), sea_speed);
	App->render->Blit(rocktexture, sea_x + 128,-874, &(rock3.GetCurrentFrame()), sea_speed);

	if (delay > 5200) {
		if (sea_x < 0) {
			sea_x += 0.4;
		}
		
	}
	else {
		delay++;
	}


	//UI--------------------------


	if (App->render->camera.y <= 10000000) {
		App->render->camera.y += SCROLL_SPEED;
	}

	else {
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;		

	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN) {
		polla = App->render->camera.y;
		change = false;
		App->fade->FadeToBlack(this, App->congrats, 1);
		change = true;
	}

	//ENEMIES--------------------------

	
	
	if (App->render->camera.y == 560) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 164, -340);
	}

	if (App->render->camera.y == 590) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 55, -360);
	}

	if (App->render->camera.y == 620) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 95, -390);
	}
	
	if (App->render->camera.y == 680) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 194, -420);
	}

	if (App->render->camera.y == 740) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 10, -450);
	}

	if (App->render->camera.y == 800) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 122, -470);
	}

	if (App->render->camera.y == 860) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 30, -490);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 184, -490);
	}

	if (App->render->camera.y == 890) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 60, -510);
	}

	if (App->render->camera.y == 920) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 90, -530);
	}

	if (App->render->camera.y == 950) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 194, -550);
	}

	if (App->render->camera.y == 980) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 0, -570);
	}

	if (App->render->camera.y == 1010) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 112, -590);
	}

	if (App->render->camera.y == 1040) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 30, -610);
	}

	if (App->render->camera.y == 600) {
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET, 224, -240);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET, 304, -274);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET, 384, -308);
	}

	if (App->render->camera.y == 900) {
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -30, -475);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -130, -475);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -230, -475);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -330, -475);
	}

	if (App->render->camera.y == 50) {
		App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, 50, -50);
	}

	if (App->render->camera.y == 1270) {
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET, 188, -665);
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET, 188, -700);
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET, 188, -735);
	}
	if (App->render->camera.y == 1500) {
		App->enemies->AddEnemy(ENEMY_TYPES::BIGSHIPSTATIC, 10, -850);
	}

	if (App->render->camera.y == 2770) {
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -30, -1400);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -130, -1400);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -230, -1400);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -330, -1400);
	}

	if (App->render->camera.y == 2850) {
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -45, -1475);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -145, -1475);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -245, -1475);
		App->enemies->AddEnemy(ENEMY_TYPES::SURFINGTURRET2, -345, -1475);
	}

	if (App->render->camera.y == 3450) {
		App->enemies->AddEnemy(ENEMY_TYPES::BIGSHIPMOVE, 145, -1850);
	}

	if (App->render->camera.y == 4600) {
		App->enemies->AddEnemy(ENEMY_TYPES::BLUETURRET, 66, -2327);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -2327);
	}
	if (App->render->camera.y == 4700) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -2457);
	}
	if (App->render->camera.y == 4700) {
		App->enemies->AddEnemy(ENEMY_TYPES::BLUETURRET, 66, -2430);
	}
	if (App->render->camera.y == 5400) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -2745);
	}
	if (App->render->camera.y == 5600) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -2900);
	}
	if (App->render->camera.y == 5800) {
		App->enemies->AddEnemy(ENEMY_TYPES::BLUETURRET, 66, -2927);
	}
	if (App->render->camera.y == 6390) {
		App->enemies->AddEnemy(ENEMY_TYPES::BLUETURRET, 66, -3222);
	}
	if (App->render->camera.y == 6150) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -3157);
	}
	if (App->render->camera.y == 6800) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -3435);
	}
	if (App->render->camera.y == 7200) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -3645);
	}
	if (App->render->camera.y == 7500) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALSURFINGTURRET, 10, -3820);
	}




	if (App->render->camera.y == 9450) {
		App->enemies->AddEnemy(ENEMY_TYPES::BIGSHIPMOVE, 0, -4850);
	}




	if (App->render->camera.y == 1550) {
		App->enemies->AddEnemy(ENEMY_TYPES::TOWER, 96, -882);
	}
	if (App->render->camera.y == 7100) {
		App->enemies->AddEnemy(ENEMY_TYPES::BLUEROBOT, -80, -3475);
	}
	if (App->render->camera.y == 8890) {

		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET2, 110, -4480);
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET2, 110, -4512);
	}
	if (App->render->camera.y == 10050) {
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET4, 110, -5083);
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET4, 110, -5052);
	}
	
	if (App->render->camera.y == 9100) {
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET3, 110, -4625);
		App->enemies->AddEnemy(ENEMY_TYPES::STATICTURRET3, 110, -4657);
	}	
	
	if (App->render->camera.y == 9200) {
		App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE1, -45, -4610);
		App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE1, -30, -4650);
		App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE1, -60, -4650);
		App->enemies->AddEnemy(ENEMY_TYPES::BLUEROBOT2, 230, -4585);
	}

	if (App->render->camera.y == 9350) {
		App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE2, 245, -4670);
		App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE2, 230, -4720);
		App->enemies->AddEnemy(ENEMY_TYPES::REDMACHINE2, 260, -4720);
	}


	///*

	//if (App->render->camera.y == 9100) {
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 90, -4554);
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 60, -4574);
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 30, -4594);
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 1, -4614);

	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 102, -4554);
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 132, -4574);
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 162, -4594);
	//	App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 192, -4614);

	//}
	//*/

	if (App->render->camera.y == 11100) {
		App->enemies->AddEnemy(ENEMY_TYPES::UPSURFINGTURRET, 65, -5220);
		App->enemies->AddEnemy(ENEMY_TYPES::UPSURFINGTURRET, 100, -5210);
		App->enemies->AddEnemy(ENEMY_TYPES::UPSURFINGTURRET, 135, -5200);
	}
	if (App->render->camera.y == 11400) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 15, -5700);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 50, -5720);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 85, -5740);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 120, -5760);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 155, -5780);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 190, -5800);
	}

	if (App->render->camera.y == 11850) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 224, -5850);
	}
	if (App->render->camera.y == 11900) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 254, -5890);
	}
	if (App->render->camera.y == 11950) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 284, -5930);
	}

	if (App->render->camera.y == 12150) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, -10, -5950);
	}
	if (App->render->camera.y == 12200) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, -40, -5990);
	}
	if (App->render->camera.y == 12250) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, -70, -6030);
	}


	
	if (App->render->camera.y == 12760) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 164, -6460);
	}

	if (App->render->camera.y == 12770) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 55, -6470);
	}

	if (App->render->camera.y == 12800) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 95, -6475);
	}

	if (App->render->camera.y == 12860) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 194, -6500);
	}

	if (App->render->camera.y == 12920) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 10, -6520);
	}

	if (App->render->camera.y == 13000) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 122, -6540);
	}

	if (App->render->camera.y == 13060) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 30, -6550);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 184, -6550);
	}

	if (App->render->camera.y == 13090) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 60, -6570);
	}

	if (App->render->camera.y == 13120) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 90, -6590);
	}

	if (App->render->camera.y == 13150) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 194, -6610);
	}

	if (App->render->camera.y == 13180) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 0, -6620);
	}

	if (App->render->camera.y == 13210) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 112, -6630);
	}

	if (App->render->camera.y == 13240) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 30, -6640);
	}

	if (App->render->camera.y == 13260) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 194, -6650);
	}

	if (App->render->camera.y == 13280) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 10, -6660);
	}

	if (App->render->camera.y == 13300) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 122, -6680);
	}

	if (App->render->camera.y == 13310) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 30, -6700);
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 184, -6700);
	}

	if (App->render->camera.y == 13330) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 60, -6720);
	}

	if (App->render->camera.y == 13340) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 90, -6735);
	}

	if (App->render->camera.y == 13350) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 194, -6750);
	}

	if (App->render->camera.y == 13380) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 0, -6770);
	}

	if (App->render->camera.y == 13410) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 112, -6780);
	}

	if (App->render->camera.y == 13440) {
		App->enemies->AddEnemy(ENEMY_TYPES::VERTICALBOMB, 30, -6790);
	}
	/*

	if (App->render->camera.y == 9100) {
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 90, -4554);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 60, -4574);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 30, -4594);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB, 1, -4614);

		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 102, -4554);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 132, -4574);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 162, -4594);
		App->enemies->AddEnemy(ENEMY_TYPES::BOMB2, 192, -4614);

	}
	*/





	return UPDATE_CONTINUE;
}