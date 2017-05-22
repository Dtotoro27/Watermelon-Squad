#include "Application.h"
#include "Enemy_Tower.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_Tower::Enemy_Tower(int x, int y) : Enemy(x, y)
{
	stand.PushBack({ 5,259,64,100});
	stand.PushBack({ 70,259,64,100 });
	stand.PushBack({ 135,259,64,100 });
	stand.PushBack({ 200,259,64,100 });
	stand.PushBack({ 265,259,64,100 });
	stand.PushBack({ 330,259,64,100 });
	stand.PushBack({ 330,259,64,100 });
	stand.PushBack({ 330,259,64,100 });
	stand.PushBack({ 265,259,64,100 });
	stand.PushBack({ 200,259,64,100 });
	stand.PushBack({ 135,259,64,100 });
	stand.PushBack({ 70,259,64,100 });
	stand.PushBack({ 5,259,64,100 });
	stand.PushBack({ 5,259,64,100 });

	stand.speed = 0.1f;
	animation = &stand;


	movement.PushBack({ 0.0f,-0.88f },350, &stand);


	collider = App->collision->AddCollider({ 0, 0, 64,100 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_Tower::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_Tower::Shoot() {
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