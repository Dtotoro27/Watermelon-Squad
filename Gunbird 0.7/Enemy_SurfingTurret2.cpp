#include "Application.h"
#include "Enemy_SurfingTurret2.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>

#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)

Enemy_SurfingTurret2::Enemy_SurfingTurret2(int x, int y) : Enemy(x, y)
{
	live = 3;

	base.PushBack({ 711,357,30,30 });

	turret1.PushBack({ 494,257,30,32 });
	turret2.PushBack({ 525,257,30,32 });
	turret3.PushBack({ 556,257,30,32 });
	turret4.PushBack({ 587,257,30,32 });
	turret5.PushBack({ 618,257,30,32 });
	turret6.PushBack({ 649,257,30,32 });
	turret7.PushBack({ 680,257,30,32 });
	turret8.PushBack({ 711,257,30,32 });
	turret9.PushBack({ 494,290,30,32 });
	turret10.PushBack({ 525,290,30,32 });
	turret11.PushBack({ 556,290,30,32 });
	turret12.PushBack({ 587,290,30,32 });
	turret13.PushBack({ 618,290,30,32 });
	turret14.PushBack({ 649,290,30,32 });
	turret15.PushBack({ 680,290,30,32 });
	turret16.PushBack({ 711,290,30,32 });
	turret17.PushBack({ 494,323,30,32 });
	turret18.PushBack({ 525,323,30,32 });
	turret19.PushBack({ 556,323,30,32 });
	turret20.PushBack({ 587,323,30,32 });
	turret21.PushBack({ 618,323,30,32 });
	turret22.PushBack({ 649,323,30,32 });
	turret23.PushBack({ 680,323,30,32 });
	turret24.PushBack({ 711,323,30,32 });
	turret25.PushBack({ 494,356,30,32 });
	turret26.PushBack({ 525,356,30,32 });
	turret27.PushBack({ 556,356,30,32 });
	turret28.PushBack({ 587,356,30,32 });
	turret29.PushBack({ 618,356,30,32 });
	turret30.PushBack({ 649,356,30,32 });
	turret31.PushBack({ 680,356,30,32 });


	animation = &base;

	water.PushBack({ 9, 582,32,32 });
	water.PushBack({ 50, 582,32,32 });
	water.PushBack({ 87, 582,32,32 });
	water.PushBack({ 125, 582,32,32 });
	water.PushBack({ 163, 582,32,32 });
	water.PushBack({ 197, 582,32,32 });
	


	water.speed = 0.1f;
	animation4 = &water;


	movement.PushBack({ 1,-0.782f }, 1250, &base);


	collider = App->collision->AddCollider({ 0, 0, 26, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 7;
	live = 3;
	score = 500;
}

void Enemy_SurfingTurret2::Move()
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
		if (angle < 5.625) {
			animation5 = &turret31;
		}
		else if (angle >= 5.625 && angle < 16.875) {
			animation5 = &turret30;
		}
		else if (angle >= 16.875 && angle < 28.125) {
			animation5 = &turret29;
		}
		else if (angle >= 28.125 && angle < 39.375) {
			animation5 = &turret28;
		}
		else if (angle >= 39.375 && angle <50.625) {
			animation5 = &turret27;
		}
		else if (angle >= 50.625 && angle < 61.875) {
			animation5 = &turret26;
		}
		else if (angle >= 61.875 && angle < 73.125) {
			animation5 = &turret25;
		}
		else if (angle >= 73.125 && angle < 84.375) {
			animation5 = &turret24;
		}
		else if (angle >= 84.375 && angle < 95.625) {
			animation5 = &turret23;
		}
		else if (angle >= 95.625 && angle < 106.875) {
			animation5 = &turret22;
		}
		else if (angle >= 106.875&& angle < 118.125) {
			animation5 = &turret21;
		}
		else if (angle >= 118.125 && angle < 129.375) {
			animation5 = &turret20;
		}
		else if (angle >= 129.375 && angle < 140.625) {
			animation5 = &turret19;
		}
		else if (angle >= 140.625 && angle < 151.875) {
			animation5 = &turret18;
		}
		else if (angle >= 151.875 && angle < 163.125) {
			animation5 = &turret17;
		}
		else if (angle >= 163.125 && angle < 174.375) {
			animation5 = &turret16;
		}
		else if (angle >= 163.125 && angle <= 180) {
			animation5 = &turret16;
		}
	}
	//Left

	else {
		if (angle < 5.625) {
			animation5 = &turret1;
		}
		else if (angle >= 5.625 && angle < 16.875) {
			animation5 = &turret2;
		}
		else if (angle >= 16.875 && angle < 28.125) {
			animation5 = &turret3;
		}
		else if (angle >= 28.125 && angle < 39.375) {
			animation5 = &turret4;
		}
		else if (angle >= 39.375 && angle <50.625) {
			animation5 = &turret5;
		}
		else if (angle >= 50.625 && angle < 61.875) {
			animation5 = &turret6;
		}
		else if (angle >= 61.875 && angle < 73.125) {
			animation5 = &turret7;
		}
		else if (angle >= 73.125 && angle < 84.375) {
			animation5 = &turret8;
		}
		else if (angle >= 84.375 && angle < 95.625) {
			animation5 = &turret9;
		}
		else if (angle >= 95.625 && angle < 106.875) {
			animation5 = &turret10;
		}
		else if (angle >= 106.875&& angle < 118.125) {
			animation5 = &turret11;
		}
		else if (angle >= 118.125 && angle < 129.375) {
			animation5 = &turret12;
		}
		else if (angle >= 129.375 && angle < 140.625) {
			animation5 = &turret13;
		}
		else if (angle >= 140.625 && angle < 151.875) {
			animation5 = &turret14;
		}
		else if (angle >= 151.875 && angle < 163.125) {
			animation5 = &turret15;
		}
		else if (angle >= 163.125 && angle < 174.375) {
			animation5 = &turret16;
		}
		else if (angle >= 163.125 && angle <= 180) {
			animation5 = &turret16;
		}

	}

	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_SurfingTurret2::Shoot() {
	if (App->sea->pause == false) {

		now = SDL_GetTicks() - start_time;
		if (now > 3000) {
			if (position.x < SCREEN_WIDTH && position.x > 0) {
				pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
				pos_y = App->player->position.y - position.y;
				module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
				v_x = 4 * (pos_x / module);
				v_y = (4 * (pos_y / module) - 1.88f);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
				start_time = SDL_GetTicks();

			}
		}
	}
}