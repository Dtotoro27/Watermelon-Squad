#include "Application.h"
#include "Enemy_FlyingMachine4.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>

#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)



Enemy_FlyingMachine4::Enemy_FlyingMachine4(int x, int y) : Enemy(x, y)
{
	enemy_position_s.PushBack({ 629,105,32,34 });
	enemy_position_s.speed = 0.2f;

	enemy_position_sa.PushBack({ 551,116,32,34 });
	enemy_position_sa.speed = 0.2f;

	enemy_position_a.PushBack({ 628,79,32,34 });
	enemy_position_a.speed = 0.2f;

	enemy_position_wa.PushBack({ 551,81,32,34 });
	enemy_position_wa.speed = 0.2f;

	enemy_position_w.PushBack({ 630,44,32,34 });
	enemy_position_w.speed = 0.2f;

	enemy_position_wd.PushBack({ 557,44,32,34 });
	enemy_position_wd.speed = 0.2f;

	enemy_position_d.PushBack({ 632,10,32,34 });
	enemy_position_d.speed = 0.2f;

	enemy_position_sd.PushBack({ 559,12,32,34 });
	enemy_position_sd.speed = 0.2f;

	fly.PushBack({ 533,154,32,32 });
	fly.PushBack({ 570,152,32,32 });
	fly.PushBack({ 603,152,32,32 });
	fly.PushBack({ 640,151,32,32 });
	fly.PushBack({ 686,152,32,32 });
	fly.PushBack({ 739,153,32,32 });

	fly.speed = 0.5f;
	animation2 = &fly;





	collider = App->collision->AddCollider({ 0, 0,26,33 }, COLLIDER_TYPE::COLLIDER_FLYING_ENEMY, (Module*)App->enemies);

	movement.PushBack({ 0.0f, 0.35f }, 125, &enemy_position_s);
	movement.PushBack({ 0.0f, -0.3f }, 40, &enemy_position_s);
	movement.PushBack({ 0.7f,-1.85f }, 10000, &enemy_position_s);


	originalpos.x = x;
	originalpos.y = y;

	enemy = 5;
	hitpoints = 0;
	score = 200;
}

void Enemy_FlyingMachine4::Move()
{
	bool left;
	float angle;


	if (App->player->position.x >= position.x) {
		left = false;
	}
	else {
		left = true;
	}

	angle = ((float)acos((((App->player->position.x - position.x) * 0) + ((App->player->position.y - position.y) * 1)) / (sqrt((double)((App->player->position.x - position.x)*(App->player->position.x - position.x) + (App->player->position.y - position.y)*(App->player->position.y - position.y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;
	if (left == false) {
		if (angle < 22.5) {
			animation = &enemy_position_s;
		}
		else if (angle >= 22.5 && angle < 67.5) {
			animation = &enemy_position_sd;
		}

		else if (angle >= 67.5 && angle < 112.5) {
			animation = &enemy_position_d;
		}
		else if (angle >= 112.5 && angle < 157.5) {
			animation = &enemy_position_wd;
		}
		else if (angle >= 157.5) {
			animation = &enemy_position_w;
		}
	}
	//Left

	else {
		if (angle < 22.5) {
			animation = &enemy_position_s;
		}

		else if (angle >= 22.5 && angle < 67.5) {
			animation = &enemy_position_sa;
		}

		else if (angle >= 67.5 && angle < 112.5) {
			animation = &enemy_position_a;
		}

		else if (angle >= 112.5 && angle < 157.5) {
			animation = &enemy_position_wa;
		}

		else if (angle >= 157.5) {
			animation = &enemy_position_w;
		}

	}
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_FlyingMachine4::Shoot() {

	if (App->sea->pause == false) {
		now = SDL_GetTicks() - start_time;
		if (now > 3000) {
			pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
			pos_y = App->player->position.y - position.y;
			module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
			v_x = 4 * (pos_x / module);

			if (position.y >= App->player->position.y) {
				v_y = (4 * (pos_y / module) - 1.88f);
			}

			else {
				v_y = (4 * (pos_y / module) + 1.88f);
			}


			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
			start_time = SDL_GetTicks();

		}
	}
}