#include "Application.h"
#include "Enemy_ShipBigMiddleTurret.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_ShipBigMiddleTurret::Enemy_ShipBigMiddleTurret(int x, int y) : Enemy(x, y)
{


	base.PushBack({ 6,683,140,86 });

	animation = &base;

	shootopen.PushBack({ 5,772,145,51 });
	shootopen.PushBack({ 5,824,145,51 });
	shootopen.speed = 0.1f;
	shootopen.loop = false;

	shootclose.PushBack({ 5,824,144,48 });
	shootclose.PushBack({ 5,772,144,48 });
	shootclose.speed = 0.1f;
	shootclose.loop = false;

	movement.PushBack({ 0.0f,-0.783f}, 350, &base);

	collider = App->collision->AddCollider({ 0, 0, 141,51 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	start_time = SDL_GetTicks();
	originalpos.x = x;
	originalpos.y = y;

}

void Enemy_ShipBigMiddleTurret::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}

}


void Enemy_ShipBigMiddleTurret::Shoot() {

	if (App->sea->pause == false) {
		if (timer == 480) {
			animation10 = &shootopen;
			timer++;
		}

		if (timer == 500) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 108, position.y + 37, 0.2f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 115, position.y + 37, 0.9f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 122, position.y + 37, 2, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 2.75, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 108, position.y +37, 0.1f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 115, position.y + 37, 0.6f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 122, position.y + 37, 1, 1, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 2.75, 2, COLLIDER_ENEMY_SHOT);

			timer++;
		}

		if (timer == 510) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 108, position.y + 37, 0.2f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 115, position.y + 37, 0.9f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 122, position.y + 37, 2, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 1.95f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.40f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 108, position.y + 37, 0.1f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 115, position.y + 37, 0.6f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 122, position.y + 37, 1, 1, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);

			timer++;
		}

		if (timer == 520) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 108, position.y + 37, 0.2f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 115, position.y + 37, 0.9f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 122, position.y + 37, 2, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 108, position.y + 37, 0.1f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 115, position.y + 37, 0.6f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 122, position.y + 37, 1, 1, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

			timer++;
		}

		if (timer == 530) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 16, position.y + 37, -0.1f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 23, position.y + 37, -0.6f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 30, position.y + 37, -1, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 16, position.y + 37, -0.1f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 23, position.y + 37, -0.6f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 30, position.y + 37, -1, 1, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

			timer++;
		}

		if (timer == 540) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 16, position.y + 37, -0.1f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 23, position.y + 37, -0.6f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 30, position.y + 37, -1, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 1.95f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.40f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 16, position.y + 37, -0.1f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 23, position.y + 37, -0.6f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 30, position.y + 37, -1, 1, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);

			timer++;
		}

		if (timer == 550) {

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 16, position.y + 37, -0.1f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 23, position.y + 37, -0.6f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 30, position.y + 37, -1, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot, position.x + 69, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 16, position.y + 37, -0.1f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 23, position.y + 37, -0.6f, 1, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 30, position.y + 37, -1, 1, COLLIDER_ENEMY_SHOT);

			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 69, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);
			timer++;
		}
		if (timer == 570) {
			animation10 = &shootclose;
			timer++;
		}

		if (timer == 590) {
			animation10 = nullptr;
			timer = 0;
		}
		else {
			timer++;
		}
	}
}