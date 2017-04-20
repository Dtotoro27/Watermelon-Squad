#include "Application.h"
#include "Enemy_Turret.h"
#include "ModuleCollision.h"



Enemy_Turret::Enemy_Turret(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 470,171,28,41 });
	fly.speed = 0.2f;
	animation = &fly;

	movement.PushBack({ 0.0f,-0.78f }, 50, &fly);
	
	collider = App->collision->AddCollider({ 0, 0, 28,41 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_Turret::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}
