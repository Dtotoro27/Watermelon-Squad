#include "Application.h"
#include "ModuleRender.h"
#include "PowerUp.h"
#include "ModuleSea.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include <time.h>
#include <stdio.h>




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
	


	collider = App->collision->AddCollider({ 0, 0, 21,12 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	

}

void PowerUp::Move()
{
	if (up == true)
		position.y -= 2; //si se cambia esta speed, por algun motivo desconocido deja de ir, NO TOCAR!
	else
		position.y += 1; 

	if (left == true)
		position.x -= 1;
	else
		position.x += 1;

	if (position.x < App->render->camera.x)
		left = false;

	else if (position.x > SCREEN_WIDTH - 21)
		left = true;

	 if (position.y > App->player->camera_limits.y + (SCREEN_HEIGHT - 13))
		up = true;

	 else if (position.y  < App->player->camera_limits.y)
		 up = false;
}


