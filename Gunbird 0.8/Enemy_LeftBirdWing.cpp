#include "Application.h"
#include "Enemy_LeftBirdWing.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "SDL/include/SDL_timer.h"





Enemy_LeftBirdWing::Enemy_LeftBirdWing(int x, int y) : Enemy(x, y)
{

	enemypos.PushBack({ 748,497,112,75 });

	animation = &enemypos;




	movement.PushBack({ 0.0f,-1.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);
	movement.PushBack({ 0.0f,-0.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);

	collider = App->collision->AddCollider({ 0, 0,87,80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	originalpos.x = x;
	originalpos.y = y;

	enemy = 15;
	hitpoints = 160,
	score = 4000;

}

void Enemy_LeftBirdWing::Move()
{

	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();

		if (left == true) {
			if (originalpos.x > -82 && timermove == 0) {
				originalpos.x--;
				if (originalpos.x == -82) {
					timermove = 1;
				}
			}

			else if (timermove > 0) {
				if (App->player->position.x < SCREEN_WIDTH / 2) {
					timermove++;
					if (timermove > 100) {
						left = false;
						right = true;
						timermove = 0;
					}
				}
			}
		}

		else if (right == true) {
			if (originalpos.x < 38 && timermove == 0) {
				originalpos.x++;
				if (originalpos.x == 38) {
					timermove = 1;
				}
			}
			else if (timermove > 0) {
				if (App->player->position.x > SCREEN_WIDTH / 2) {
					timermove++;
					if (timermove > 100) {
						right = false;
						left = true;
						timermove = 0;
					}
				}
			}
		}

	}
}

void Enemy_LeftBirdWing::Shoot() {
	if (App->sea->pause == false) {
		
		
		if (timer == 400) {
			if (right == true) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (right == true) {
			if (timer == 420) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 440) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}


		if (timer == 460) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 480) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 500) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 520) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}

			if (timer == 540) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 560) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 57, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 90, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 580) {
			if (right == true) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 580) {
			timer = 0;
		}

		else {
			timer++;
		}
	}
}
