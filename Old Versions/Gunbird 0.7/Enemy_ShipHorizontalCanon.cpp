#include "Application.h"
#include "Enemy_ShipHorizontalCanon.h"
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



Enemy_ShipHorizontalCanon::Enemy_ShipHorizontalCanon(int x, int y) : Enemy(x, y)
{
	enemypos.PushBack({ 11,627,35,16 });

	shootopen.PushBack({ 49,627,35,16 });
	shootopen.PushBack({ 93,627,35,16 });
	shootopen.PushBack({ 134,627,35,16 });
	shootopen.loop = false;
	shootopen.speed = 0.1f;

	shootclose.PushBack({ 93,627,35,16 });
	shootclose.PushBack({ 134,627,35,16 });
	shootclose.PushBack({ 49,627,35,16 });
	shootclose.loop = false;
	shootclose.speed = 0.1;
	


	animation = &enemypos;

	collider = App->collision->AddCollider({ 0, 0,28,15 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	movement.PushBack({ 0.0f,-0.782f }, 100, &enemypos);



	originalpos.x = x;
	originalpos.y = y;

	enemy = 11;
	hitpoints = 28;
	score = 2000;

}

void Enemy_ShipHorizontalCanon::Move()
{

	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_ShipHorizontalCanon::Shoot() {
	if (App->sea->pause == false) {
		if (position.x < SCREEN_WIDTH && position.x > 0) {
			pos_x = (App->player->position.x - (ASH_WIDTH / 2)) - position.x;
			pos_y = App->player->position.y - position.y;
			module = sqrt((pos_x*pos_x) + (pos_y*pos_y));
			v_x = 4 * (pos_x / module);
			v_y = (4 * (pos_y / module) - 1.88f);
		}
		if (timer == 200) {
			animation = &shootopen;
			timer++;
		}
		if (timer == 250) {	
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 16, position.y + 4, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x+16 + 7, position.y + 4, v_x, v_y, COLLIDER_ENEMY_SHOT);
			timer++;

		}
		if (timer == 270) {
			App->particles->AddParticle(App->particles->big_enemy_shoot, position.x + 4, position.y + 4, v_x, v_y, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->big_enemy_shoot_born, position.x + 4, position.y + 4, v_x, v_y, COLLIDER_ENEMY_SHOT);
			timer++;
		}
		if (timer == 300) {
			animation = &shootclose;
			timer++;
		}
		if (timer == 330) {
			animation = &enemypos;
			timer = 0;
		}
		else {
			timer++;
		}
	}
}