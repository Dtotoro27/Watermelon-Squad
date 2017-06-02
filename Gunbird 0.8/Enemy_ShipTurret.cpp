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

	turret1.PushBack({ 419,426,39,40 });
	turret2.PushBack({ 458,426,39,40 });
	turret3.PushBack({ 497,426,39,40 });
	turret4.PushBack({ 536,426,39,40 });
	turret5.PushBack({ 575,426,39,40 });
	turret6.PushBack({ 614,426,39,40 });
	turret7.PushBack({ 653,426,39,40 });
	turret8.PushBack({ 692,426,39,40 });
	turret9.PushBack({ 419,467,39,40 });
	turret10.PushBack({ 458,467,39,40 });
	turret11.PushBack({ 497,467,39,40 });
	turret12.PushBack({ 536,467,39,40 });
	turret13.PushBack({ 575,467,39,40 });
	turret14.PushBack({ 614,467,39,40 });
	turret15.PushBack({ 653,467,39,40 });
	turret16.PushBack({ 692,467,39,40 });
	turret17.PushBack({ 419,508,39,40 });
	turret18.PushBack({ 458,508,39,40 });
	turret19.PushBack({ 497,508,39,40 });
	turret20.PushBack({ 536,508,39,40 });
	turret21.PushBack({ 575,508,39,40 });
	turret22.PushBack({ 614,508,39,40 });
	turret23.PushBack({ 653,508,39,40 });
	turret24.PushBack({ 692,508,39,40 });
	turret25.PushBack({ 419,549,39,40 });
	turret26.PushBack({ 458,549,39,40 });
	turret27.PushBack({ 497,549,39,40 });
	turret28.PushBack({ 536,549,39,40 });
	turret29.PushBack({ 575,549,39,40 });


	animation = &turret1;

	movement.PushBack({ 0.3f,-1.0f }, 75, &turret1);
	movement.PushBack({ 0.0f,-1.0f }, 40, &turret1);
	movement.PushBack({ -0.3f,-1.0f }, 75, &turret1);
	movement.PushBack({ 0.0f,-1.0f }, 40, &turret1);

	collider = App->collision->AddCollider({ 0, 0,39,40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 12;
	hitpoints = 30;
	score = 800;

}

void Enemy_ShipTurret::Move()
{
	if (App->sea->pause == false) {
		if (timer < 285) {
			originalpos.y++;
			timer++;
		}
		else {
		}
		position = originalpos + movement.GetCurrentPosition();
		if (App->collision->shipturret1 == true) {
			if (timer > 350 && timer < 490) {
				originalpos.y++;
				timer++;
			}
			else if (App->collision->shipturret2 == true) {
				originalpos.y++;
			}
			else {
				timer++;
			}
		}

	}

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
			animation = &turret1;
		}
		else if (angle >= 5.625 && angle < 16.875) {
			animation = &turret29;
		}
		else if (angle >= 16.875 && angle < 28.125) {
			animation = &turret29;
		}
		else if (angle >= 28.125 && angle < 39.375) {
			animation = &turret28;
		}
		else if (angle >= 39.375 && angle <50.625) {
			animation = &turret27;
		}
		else if (angle >= 50.625 && angle < 61.875) {
			animation = &turret26;
		}
		else if (angle >= 61.875 && angle < 73.125) {
			animation = &turret25;
		}
		else if (angle >= 73.125 && angle < 84.375) {
			animation = &turret24;
		}
		else if (angle >= 84.375 && angle < 95.625) {
			animation = &turret23;
		}
		else if (angle >= 95.625 && angle < 106.875) {
			animation = &turret22;
		}
		else if (angle >= 106.875&& angle < 118.125) {
			animation = &turret21;
		}
		else if (angle >= 118.125 && angle < 129.375) {
			animation = &turret20;
		}
		else if (angle >= 129.375 && angle < 140.625) {
			animation = &turret19;
		}
		else if (angle >= 140.625 && angle < 151.875) {
			animation = &turret18;
		}
		else if (angle >= 151.875 && angle < 163.125) {
			animation = &turret17;
		}
		else if (angle >= 163.125 && angle < 174.375) {
			animation = &turret16;
		}
		else if (angle >= 163.125 && angle <= 180) {
			animation = &turret16;
		}
	}
	//Left

	else {
		if (angle < 5.625) {
			animation = &turret1;
		}
		else if (angle >= 5.625 && angle < 16.875) {
			animation = &turret2;
		}
		else if (angle >= 16.875 && angle < 28.125) {
			animation = &turret3;
		}
		else if (angle >= 28.125 && angle < 39.375) {
			animation = &turret4;
		}
		else if (angle >= 39.375 && angle <50.625) {
			animation = &turret5;
		}
		else if (angle >= 50.625 && angle < 61.875) {
			animation = &turret6;
		}
		else if (angle >= 61.875 && angle < 73.125) {
			animation = &turret7;
		}
		else if (angle >= 73.125 && angle < 84.375) {
			animation = &turret8;
		}
		else if (angle >= 84.375 && angle < 95.625) {
			animation = &turret9;
		}
		else if (angle >= 95.625 && angle < 106.875) {
			animation = &turret10;
		}
		else if (angle >= 106.875&& angle < 118.125) {
			animation = &turret11;
		}
		else if (angle >= 118.125 && angle < 129.375) {
			animation = &turret12;
		}
		else if (angle >= 129.375 && angle < 140.625) {
			animation = &turret13;
		}
		else if (angle >= 140.625 && angle < 151.875) {
			animation = &turret14;
		}
		else if (angle >= 151.875 && angle < 163.125) {
			animation = &turret15;
		}
		else if (angle >= 163.125 && angle < 174.375) {
			animation = &turret16;
		}
		else if (angle >= 163.125 && angle <= 180) {
			animation = &turret16;
		}

	}
}

void Enemy_ShipTurret::Shoot() {
	if (App->sea->pause == false) {
		if (App->collision->shipturret1 == false) {
			now = SDL_GetTicks() - start_time;
			if (now > 5000) {
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
}