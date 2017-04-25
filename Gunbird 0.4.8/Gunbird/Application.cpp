#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleMine.h"
#include "ModuleWelcome.h"
#include "ModuleCongrats.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

Application::Application()
{

	
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = fonts = new ModuleFonts();
	modules[5] = welcome = new ModuleWelcome();
	modules[6] = mine = new ModuleMine();
	modules[7] = congrats = new ModuleCongrats();
	modules[8] = enemies = new ModuleEnemies();
	modules[9] = player = new ModulePlayer();
	modules[10] = player2 = new ModulePlayer2();
	modules[11] = particles = new ModuleParticles();
	modules[12] = collision = new ModuleCollision();
	modules[13] = audio = new ModuleAudio();
	modules[14] = fade = new ModuleFadeToBlack();


}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	mine->Disable();
	congrats->Disable();
	player->Disable();
	player2->Disable();
	collision->Disable();
	enemies->Disable();
	//particles->Disable(); //diferente en handouts

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i) {
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;
		
	}

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;
	return ret;
}