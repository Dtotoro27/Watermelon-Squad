#include "Application.h"
#include "Enemy_FlyingMachine4.h"
#include "ModuleCollision.h"



Enemy_FlyingMachine4::Enemy_FlyingMachine4(int x, int y) : Enemy(x, y)
{
	enemy_position.PushBack({ 626,105,32,34 });
	enemy_position.speed = 0.2f;
	animation = &enemy_position;


	fly.PushBack({ 531,154,32,32 });
	fly.PushBack({ 568,152,32,32 });
	fly.PushBack({ 601,152,32,32 });
	fly.PushBack({ 638,151,32,32 });
	fly.PushBack({ 684,152,32,32 });
	fly.PushBack({ 737,153,32,32 });

	fly.speed = 0.2f;
	animation2 = &fly;



	collider = App->collision->AddCollider({ 0, 0,26,26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	movement.PushBack({ 0.0f,-0.775f }, 250, &enemy_position);
	movement.PushBack({ -0.1f,-0.1f }, 650, &enemy_position);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine4::Move()
{

	position = originalpos + movement.GetCurrentPosition();

}