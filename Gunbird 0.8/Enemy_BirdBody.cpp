#include "Application.h"
#include "Enemy_BirdBody.h"
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



Enemy_BirdBody::Enemy_BirdBody(int x, int y) : Enemy(x, y)
{


	enemypos.PushBack({ 326,657,245,150 });

	motor.PushBack({ 420,608,64,48 });
	motor.PushBack({ 486,608,64,48 });
	motor.PushBack({ 550,608,64,48 });
	motor.PushBack({ 486,608,64,48 });
	motor.speed = 0.2f;

	animation = &enemypos;
	animation13 = &motor;

	collider = App->collision->AddCollider({ 0, 0,37,120 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	movement.PushBack({ 0.0f,-1.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);
	movement.PushBack({ 0.0f,-0.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);


	originalpos.x = x;
	originalpos.y = y;

	enemy = 14;
	hitpoints = 373;
	score = 10000;

}

void Enemy_BirdBody::Move()
{
	if (App->sea->pause == false) {
		if (App->collision->shipturret2 == true) {
			if (timer > 300) {
			}
			else {
				originalpos.x++;
				timer++;
			}
		}
		position = originalpos + movement.GetCurrentPosition();

		if (left == true) {
			if (originalpos.x > -74 && timermove == 0) {
				originalpos.x--;
				if (originalpos.x == -74) {
					timermove = 1;
				}
			}

			else if (timermove > 0) {
				if (App->player->position.x < SCREEN_WIDTH / 2) {
					timermove++;
					if (timermove > 100) {
						left = false;
						right = true;
						timermove = 0;
					}
				}
			}
		}

		else if (right == true) {
			if (originalpos.x < 46 && timermove == 0) {
				originalpos.x++;
				if (originalpos.x == 46) {
					timermove = 1;
				}
			}
			else if (timermove > 0) {
				if (App->player->position.x > SCREEN_WIDTH / 2) {
					timermove++;
					if (timermove > 100) {
						right = false;
						left = true;
						timermove = 0;
					}
				}
			}
		}
	}
}


void Enemy_BirdBody::Shoot() {
	if (App->sea->pause == false) {
		pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
		pos_y = App->player->position.y - position.y;
		module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
		v_x = 4 * (pos_x / module);
		v_y = (4 * (pos_y / module) - 1.88f);

		if (App->collision->rwing == true) {
			if (timer2 == 300) {
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);

			}
			if (timer2 == 310) {
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
			}

			if (timer2 == 360) {
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x  + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
			}
			if (timer2 == 370) {
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 78, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 150, position.y + 65, v_x, v_y, COLLIDER_ENEMY_SHOT);
			}
			if (timer2 == 400) {
				timer2 = 0;
			}
			timer2++;
		}
	}
}
