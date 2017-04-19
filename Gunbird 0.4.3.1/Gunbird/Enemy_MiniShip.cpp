#include "Application.h"
#include "Enemy_MiniShip.h"
#include "ModuleCollision.h"



Enemy_MiniShip::Enemy_MiniShip(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 320,6,41,52 });
	fly.speed = 0.2f;
	animation = &fly;

	movement.PushBack({ 0.0f,-1.0f }, 50, &fly);
	
	collider = App->collision->AddCollider({ 0, 0, 41,52 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_MiniShip::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}
