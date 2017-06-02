#include "Application.h"
#include "Enemy_ShipVerticalCanon3.h"
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



Enemy_ShipVerticalCanon3::Enemy_ShipVerticalCanon3(int x, int y) : Enemy(x, y)
{


	enemypos.PushBack({ 51,877,18,32 });

	shootopen_right.PushBack({ 51,917,18,31 });
	shootopen_right.PushBack({ 51,954,18,31 });
	shootopen_right.PushBack({ 51,991,18,31 });
	shootopen_right.loop = false;
	shootopen_right.speed = 0.1f;

	shootclose_right.PushBack({ 51,992,18,31 });
	shootclose_right.PushBack({ 51,955,18,31 });
	shootclose_right.PushBack({ 51,918,18,31 });
	shootclose_right.loop = false;
	shootclose_right.speed = 0.1;

	shootopen_left.PushBack({ 124,918,18,31 });
	shootopen_left.PushBack({ 124,955,18,31 });
	shootopen_left.PushBack({ 124,992,18,31 });
	shootopen_left.loop = false;
	shootopen_left.speed = 0.1f;

	shootclose_left.PushBack({ 124,992,18,31 });
	shootclose_left.PushBack({ 124,955,18,31 });
	shootclose_left.PushBack({ 124,918,18,31 });
	shootclose_left.loop = false;
	shootclose_left.speed = 0.1f;

	animation = &enemypos;

	movement.PushBack({ 0.3f,-1.0f }, 75, &enemypos);
	movement.PushBack({ 0.0f,-1.0f }, 40, &enemypos);
	movement.PushBack({ -0.3f,-1.0f }, 75, &enemypos);
	movement.PushBack({ 0.0f,-1.0f }, 40, &enemypos);




	originalpos.x = x;
	originalpos.y = y;

	enemy = 13;
	hitpoints = 28;
	score = 2000;

}

void Enemy_ShipVerticalCanon3::Move()
{

	if (App->sea->pause == false) {
		if (timer2 < 285) {
			originalpos.y++;
			timer2++;
		}
		else {
		}
		position = originalpos + movement.GetCurrentPosition();

	}
}

void Enemy_ShipVerticalCanon3::Shoot() {
	if (App->sea->pause == false) {

		if (timer == 200) {
			collider = App->collision->AddCollider({ 0, 0,18,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
			if (App->player->position.x > position.x) {
				animation = &shootopen_right;
			}
			else {
				animation = &shootopen_left;
			}
			timer++;
		}
		if (timer == 250) {
			if (position.x < SCREEN_WIDTH && position.x > 0) {
				pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
				pos_y = App->player->position.y - position.y;
				module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
				v_x = 4 * (pos_x / module);
				v_y = (4 * (pos_y / module) - 1.88f);


				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 7, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 7, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
				timer++;
			}
		}
		if (timer == 300) {
			if (animation == &shootopen_left) {
				animation = &shootclose_left;
			}
			if (animation == &shootopen_right) {
				animation = &shootclose_right;
			}

			timer++;
		}
		if (timer == 330) {
			animation = &enemypos;
			timer = 0;
			App->collision->EraseCollider(collider);
		}
		else {
			timer++;
		}
	}
}