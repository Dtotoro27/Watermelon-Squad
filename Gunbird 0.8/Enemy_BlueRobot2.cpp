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

	movement.PushBack({ -1.5f,-1 }, 55, &robot);
	movement.PushBack({ -0.5f,-1 }, 65, &robot);
	movement.PushBack({ 0,-1 }, 150, &robot);
	movement.PushBack({ -0.5f,-1 }, 75, &robot);
	movement.PushBack({ -1.5f,-1 }, 75000, &robot);


	collider = App->collision->AddCollider({ 0, 0, 63, 63 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

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
		now = SDL_GetTicks() - start_time;
		if (now > 3000) {
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, -0.5f, -1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, -1, -1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, 0, 0, COLLIDER_ENEMY_SHOT);



			start_time = SDL_GetTicks();
		}
	}
}