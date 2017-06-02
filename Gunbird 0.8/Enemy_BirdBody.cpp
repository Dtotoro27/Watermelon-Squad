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

	shootopen.PushBack({ 193,736,87,17 });
	shootopen.PushBack({ 193,758,87,17 });
	shootopen.PushBack({ 193,783,87,17 });
	shootclose.PushBack({ 193,807,87,17 });
	shootopen.loop = false;
	shootopen.speed = 0.1f;

	shootclose.PushBack({ 193,807,87,17 });
	shootclose.PushBack({ 193,783,87,17 });
	shootclose.PushBack({ 193,758,87,17 });
	shootclose.PushBack({ 193,736,87,17 });
	shootclose.loop = false;
	shootclose.speed = 0.1f;

	animation = &enemypos;
	animation13 = &motor;



	movement.PushBack({ 0.0f,-1.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);
	movement.PushBack({ 0.0f,-0.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);

	collider = App->collision->AddCollider({ 0, 0,37,80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	originalpos.x = x;
	originalpos.y = y;

	enemy = 14;
	hitpoints = 373;
	score = 10000;

}

void Enemy_BirdBody::Move()
{

	if (App->sea->pause == false) {
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
		pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x + 8;
		pos_y = App->player->position.y - position.y + 66;
		module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
		v_x = 4 * (pos_x / module);
		v_y = (4 * (pos_y / module) - 1.88f);

		if (timer == 400) {
			shootopen.current_frame = 0;
			animation12 = &shootopen;
		}
		if (timer == 410) {
			shootopen.loop = false;
			timer++;
		}
		if (timer == 450) {
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 83, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 8, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 80, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			timer++;

		}
		if (timer == 460) {
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 83, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 8, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 80, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			timer++;
		}

		if (timer == 490) {


			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 83, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 8, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 80, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			timer++;
		}
		if (timer == 500) {


			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 83, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 150, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 8, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 80, position.y + 66, v_x, v_y, COLLIDER_ENEMY_SHOT);
			timer++;
		}

		if (timer == 550) {
			shootclose.current_frame = 0;
			animation12 = &shootclose;
			timer++;
		}

		if (timer == 580) {
			timer = 0;
		}

		else {
			timer++;
		}
	}
}