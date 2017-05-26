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


	fly.PushBack({ 26,17,42,53 });

	fly.speed = 0.2f;
	animation = &fly;


	movement.PushBack({ 0.0f,-0.782f }, 350, &fly);

	collider = App->collision->AddCollider({ 0, 0, 42,53 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


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

	if (start_time == 0) {
		start_time = SDL_GetTicks();
	}

	now = SDL_GetTicks() - start_time;

	if (App->sea->pause == false) {

		if (now > 6000) {

			if (now >6000 && now < 6200 && shoot1==false) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 70, position.y + 26, 0.2f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 26, 0.9f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 77, position.y + 26, 2, 2, COLLIDER_ENEMY_SHOT);
				
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 2.75, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 70, position.y + 26, 0.1f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 26, 0.6f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 77, position.y + 26, 1, 1, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 2.75, 2, COLLIDER_ENEMY_SHOT);

				shoot1 = true;
				

			}

			if (now > 6200 && now < 6400 && shoot2==false) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 70, position.y + 26, 0.1f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 26, 0.6f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 77, position.y + 26, 1, 2, COLLIDER_ENEMY_SHOT);
			
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 1.95f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.40f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 70, position.y + 26, 0.1f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 26, 0.6f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 77, position.y + 26, 1, 1, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);

				shoot2 = true;
			}

			if (now > 6400 && now < 6600 && shoot3 == false) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 70, position.y + 26, 0.1f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 26, 0.6f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 77, position.y + 26, 1, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 70, position.y + 26, 0.1f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 26, 0.6f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 77, position.y + 26, 1, 1, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

				shoot3 = true;
			}

			if (now > 6600 && now < 6800 && shoot4 == false) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 70, position.y + 26, -0.1f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 75, position.y + 26, -0.6f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 77, position.y + 26, -1, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 70, position.y + 26,- 0.1f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 75, position.y + 26, -0.6f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 77, position.y + 26, -1, 1, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

				shoot4 = true;
			}

			if (now > 6800 && now < 7000 && shoot5 == false) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 70, position.y + 26, -0.1f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 75, position.y + 26, -0.6f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 77, position.y + 26, -1, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 1.95f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.40f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 70, position.y + 26, -0.1f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 75, position.y + 26,- 0.6f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 77, position.y + 26, -1, 1, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -2.75, 2, COLLIDER_ENEMY_SHOT);

				shoot5 = true;
			}

			if (now > 7000 && now < 7200 ) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 70, position.y + 26, -0.1f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 75, position.y + 26, -0.6f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x - 77, position.y + 26, -1, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 35, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 70, position.y + 26, -0.1f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 75, position.y + 26, -0.6f, 1, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x - 77, position.y + 26, -1, 1, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 0.3f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, -0.8, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 35, position.y + 26, 2.0f, 2, COLLIDER_ENEMY_SHOT);

				shoot1 = false;
				shoot2 = false;
				shoot3 = false;
				shoot4 = false;
				shoot5 = false;
				start_time = SDL_GetTicks();
			
			}

			

		}
	}

}

