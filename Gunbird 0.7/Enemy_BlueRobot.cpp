#include "Application.h"
#include "Enemy_BlueRobot.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_BlueRobot::Enemy_BlueRobot(int x, int y) : Enemy(x, y)
{
	robot.PushBack({ 275,82,63,63 });
	robot.PushBack({ 343,81,74,71 });
	robot.PushBack({ 275,82,63,63 });
	robot.PushBack({ 421,82,70,66 });

	robot.speed = 0.2f;
	animation = &robot;

	movement.PushBack({ 1.0f,-0.775f }, 75, &robot);
	movement.PushBack({ 0.25f,-0.775f }, 75, &robot);
	movement.PushBack({ 0,-0.775f }, 150, &robot);
	movement.PushBack({ 0.25f,-0.775f }, 75, &robot);
	movement.PushBack({ 1.0f,-0.775f }, 75000, &robot);


	collider = App->collision->AddCollider({ 0, 0, 63, 63 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_BlueRobot::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_BlueRobot::Shoot() {
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