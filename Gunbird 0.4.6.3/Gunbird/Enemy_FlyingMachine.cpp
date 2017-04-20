#include "Application.h"
#include "Enemy_FlyingMachine.h"
#include "ModuleCollision.h"



Enemy_FlyingMachine::Enemy_FlyingMachine(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 470,21,26,29});
	fly.PushBack({ 518,17,26,35 });
	fly.PushBack({ 566,20,26,33 });
	fly.PushBack({ 621,24,28,28 });
	fly.PushBack({ 512,77,32,26 });
	fly.PushBack({ 567,70,26,34 });
	fly.PushBack({ 623,70,26,35 });
	fly.speed = 0.2f;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 32,35 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	movement.PushBack({ 0.0f,-1.0f }, 50, &fly);
	
	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine::Move()
{

	
	position = originalpos + movement.GetCurrentPosition();

}
