#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{

	

	fly.PushBack({ 26,17,42,53 });
	fly.PushBack({ 79,17,42,53 });
	fly.PushBack({ 131,17,42,53 });
	fly.PushBack({ 183,17,42,53 });
	fly.PushBack({ 234,17,42,53 });

	fly.speed = 0.2f;
	animation = &fly;


	movement.PushBack({ 0.0f,-0.2f }, 70, &fly);
	movement.PushBack({ 0.0f,-1.0f }, 100, &fly);
	movement.PushBack({ 0.0f,-0.2f }, 120, &fly);
	movement.PushBack({ 0.0f,-1.0f }, 100, &fly);
	movement.PushBack({ 0.0f,-0.2f }, 15000, &fly);
	

	collider = App->collision->AddCollider({ 0, 0, 42,53 }, COLLIDER_TYPE::COLLIDER_FLYING_ENEMY, (Module*)App->enemies);

	start_time = SDL_GetTicks();
	originalpos.x = x;
	originalpos.y = y;

	enemy = 0;
	hitpoints = 25;
	score = 500;

}

void Enemy_Balloon::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}

}


void Enemy_Balloon::Shoot() {
	if (App->sea->pause == false) {
		now = SDL_GetTicks() - start_time;
		if (now > 3000) {
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, 2, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, -2, 1, COLLIDER_ENEMY_SHOT);
			start_time = SDL_GetTicks();

		}
	}

}

