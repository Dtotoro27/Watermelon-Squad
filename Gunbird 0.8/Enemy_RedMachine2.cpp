#include "Application.h"
#include "Enemy_RedMachine2.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_RedMachine2::Enemy_RedMachine2(int x, int y) : Enemy(x, y)
{
	machine.PushBack({ 766,287,26,36 });

	machine.speed = 0.2f;
	animation = &machine;

	movement.PushBack({ -0.9f,-0.775f }, 100, &machine);
	movement.PushBack({ 0,-0.775f }, 150, &machine);
	movement.PushBack({ 0.9f,-0.775f }, 10000, &machine);

	collider = App->collision->AddCollider({ 0, 0, 26, 36 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 6;
	hitpoints = 8;
	score = 400;
}

void Enemy_RedMachine2::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_RedMachine2::Shoot() {

	if (App->sea->pause == false) {
		now = SDL_GetTicks() - start_time;
		if (now > 6000) {
			if (shoots<2)
				shooting = true;
		}
		if (now > 1000) {
			if (shooting && shoots < 2) {
				pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
				pos_y = App->player->position.y - position.y;
				module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
				v_x = 3 * (pos_x / module);

				if (position.y >= App->player->position.y) {
					v_y = (3 * (pos_y / module) - 1.88f);
				}

				else {
					v_y = (3 * (pos_y / module) + 1.88f);
				}


				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
				start_time = SDL_GetTicks();
				shoots++;
			}
		}
	}
}