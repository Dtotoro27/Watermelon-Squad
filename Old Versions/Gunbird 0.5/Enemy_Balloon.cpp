#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 26,17,42,53 });
	fly.PushBack({ 79,17,42,53 });
	fly.PushBack({ 131,17,42,53 });
	fly.PushBack({ 183,17,42,53 });
	fly.PushBack({ 234,17,42,53 });

	fly.speed = 0.2f;
	animation = &fly;


	movement.PushBack({ 0.0f,-1.0f }, 350, &fly);
	/*movement.PushBack({ 0.0f,-0.5f }, 175, &fly);
	movement.PushBack({ 0.0f,-1.0f }, 650, &fly);
	movement.PushBack({ 0.0f,-0.35f }, 1000, &fly);*/

	collider = App->collision->AddCollider({ 0, 0, 42,53 }, COLLIDER_TYPE::COLLIDER_BALLOON, (Module*)App->enemies);


	start_time = SDL_GetTicks();
	originalpos.x = x;
	originalpos.y = y;

}

void Enemy_Balloon::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}

}


void Enemy_Balloon::Shoot() {
	if (App->sea->pause == false) {
		now = SDL_GetTicks() - start_time;
		if (now > 3000) {
			pos_x = (App->player->position.x + (ASH_WIDTH / 2)) - position.x;
			pos_y = App->player->position.y - position.y;
			module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
			v_x = 3 * (pos_x / module);
			v_y = 3 * (pos_y / module);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, v_x, v_y - 1.5f, COLLIDER_ENEMY_SHOT);
			start_time = SDL_GetTicks();
		}
	}
}
