#include "Application.h"
#include "Enemy_BlueRobot2.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_BlueRobot2::Enemy_BlueRobot2(int x, int y) : Enemy(x, y)
{
	robot.PushBack({ 269,82,74,69 });
	robot.PushBack({ 419,82,74,69 });
	robot.PushBack({ 269,82,74,69 });
	robot.PushBack({ 193,133,74,69 });
	robot.PushBack({ 269,82,74,69 });
	robot.PushBack({ 343,82,74,69 });
	robot.speed = 0.2;


	shootopen.PushBack({ 415,191,60,29 });
	shootopen.PushBack({ 345,191,60,29 });
	shootopen.PushBack({ 275,191,60,29 });
	shootopen.PushBack({ 415,157,60,29 });
	shootopen.PushBack({ 345,157,60,29 });
	shootopen.PushBack({ 275,157,60,29 });
	shootopen.speed = 0.1;
	shootopen.loop = false;

	shootclose.PushBack({ 275,157,60,29 });
	shootclose.PushBack({ 345,157,60,29 });
	shootclose.PushBack({ 415,157,60,29 });
	shootclose.PushBack({ 275,191,60,29 });
	shootclose.PushBack({ 345,191,60,29 });
	shootclose.PushBack({ 415,191,60,29 });
	shootclose.speed = 0.1;
	shootclose.loop = false;


	animation = &robot;

	movement.PushBack({ -1.5f,-1 }, 85, &robot);
	movement.PushBack({ -0.5f,-1 }, 65, &robot);
	movement.PushBack({ 0,-1 }, 150, &robot);
	movement.PushBack({ -0.5f,-1 }, 75, &robot);
	movement.PushBack({ -1.5f,-1 }, 75000, &robot);


	collider = App->collision->AddCollider({ 0, 0, 63, 63 }, COLLIDER_TYPE::COLLIDER_FLYING_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 2;
	hitpoints = 92;
	score = 5400;
}



void Enemy_BlueRobot2::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_BlueRobot2::Shoot() {
	if (App->sea->pause == false) {

		if (position.x < SCREEN_WIDTH && position.x > 0) {
			pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
			pos_y = App->player->position.y - position.y;
			module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
			v_x = 4 * (pos_x / module);
			v_y = (4 * (pos_y / module) - 1.88f);
			if (timer == 150) {
				animation6 = &shootopen;
				timer++;
			}
			if (timer > 190) {
				if (timer == 200) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 54, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 54, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 54, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 8, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 8, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 8, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 54, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 54, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 54, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 8, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 8, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 8, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					timer++;
				}

				if (timer == 210) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 60, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 60, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 60, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 14, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 14, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 14, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 60, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 60, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 60, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 14, position.y + 16, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 14, position.y + 16, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 14, position.y + 16, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					timer++;
				}
				if (timer == 220) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 20, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 20, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 20, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 11, position.y + 20, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 11, position.y + 20, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 11, position.y + 20, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 20, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 20, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 20, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 11, position.y + 20, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 11, position.y + 20, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 11, position.y + 20, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					timer++;
				}
				if (timer == 230) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 54, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 54, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 54, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 8, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 8, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 8, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 54, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 54, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 54, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 8, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 8, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 8, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					timer++;
				}
				if (timer == 240) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 60, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 60, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 60, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 14, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 14, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 14, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 60, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 60, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 60, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 14, position.y + 24, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 14, position.y + 24, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 14, position.y + 24, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					timer++;
				}
				if (timer == 260) {
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 31, position.y + 51, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 31, position.y + 51, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 29, position.y + 49, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 29, position.y + 49, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					timer++;
				}
				if (timer == 269) {
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 31, position.y + 51, v_x + 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 31, position.y + 51, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 29, position.y + 49, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 29, position.y + 49, v_x - 1, v_y + 1, COLLIDER_ENEMY_SHOT);

					timer++;
				}


				else {
					timer++;
				}
			}

			else {
				timer++;
			}
			if (timer == 270) {
				animation6 = &shootclose;
				timer++;
			}
			if (timer == 300) {
				animation6 = nullptr;
			}
		}
	}
}