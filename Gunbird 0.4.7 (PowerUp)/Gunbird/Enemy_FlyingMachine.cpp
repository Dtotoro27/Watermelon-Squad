#include "Application.h"
#include "Enemy_FlyingMachine.h"
#include "ModuleCollision.h"



Enemy_FlyingMachine::Enemy_FlyingMachine(int x, int y) : Enemy(x, y)
{
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

	movement.PushBack({ 0.0f,-1.0f }, 50, &enemy_position);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine::Move()
{

	position = originalpos + movement.GetCurrentPosition();

}
