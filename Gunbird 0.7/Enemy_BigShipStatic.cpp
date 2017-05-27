#include "Application.h"
#include "Enemy_BigShipStatic.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_BigShipStatic::Enemy_BigShipStatic(int x, int y) : Enemy(x, y)
{
	base.PushBack({ 6,382,64,112 });
	base.speed = 0.2;


	shootopen.PushBack({ 76,373,51,68 });
	shootopen.PushBack({ 129,373,51,68 });
	shootopen.PushBack({ 182,373,51,68 });
	shootopen.PushBack({ 76,443,51,68 });
	shootopen.PushBack({ 129,443,51,68 });
	shootopen.speed = 0.1;
	shootopen.loop = false;

	shootclose.PushBack({ 129,443,51,68 });
	shootclose.PushBack({ 76,443,51,68 });
	shootclose.PushBack({ 182,373,51,68 });
	shootclose.PushBack({ 129,373,51,68 });
	shootclose.PushBack({ 76,373,51,68 });
	shootclose.speed = 0.1;
	shootclose.loop = false;


	animation = &base;

	movement.PushBack({ 0.0f,-0.825f }, 50, &base);
	movement.PushBack({ 0.0f,-0.715f }, 50, &base);

	collider = App->collision->AddCollider({ 0, 0, 63, 63 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 1;
	hitpoints = 60;
	score = 1000;
}

void Enemy_BigShipStatic::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_BigShipStatic::Shoot() {
	if (App->sea->pause == false) {

		if (position.x < SCREEN_WIDTH && position.x > 0) {
			pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
			pos_y = App->player->position.y - position.y;
			module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
			v_x = 4 * (pos_x / module);
			v_y = (4 * (pos_y / module) - 1.88f);
			if (timer == 150) {
				animation8 = &shootopen;
				timer++;
			}
			if (timer > 190) {
				if (timer == 200) {
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 28, position.y + 49, v_x-0.5f , v_y , COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 28, position.y + 42, v_x + 0.5f, v_y, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 28, position.y + 49, v_x -0.5f, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 28, position.y + 42, v_x+0.5f, v_y, COLLIDER_ENEMY_SHOT);

					timer++;
				}

				if (timer == 210) {
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 28, position.y + 49, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 14, position.y + 49, v_x, v_y, COLLIDER_ENEMY_SHOT);
					timer++;
				}
				if (timer == 220) {
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 28, position.y + 49, v_x - 0.5f, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 28, position.y + 42, v_x + 0.5f, v_y, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 28, position.y + 49, v_x - 0.5f, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 28, position.y + 42, v_x + 0.5f, v_y, COLLIDER_ENEMY_SHOT);

					timer++;
				}
				if (timer == 230) {
					App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 28, position.y + 42, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 14, position.y + 42, v_x, v_y, COLLIDER_ENEMY_SHOT);
					timer++;
				}
					if (timer == 240) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 31, position.y + 75, 0, 3, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 45, position.y + 70, 3, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 16, position.y + 70, -3, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 45, position.y + 25, 2,-2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 16, position.y + 25,-2,-2, COLLIDER_ENEMY_SHOT);

				
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
				animation8 = &shootclose;
				timer++;
			}
			if (timer == 300) {
				animation8 = nullptr;
			}
		}
	}
}