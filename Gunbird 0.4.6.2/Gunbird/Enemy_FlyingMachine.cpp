#include "Application.h"
#include "Enemy_FlyingMachine.h"
#include "ModuleCollision.h"



Enemy_FlyingMachine::Enemy_FlyingMachine(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 470,21,28,29});
	fly.speed = 0.2f;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 28,29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	movement.PushBack({ 0.0f,-1.0f }, 50, &fly);
	
	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_FlyingMachine::Move()
{

	
	position = originalpos + movement.GetCurrentPosition();

}
