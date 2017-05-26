#include "Application.h"
#include "Enemy_BlueTurret.h"
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

Enemy_BlueTurret::Enemy_BlueTurret(int x, int y) : Enemy(x, y)
{
	live = 20;
	appear.PushBack({1000,0,18,29});
	appear.PushBack({ 1000,33,18,29 });
	appear.PushBack({ 1000,66,18,29 });
	appear.PushBack({ 1000,99,18,29 });
	appear.PushBack({ 1000,132,18,29 });
	appear.speed = 0.1;

	enemy_position_1.PushBack({ 782,119,30,32});
	enemy_position_2.PushBack({ 813,119,30,32 });
	enemy_position_3.PushBack({ 844,119,30,32 });
	enemy_position_4.PushBack({ 875,119,30,32 });
	enemy_position_5.PushBack({ 906,119,30,32 });
	enemy_position_6.PushBack({ 937,119,30,32 });
	enemy_position_7.PushBack({ 968,119,30,32 });

	enemy_position_8.PushBack({ 782,152,30,32 });
	enemy_position_9.PushBack({ 813,152,30,32 });
	enemy_position_10.PushBack({ 844,152,30,32 });
	enemy_position_11.PushBack({ 875,152,30,32 });
	enemy_position_12.PushBack({ 906,152,30,32 });
	enemy_position_13.PushBack({ 937,152,30,32 });
	enemy_position_14.PushBack({ 968,152,30,32 });

	enemy_position_15.PushBack({ 782,185,30,32 });
	enemy_position_16.PushBack({ 813,185,30,32 });
	enemy_position_17.PushBack({ 844,185,30,32 });
	enemy_position_18.PushBack({ 875,185,30,32 });
	enemy_position_19.PushBack({ 906,185,30,32 });
	enemy_position_20.PushBack({ 937,185,30,32 });
	enemy_position_21.PushBack({ 968,185,30,32 });

	enemy_position_22.PushBack({ 782,218,30,32 });
	enemy_position_23.PushBack({ 813,218,30,32 });
	enemy_position_24.PushBack({ 844,218,30,32 });
	enemy_position_25.PushBack({ 875,218,30,32 });
	enemy_position_26.PushBack({ 906,218,30,32 });
	enemy_position_27.PushBack({ 937,218,30,32 });
	enemy_position_28.PushBack({ 968,218,30,32 });


	enemy_position_29.PushBack({ 782,251,30,32 });
	enemy_position_30.PushBack({ 813,251,30,32 });
	enemy_position_31.PushBack({ 844,251,30,32 });
	enemy_position_32.PushBack({ 875,251,30,32 });


	movement.PushBack({ 0.0f,-0.782f }, 350, &appear);

	collider = App->collision->AddCollider({ 10, 0, 30, 27}, COLLIDER_TYPE::COLLIDER_SURFINGTURRET, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_BlueTurret::Move()
{
	/*if (App->player->position.x > 100) {
		animation = &appear;
	}*/
	
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
				animation = &enemy_position_1;
			}
			else if (angle >= 5.625 && angle < 16.875) {
				animation = &enemy_position_2;
			}
			else if (angle >= 16.875 && angle < 28.125) {
				animation = &enemy_position_3;
			}
			else if (angle >= 28.125 && angle < 39.375) {
				animation = &enemy_position_4;
			}
			else if (angle >= 39.375 && angle <50.625) {
				animation = &enemy_position_5;
			}
			else if (angle >= 50.625 && angle < 61.875) {
				animation = &enemy_position_6;
			}
			else if (angle >= 61.875 && angle < 73.125) {
				animation = &enemy_position_7;
			}
			else if (angle >= 73.125 && angle < 84.375) {
				animation = &enemy_position_8;
			}
			else if (angle >= 84.375 && angle < 95.625) {
				animation = &enemy_position_9;
			}
			else if (angle >= 95.625 && angle < 106.875) {
				animation = &enemy_position_10;
			}
			else if (angle >= 106.875&& angle < 118.125) {
				animation = &enemy_position_11;
			}
			else if (angle >= 118.125 && angle < 129.375) {
				animation = &enemy_position_12;
			}
			else if (angle >= 129.375 && angle < 140.625) {
				animation = &enemy_position_13;
			}
			else if (angle >= 140.625 && angle < 151.875) {
				animation = &enemy_position_14;
			}
			else if (angle >= 151.875 && angle < 163.125) {
				animation = &enemy_position_15;
			}
			else if (angle >= 163.125 && angle < 174.375) {
				animation = &enemy_position_16;
			}
			else if (angle >= 163.125 && angle <= 180) {
				animation = &enemy_position_17;
			}
		}
		//Left

		else {
			if (angle < 5.625) {
				animation = &enemy_position_1;
			}
			else if (angle >= 5.625 && angle < 16.875) {
				animation = &enemy_position_32;
			}
			else if (angle >= 16.875 && angle < 28.125) {
				animation = &enemy_position_31;
			}
			else if (angle >= 28.125 && angle < 39.375) {
				animation = &enemy_position_30;
			}
			else if (angle >= 39.375 && angle <50.625) {
				animation = &enemy_position_29;
			}
			else if (angle >= 50.625 && angle < 61.875) {
				animation = &enemy_position_28;
			}
			else if (angle >= 61.875 && angle < 73.125) {
				animation = &enemy_position_27;
			}
			else if (angle >= 73.125 && angle < 84.375) {
				animation = &enemy_position_26;
			}
			else if (angle >= 84.375 && angle < 95.625) {
				animation = &enemy_position_25;
			}
			else if (angle >= 95.625 && angle < 106.875) {
				animation = &enemy_position_24;
			}
			else if (angle >= 106.875&& angle < 118.125) {
				animation = &enemy_position_23;
			}
			else if (angle >= 118.125 && angle < 129.375) {
				animation = &enemy_position_22;
			}
			else if (angle >= 129.375 && angle < 140.625) {
				animation = &enemy_position_21;
			}
			else if (angle >= 140.625 && angle < 151.875) {
				animation = &enemy_position_20;
			}
			else if (angle >= 151.875 && angle < 163.125) {
				animation = &enemy_position_19;
			}
			else if (angle >= 163.125 && angle < 174.375) {
				animation = &enemy_position_18;
			}
			else if (angle >= 163.125 && angle <= 180) {
				animation = &enemy_position_17;
			}

		}
	
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_BlueTurret::Shoot() {
	if (App->sea->pause == false) {

			now = SDL_GetTicks() - start_time;
			if (now > 3000) {
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