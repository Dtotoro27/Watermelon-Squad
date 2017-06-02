#include "Application.h"
#include "Enemy_ShipBackTurret.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_ShipBackTurret::Enemy_ShipBackTurret(int x, int y) : Enemy(x, y)
{


	base.PushBack({150,871,127,151 });

	animation = &base;

	shootopen.PushBack({ 289,871,127,151 });
	shootopen.PushBack({ 426,871,127,151 });
	shootopen.speed = 0.1f;
	shootopen.loop = false;

	shootclose.PushBack({ 426,871,127,151 });
	shootclose.PushBack({ 289,871,127,151 });
	shootclose.speed = 0.1f;
	shootclose.loop = false;

	movement.PushBack({ 0.3f,-1.0f }, 75, &base);
	movement.PushBack({ 0.0f,-1.0f }, 40, &base);
	movement.PushBack({ -0.3f,-1.0f }, 75, &base);
	movement.PushBack({ 0.0f,-1.0f }, 40, &base);


	start_time = SDL_GetTicks();
	originalpos.x = x;
	originalpos.y = y;

	enemy = 9; 
	hitpoints = 275;
	score = 10000;

}

void Enemy_ShipBackTurret::Move()
{
	if (App->sea->pause == false) {
		if (timer2 < 285) {
			originalpos.y++;
			timer2++;
		}
		else {
		}
		position = originalpos + movement.GetCurrentPosition();
		if (App->collision->shipturret1 == true) {
			if (timer2 > 350 && timer2 < 490) {
				originalpos.y++;
				timer2++;
			}
			else if (timer2 == 350) {
				collider = App->collision->AddCollider({ 0, 0, 127,122 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
				timer2++;
			}
			else {
				timer2++;
			}
		}

	
			
		
		


	}


}


void Enemy_ShipBackTurret::Shoot() {

	if (App->sea->pause == false) {
		if (App->collision->shipturret1 == true) {
			pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
			pos_y = App->player->position.y - position.y;
			module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
			v_x = 4 * (pos_x / module);
			v_y = (4 * (pos_y / module) - 1.88f);

			if (timer == 480) {
				animation = &shootopen;
				timer++;
			}



			if (timer == 500) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 27, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 27, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				timer++;
			}

			if (timer == 510) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 27, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 1.95f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 0.40f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 0.8, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 27, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, -0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, -2.75, 2, COLLIDER_ENEMY_SHOT);

				timer++;
			}

			if (timer == 520) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 27, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 33, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);


				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);


				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 27, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 33, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);


				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				timer++;
			}

			if (timer == 530) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 91, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 97, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 91, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 97, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);
				timer++;
			}

			if (timer == 540) {

				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 91, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 97, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 91, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 97, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				timer++;
			}

			if (timer == 550) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 91, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 97, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 91, position.y + 107, v_x + 0.5f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot_born, position.x + 97, position.y + 107, v_x - 0.5f, 2, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 0.75f, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x - 2.75, 2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 60, position.y + 110, v_x + 2.75, 2, COLLIDER_ENEMY_SHOT);
				timer++;
			}
			if (timer == 570) {
				animation = &shootclose;
				timer++;
			}

			if (timer == 590) {
				animation = &base;
				timer = 0;
			}
			else {
				timer++;
			}
		}
	}
}
