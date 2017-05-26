#include "Application.h"
#include "Enemy_Tower.h"
#include "ModuleCollision.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleSea.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

#include <math.h>


Enemy_Tower::Enemy_Tower(int x, int y) : Enemy(x, y)
{
	live = 40; 

	stand.PushBack({ 5,259,64,100});
	stand.PushBack({ 70,259,64,100 });
	stand.PushBack({ 135,259,64,100 });
	stand.PushBack({ 200,259,64,100 });
	stand.PushBack({ 265,259,64,100 });
	stand.PushBack({ 330,259,64,100 });
	stand.PushBack({ 330,259,64,100 });
	stand.PushBack({ 330,259,64,100 });
	stand.PushBack({ 265,259,64,100 });
	stand.PushBack({ 200,259,64,100 });
	stand.PushBack({ 135,259,64,100 });
	stand.PushBack({ 70,259,64,100 });
	stand.PushBack({ 5,259,64,100 });
	stand.PushBack({ 5,259,64,100 });

	stand.speed = 0.3f;
	animation = &stand;


	movement.PushBack({ 0.0f,-0.782f },350, &stand);


	collider = App->collision->AddCollider({ 0, 0, 64,100 }, COLLIDER_TYPE::COLLIDER_TOWER, (Module*)App->enemies);

	originalpos.x = x;
	originalpos.y = y;


}

void Enemy_Tower::Move()
{
	if (App->sea->pause == false) {
		position = originalpos + movement.GetCurrentPosition();
	}
}

void Enemy_Tower::Shoot() {
	if (App->sea->pause == false) {

	
			if (time == 0) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 22, position.y + 37, -0.8, 0.3, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 34, position.y + 37, 0.8, 0.3, COLLIDER_ENEMY_SHOT);
				time++;
			}
			
			if (time == 3) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 22, position.y + 35, -1.3, -0.2, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 34, position.y + 35, 1.3, -0.2, COLLIDER_ENEMY_SHOT);
				time++;
			}
			
			if (time == 6) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 22, position.y + 32, -1.5, -0.85, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 34, position.y + 32, 1.5, -0.85, COLLIDER_ENEMY_SHOT);
				time++;
			}
			
			if (time == 9) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 22, position.y + 30, -1.5, -1.5, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 34, position.y + 30, 1.5, -1.5, COLLIDER_ENEMY_SHOT);
				time++;
			}
			
			if (time == 12) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 22, position.y + 28, -1.3, -2.35, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 34, position.y + 28, 1.3, -2.35, COLLIDER_ENEMY_SHOT);
				time++;
			}
			
			if (time == 15) {
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 22, position.y + 26, -0.8, -2.8, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->enemy_shoot, position.x + 34, position.y + 26, 0.8, -2.8, COLLIDER_ENEMY_SHOT);
				time++;
			}
			else {
				time++;
			}
			if (time == 52) {
				time = 0;
			}
		
	}
}