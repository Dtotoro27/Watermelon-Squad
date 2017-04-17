#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"

Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 11,6,41,52 });
	fly.PushBack({ 11,6,41,52 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 41,52 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_x = x;


}

void Enemy_Balloon::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = original_x + (25.0f * sinf(wave));
	position.x -= 1;
}
