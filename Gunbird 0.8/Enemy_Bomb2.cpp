#include "Application.h"
#include "Enemy_Bomb2.h"
#include "ModuleCollision.h"



Enemy_Bomb2::Enemy_Bomb2(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 790,24,28,32 });
	fly.PushBack({ 819,24,28,32 });
	fly.PushBack({ 849,24,28,32 });
	fly.PushBack({ 882,24,28,32 });
	fly.PushBack({ 795,61,28,32 });
	fly.PushBack({ 831,61,28,32 });
	fly.PushBack({ 867,61,28,32 });
	fly.PushBack({ 897,61,28,32 });

	hitpoints = 5;

	fly.speed = 0.1f;
	animation = &fly;

	movement.PushBack({ -2.0f, -1.0f }, 50, &fly);
	movement.PushBack({ 0.0f, -1.0f }, 25, &fly);
	movement.PushBack({ 0.0f, 2.5f }, 25000, &fly);

	collider = App->collision->AddCollider({ 0, 0, 26,24 }, COLLIDER_TYPE::COLLIDER_FLYING_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 4;
	hitpoints = 5;
	score = 200;

}

void Enemy_Bomb2::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}