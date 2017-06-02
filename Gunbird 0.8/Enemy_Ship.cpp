#include "Application.h"
#include "Enemy_Ship.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_Ship::Enemy_Ship(int x, int y) : Enemy(x, y)
{
	ship.PushBack({ 637,612,189,407 });
	ship.speed = 0.2;

	animation = &ship;



	movement.PushBack({ 0.3f,-1.0f }, 75, &ship);
	movement.PushBack({ 0.0f,-1.0f }, 40, &ship);
	movement.PushBack({ -0.3f,-1.0f }, 75, &ship);
	movement.PushBack({ 0.0f,-1.0f }, 40, &ship);


	originalpos.x = x;
	originalpos.y = y;

	enemy = 1;
	hitpoints = 0;
	score = 1000;
}

void Enemy_Ship::Move()
{
	if (App->sea->pause == false) {
		if (timer < 285) {
			originalpos.y++;
			timer++;
		}
		else {
		}
		position = originalpos + movement.GetCurrentPosition();
		if (App->collision->shipturret1 == true) {
			if (timer > 350 && timer < 490) {
				originalpos.y++;
				timer++;
			}
			else {
				timer++;
			}
		}

	}


}

void Enemy_Ship::Shoot() {

}