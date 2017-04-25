#include "Application.h"
#include "PowerUp.h"
#include "ModuleCollision.h"



PowerUp::PowerUp(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 62,185,21,10 });
	fly.PushBack({ 112,184,21,12 });
	fly.PushBack({ 162,184,21,12 });
	fly.PushBack({ 112,200,21,12 });
	fly.PushBack({ 162,200,21,12 });
	fly.PushBack({ 87,217,21,12 });
	fly.PushBack({ 162,217,21,12 });
	fly.PushBack({ 88,236,21,12 });

	

	fly.speed = 0.1f;
	animation = &fly;


	movement.PushBack({ 1.0f,-0.1f }, 52, &fly);
	movement.PushBack({ -1.0f,-0.1f }, 205, &fly);
	movement.PushBack({ 1.0f, -0.1f }, 75, &fly);
	movement.PushBack({ 1.0f, -2.0f }, 132, &fly);
	movement.PushBack({ -1.0f, -2.0f }, 20005, &fly);
	
	


	collider = App->collision->AddCollider({ 0, 0, 21,12 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void PowerUp::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}
