#include "Application.h"
#include "Enemy_FlyingMachine.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>





Enemy_FlyingMachine::Enemy_FlyingMachine(int x, int y) : Enemy(x, y)
{
	enemy_position.PushBack({ 629,105,32,34 });
	enemy_position.speed = 0.2f;
	animation = &enemy_position;


	fly.PushBack({ 533,154,32,32 });
	fly.PushBack({ 570,152,32,32 });
	fly.PushBack({ 603,152,32,32 });
	fly.PushBack({ 640,151,32,32 });
	fly.PushBack({ 686,152,32,32 });
	fly.PushBack({ 739,153,32,32 });

	fly.speed = 0.5f;
	animation2 = &fly;



	collider = App->collision->AddCollider({ 0, 0,26,33 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	movement.PushBack({ 0.0f,-0.35f }, 225, &enemy_position);
	movement.PushBack({ 0.0f,-0.6f }, 50, &enemy_position);
	movement.PushBack({ 0.0f,-0.775f }, 100, &enemy_position);
	movement.PushBack({ 0.0f, -2.0f }, 10000, &enemy_position);


	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine::Move()
{

	position = originalpos + movement.GetCurrentPosition();

}

void Enemy_FlyingMachine::Shoot() {
	now = SDL_GetTicks() - start_time;
	if (now >  3000) {
		shootspeed_x = (App->player->position.x - (position.x));
		shootspeed_y = (App->player->position.y - (position.y));

		vmodule = sqrt((shootspeed_x*shootspeed_x) + (shootspeed_y*shootspeed_y));

		shootspeed_x_u = (shootspeed_x / vmodule) * 5;
		shootspeed_y_u = (shootspeed_y / vmodule) * 5;


		if (shootspeed_y_u >= 0 && now > 3000) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, shootspeed_x_u, shootspeed_y_u - 1.88f, COLLIDER_ENEMY_SHOT);
			start_time = SDL_GetTicks();
		}

	}

}
