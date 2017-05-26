#include "Application.h"
#include "ModuleRender.h"
#include "ExtraBomb.h"
#include "ModuleSea.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

#include <time.h>
#include <stdio.h>




ExtraBomb::ExtraBomb(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 65,139,23,12 });
	fly.PushBack({ 94,139,23,12 });
	fly.PushBack({ 122,139,23,12 });
	fly.PushBack({ 150,139,23,12 });
	fly.PushBack({ 65,159,23,12 });
	fly.PushBack({ 94,159,23,12 });
	fly.PushBack({ 122,159,23,12 });
	fly.PushBack({ 150,159,23,12 });



	fly.speed = 0.1f;
	animation = &fly;




	collider = App->collision->AddCollider({ 0, 0, 23,12 }, COLLIDER_TYPE::COLLIDER_EXTRA_BOMB, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;



}

void ExtraBomb::Move()
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

