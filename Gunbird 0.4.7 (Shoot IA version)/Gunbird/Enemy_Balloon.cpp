#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
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


	movement.PushBack({ 0.0f,-1.0f }, 350, &fly);
	movement.PushBack({ 0.0f,-0.5f }, 175, &fly);
	movement.PushBack({ 0.0f,-1.0f }, 650, &fly);
	movement.PushBack({ 0.0f,-0.35f }, 1000, &fly);

	collider = App->collision->AddCollider({ 0, 0, 42,53 }, COLLIDER_TYPE::COLLIDER_BALLOON, (Module*)App->enemies);


	start_time = SDL_GetTicks();
	originalpos.x = x;
	originalpos.y = y;

}

void Enemy_Balloon::Move()
{
	position = originalpos + movement.GetCurrentPosition();
 
}

void Enemy_Balloon::Shoot() {

	now = SDL_GetTicks() - start_time;
	if (now > shoots * 1000) {
		shootspeed_x = App->player->position.x - position.x;
		shootspeed_y = App->player->position.y - position.y;
		shootspeed_x = shootspeed_x / sqrt(pow(2,shootspeed_x) + pow(2,shootspeed_y));
		shootspeed_y = shootspeed_y / sqrt(pow(2, shootspeed_x) + pow(2, shootspeed_y));
		App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, shootspeed_x*4, shootspeed_y*4, COLLIDER_ENEMY_SHOT);
		shoots++;
	}

}
