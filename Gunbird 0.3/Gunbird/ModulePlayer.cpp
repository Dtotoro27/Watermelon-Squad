#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"


ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

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

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ash.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 5;
	position.y -= 1;

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &right;
		if (position.x < SCREEN_WIDTH - ASH_WIDTH) {
			position.x += speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
			current_animation = &left;
			if (position.x > 0) {
				position.x -= speed;
			}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		
			position.y += speed;
		}
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x+4, position.y-40);
	}


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}