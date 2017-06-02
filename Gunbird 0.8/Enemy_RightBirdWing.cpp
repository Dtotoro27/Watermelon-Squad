#include "Application.h"
#include "Enemy_RightBirdWing.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "SDL/include/SDL_timer.h"





Enemy_RightBirdWing::Enemy_RightBirdWing(int x, int y) : Enemy(x, y)
{

	enemypos.PushBack({ 889,497,112,75 });

	animation = &enemypos;
	


	movement.PushBack({ 0.0f,-1.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);
	movement.PushBack({ 0.0f,-0.5f }, 50, &enemypos);
	movement.PushBack({ 0.0f,-1 }, 100, &enemypos);

	collider = App->collision->AddCollider({ 0, 0,87,80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	originalpos.x = x;
	originalpos.y = y;

	enemy = 16;
	hitpoints = 160,
	score = 4000;

}

void Enemy_RightBirdWing::Move()
{
	if (App->sea->pause == false) {



		position = originalpos + movement.GetCurrentPosition();

		if (left == true) {
			if (originalpos.x > +59 && timermove == 0) {
				originalpos.x--;
				if (originalpos.x == +59) {
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
			if (originalpos.x < 180 && timermove == 0) {
				originalpos.x++;
				if (originalpos.x == 180) {
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

void Enemy_RightBirdWing::Shoot() {
	if (App->sea->pause == false) {
		if (timer == 400) {
			if (left == true) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
			}
		}

		if (timer == 420) {
			if (left == true) {
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
				if (left == true) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				}
			}


			if (timer == 460) {
				if (left == true) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 41, position.y + 46, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 75, position.y + 53, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				}

				if (timer == 480) {

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				}
			}


			if (timer == 500) {
				if (left == true) {
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
				if (left == true) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				}
			}

			if (timer == 540) {
				if (left == true) {
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
				if (left == true) {
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 76, position.y + 37, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 52, position.y + 51, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);

					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, -1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 19, position.y + 54, 1.5f, 0.6f, COLLIDER_ENEMY_SHOT);
				}
			}

			if (timer == 580) {
				if (left == true) {
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