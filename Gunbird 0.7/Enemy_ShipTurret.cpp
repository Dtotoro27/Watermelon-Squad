#include "Application.h"
#include "Enemy_ShipTurret.h"
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



Enemy_ShipTurret::Enemy_ShipTurret(int x, int y) : Enemy(x, y)
{
	enemy_position_s.PushBack({ 497,423,33,37 });
	enemy_position_s.speed = 0.2f;

	enemy_position_sa.PushBack({ 497,423,33,37 });
	enemy_position_sa.speed = 0.2f;

	enemy_position_a.PushBack({ 497,423,33,37 });
	enemy_position_a.speed = 0.2f;

	enemy_position_wa.PushBack({ 497,423,33,37 });
	enemy_position_wa.speed = 0.2f;

	enemy_position_w.PushBack({ 497,423,33,37 });
	enemy_position_w.speed = 0.2f;

	enemy_position_wd.PushBack({ 497,423,33,37 });
	enemy_position_wd.speed = 0.2f;

	enemy_position_d.PushBack({ 497,423,33,37 });
	enemy_position_d.speed = 0.2f;

	enemy_position_sd.PushBack({ 497,423,33,37 });
	enemy_position_sd.speed = 0.2f;




	collider = App->collision->AddCollider({ 0, 0,26,33 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	movement.PushBack({ 0.0f,-0.782f }, 100, &enemy_position_s);



	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_ShipTurret::Move()
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

void Enemy_ShipTurret::Shoot() {
	if (App->sea->pause == false) {

		now = SDL_GetTicks() - start_time;
		if (now >3000) {
			if (position.x < SCREEN_WIDTH && position.x > 0) {
				pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
				pos_y = App->player->position.y - position.y;
				module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
				v_x = 4 * (pos_x / module);
				v_y = (4 * (pos_y / module) - 1.88f);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 25, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 7, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
				start_time = SDL_GetTicks();

			}
		}
	}
}