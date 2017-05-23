#include "Application.h"
#include "Enemy_FlyingMachine4.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>



Enemy_FlyingMachine4::Enemy_FlyingMachine4(int x, int y) : Enemy(x, y)
{
	enemy_position.PushBack({ 629,105,32,34 });
	enemy_position.speed = 0.2f;
	animation = &enemy_position;


	fly.PushBack({ 531,154,32,32 });
	fly.PushBack({ 568,152,32,32 });
	fly.PushBack({ 601,152,32,32 });
	fly.PushBack({ 638,151,32,32 });
	fly.PushBack({ 684,152,32,32 });
	fly.PushBack({ 737,153,32,32 });

	fly.speed = 0.5f;
	animation2 = &fly;



	collider = App->collision->AddCollider({ 0, 0,26,33 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	movement.PushBack({ 0.0f,-0.775f }, 250, &enemy_position);
	movement.PushBack({ -0.15f,-0.1f }, 650, &enemy_position);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine4::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_FlyingMachine4::Shoot() {
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