#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSea.h"
#include "ModuleWelcome.h"
#include "ModuleBoss.h"
#include "ModuleCongrats.h"
#include "ModuleCharacterSelect.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleUI.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

Application::Application()
{

	int i=0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = welcome = new ModuleWelcome();
	modules[i++] = characterselect = new ModuleCharacterSelect();
	modules[i++] = sea = new ModuleSea();
	modules[i++] = boss = new ModuleBoss();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = congrats = new ModuleCongrats();
	modules[i++] = ui = new ModuleUI();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = fade = new ModuleFadeToBlack();


}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	sea->Disable();
	ui->Disable();
	characterselect->Disable();
	congrats->Disable();
	boss->Disable();
	player->Disable();
	player2->Disable();
	collision->Disable();
	enemies->Disable();
	particles->Disable(); //diferente en handouts

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