#include "Application.h"
#include "Enemy_Bomb.h"
#include "ModuleCollision.h"



Enemy_Bomb::Enemy_Bomb(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 790,24,28,32 });
	fly.PushBack({ 819,24,28,32 });
	fly.PushBack({ 849,24,28,32 });
	fly.PushBack({ 882,24,28,32 });
	fly.PushBack({ 795,61,28,32 });
	fly.PushBack({ 831,61,28,32 });
	fly.PushBack({ 867,61,28,32 });
	fly.PushBack({ 897,61,28,32 });


	fly.speed = 0.1f;
	animation = &fly;

	if (bomb_num == 1) {
		movement.PushBack({ 0.5f,1.0f }, 10000, &fly);
		bomb_num++;
	}
	else if (bomb_num == 1) {
		movement.PushBack({ 0.0f,-1.0f }, 20, &fly);
		movement.PushBack({ 0.5f,1.0f }, 10000, &fly);
		bomb_num++;
	}
	else if (bomb_num == 1) {
		movement.PushBack({ 0.0f,-1.0f }, 40, &fly);
		movement.PushBack({ 0.5f,1.0f }, 10000, &fly);
		bomb_num++;
	}
	else if (bomb_num == 1) {
		movement.PushBack({ 0.0f,-1.0f }, 60, &fly);
		movement.PushBack({ 0.5f,1.0f }, 10000, &fly);
		bomb_num == 1;
	}
	

	collider = App->collision->AddCollider({ 0, 0, 28,41 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_Bomb::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}
