#include "Application.h"
#include "Enemy_FlyingMachine3.h"
#include "ModuleCollision.h"



Enemy_FlyingMachine3::Enemy_FlyingMachine3(int x, int y) : Enemy(x, y)
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

	movement.PushBack({ 0.0f,-0.775f }, 1350, &enemy_position);
	movement.PushBack({ 0.0f,-0.35f }, 225, &enemy_position);
	movement.PushBack({ 0.0f,-0.6f }, 50, &enemy_position);
	movement.PushBack({ 0.0f,-0.775f }, 100, &enemy_position);
	movement.PushBack({ 0.0f, -2.0f }, 10000, &enemy_position);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine3::Move()
{

	position = originalpos + movement.GetCurrentPosition();

}