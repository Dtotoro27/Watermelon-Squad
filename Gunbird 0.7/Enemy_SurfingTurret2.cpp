#include "Application.h"
#include "Enemy_SurfingTurret2.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_SurfingTurret2::Enemy_SurfingTurret2(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 495,254,29,33 });


	fly.speed = 0.1f;
	animation = &fly;


	water.PushBack({ 9, 582,32,32 });
	water.PushBack({ 50, 582,32,32 });
	water.PushBack({ 87, 582,32,32 });
	water.PushBack({ 125, 582,32,32 });
	water.PushBack({ 163, 582,32,32 });
	water.PushBack({ 197, 582,32,32 });
	


	water.speed = 0.1f;
	animation4 = &water;


	movement.PushBack({ 1.0f,-0.775f }, 1250, &fly);


	collider = App->collision->AddCollider({ 0, 0, 29, 33 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_SurfingTurret2::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_SurfingTurret2::Shoot() {
	if (App->sea->pause == false) {
		now = SDL_GetTicks() - start_time;
		if (now > 3000) {
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, -0.5f, -1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, -1, -1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, 0, 0, COLLIDER_ENEMY_SHOT);



			start_time = SDL_GetTicks();
		}
	}
}