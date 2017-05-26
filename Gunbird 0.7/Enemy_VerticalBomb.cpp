#include "Application.h"
#include "Enemy_VerticalBomb.h"
#include "ModuleSea.h"
#include "ModuleCollision.h"



Enemy_VerticalBomb::Enemy_VerticalBomb(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 790,24,28,32 });
	fly.PushBack({ 819,24,28,32 });
	fly.PushBack({ 849,24,28,32 });
	fly.PushBack({ 882,24,28,32 });
	fly.PushBack({ 795,61,28,32 });
	fly.PushBack({ 831,61,28,32 });
	fly.PushBack({ 867,61,28,32 });
	fly.PushBack({ 897,61,28,32 });

	live = 5;


	fly.speed = 0.1f;
	animation = &fly;

	movement.PushBack({ 0.0f,2.0f }, 10000, &fly);


	collider = App->collision->AddCollider({ 0, 0, 28,41 }, COLLIDER_TYPE::COLLIDER_BOMB, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_VerticalBomb::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}