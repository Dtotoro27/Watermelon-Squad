#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "Enemy.h"
#include "Enemy_Balloon.h"
#include "Enemy_FlyingMachine.h"
#include "Enemy_FlyingMachine2.h"
#include "Enemy_FlyingMachine3.h"
#include "Enemy_FlyingMachine4.h"
#include "Enemy_Bomb.h"
#include "PowerUp.h"


#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("enemies.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{

		case ENEMY_TYPES::BALLOON:
			enemies[i] = new Enemy_Balloon(info.x, info.y);
			break;

		case ENEMY_TYPES::FLYINGMACHINE:
			enemies[i] = new Enemy_FlyingMachine(info.x, info.y);
			break;

		case ENEMY_TYPES::FLYINGMACHINE2:
			enemies[i] = new Enemy_FlyingMachine2(info.x, info.y);
			break;

		case ENEMY_TYPES::FLYINGMACHINE3:
			enemies[i] = new Enemy_FlyingMachine3(info.x, info.y);
			break;

		case ENEMY_TYPES::FLYINGMACHINE4:
			enemies[i] = new Enemy_FlyingMachine4(info.x, info.y);
			break;

		case ENEMY_TYPES::BOMB:
			enemies[i] = new Enemy_Bomb(info.x, info.y);
			break;

		case ENEMY_TYPES::POWER_UP:
			enemies[i] = new PowerUp(info.x, info.y);
			break;
		}

	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			if (c1->type == COLLIDER_POWER_UP) {
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			else if ((c1->type == COLLIDER_POWER_UP && c2->type == COLLIDER_ENEMY_SHOT) || (c1->type == COLLIDER_POWER_UP && c2->type == COLLIDER_ENEMY)) {}
			else if ((c2->type == COLLIDER_POWER_UP && c1->type == COLLIDER_ENEMY_SHOT) || (c2->type == COLLIDER_POWER_UP && c1->type == COLLIDER_ENEMY)) {}
			else if ((c1->type == COLLIDER_POWER_UP && c2->type == COLLIDER_BALLOON) || (c1->type == COLLIDER_POWER_UP && c2->type == COLLIDER_BALLOON)) {}

			else if (c1->type == COLLIDER_BALLOON) {
				App->particles->AddParticle(App->particles->explosion, enemies[i]->position.x-25, enemies[i]->position.y-25);
				App->audio->LoadFX("Audio/explosion.wav");
				App->player->score += 500;

				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			else {
				App->particles->AddParticle(App->particles->littleexplosion, enemies[i]->position.x - 10, enemies[i]->position.y - 5);
				App->audio->LoadFX("Audio/explosion.wav");
				App->player->score += 200;

				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
		
		}
	}
}