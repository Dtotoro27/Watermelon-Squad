#include "Application.h"
#include "Ship_Corpse.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"




Ship_Corpse::Ship_Corpse(int x, int y) : Enemy(x, y)
{

	base.PushBack({ 659, 22,62,105 });
	base.PushBack({ 726, 9,62,105 });
	base.speed = 0.3f;


	animation = &base;

	movement.PushBack({ 0.0f,-0.825f }, 50, &base);
	

	collider = App->collision->AddCollider({ 0, 0, 63, 63 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;

	enemy = 20;
	hitpoints = 60;
	score = 1000;
}

void Ship_Corpse::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Ship_Corpse::Shoot() {
	
}