#include "Application.h"
#include "Enemy_ShipVerticalCanon.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>

#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)



Enemy_ShipVerticalCanon::Enemy_ShipVerticalCanon(int x, int y) : Enemy(x, y)
{


	enemy_position_sd.PushBack({ 766,287,26,36 });
	enemy_position_sd.speed = 0.2f;




	collider = App->collision->AddCollider({ 0, 0,26,33 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	movement.PushBack({ 0.0f,-0.782f }, 100, &enemy_position_s);



	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_ShipVerticalCanon::Move()
{

	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_ShipVerticalCanon::Shoot() {
	if (App->sea->pause == false) {

		now = SDL_GetTicks() - start_time;
		if (now >2000 || shoots>0) {
			if (now>1000) {
				if (position.x < SCREEN_WIDTH && position.x > 0) {
					pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
					pos_y = App->player->position.y - position.y;
					module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
					v_x = 4 * (pos_x / module);
					v_y = (4 * (pos_y / module) - 1.88f);

					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 26, v_x, v_y, COLLIDER_ENEMY_SHOT);
					App->particles->AddParticle(App->particles->enemy_shoot, position.x + 21, position.y + 13, v_x, v_y, COLLIDER_ENEMY_SHOT);
					start_time = SDL_GetTicks();
					shoots++;
					if (shoots >= 2) {
						shoots = 0;
					}
				}
			}
		}
	}
}