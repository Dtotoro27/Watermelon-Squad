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

	/*
	pw_anim.PushBack({ 4, 32, 21, 10 });
	pw_anim.PushBack({ 54, 31, 21, 12 });
	pw_anim.PushBack({ 104, 31, 21, 12 });
	pw_anim.PushBack({ 54, 47, 21, 12 });
	pw_anim.PushBack({ 104, 47, 21, 12 });
	pw_anim.PushBack({ 29, 64, 21, 12 });
	pw_anim.PushBack({ 104, 64, 21, 12 });
	pw_anim.PushBack({ 30, 83, 21, 12 });
	pw_anim.speed = 0.1f;  */


	fly.speed = 0.1f;
	animation = &fly;

	movement.PushBack({ 0.0f,-0.78f }, 50, &fly);

	collider = App->collision->AddCollider({ 0, 0, 21,12 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void PowerUp::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}
