#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "Enemy.h"
#include "Enemy_Balloon.h"
#include "Enemy_FlyingMachine.h"
#include "Enemy_FlyingMachine2.h"
#include "Enemy_FlyingMachine4.h"
#include "Enemy_Bomb.h"
#include "Enemy_Bomb2.h"
#include "Enemy_VerticalBomb.h"
#include "Enemy_Tower.h"
#include "Enemy_SurfingTurret.h"
#include "Enemy_SurfingTurret2.h"
#include "Enemy_VerticalSurfingTurret.h"
#include "Enemy_StaticTurret.h"
#include "Enemy_StaticTurret2.h"
#include "Enemy_StaticTurret3.h"
#include "Enemy_StaticTurret4.h"
#include "Enemy_BlueTurret.h"
#include "Enemy_BlueRobot.h"
#include "Enemy_BlueRobot2.h"
#include "Enemy_RedMachine1.h"
#include "Enemy_RedMachine2.h"
#include "Enemy_ShipTurret.h"
#include "Enemy_BigShipStatic.h"
#include "Enemy_BigShipMove.h"
#include "Enemy_ShipHorizontalCanon.h"
#include "Enemy_ShipVerticalCanon.h"
#include "Enemy_ShipVerticalCanonLittle.h"
#include "Enemy_ShipBigMiddleTurret.h"
#include "Enemy_ShipBackTurret.h"
#include "ExtraBomb.h"
#include "PowerUp.h"


#define SPAWN_MARGIN 120

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
	sprites = App->textures->Load("assets/enemies.png");
	//audio_explosion = App->audio->LoadFX("assets/Audio/explosion.wav");



	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{

			if (queue[i].y * SCREEN_SIZE < App->render->camera.y + (App->render->camera.h * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].y * SCREEN_SIZE);
			}
		}
	}


	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			enemies[i]->Move();
		}
	}

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			enemies[i]->Shoot();
		}
	}

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			enemies[i]->Draw(sprites);
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{

			if (enemies[i]->position.y < App->player->camera_limits.y - SPAWN_MARGIN)
			{

				LOG("DeSpawning enemy at %d", enemies[i]->position.y * SCREEN_SIZE);
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

		case ENEMY_TYPES::FLYINGMACHINE4:
			enemies[i] = new Enemy_FlyingMachine4(info.x, info.y);
			break;

		case ENEMY_TYPES::BOMB:
			enemies[i] = new Enemy_Bomb(info.x, info.y);
			break;

		case ENEMY_TYPES::BOMB2:
			enemies[i] = new Enemy_Bomb2(info.x, info.y);
			break;

		case ENEMY_TYPES::VERTICALBOMB:
			enemies[i] = new Enemy_VerticalBomb(info.x, info.y);
			break;

		case ENEMY_TYPES::POWER_UP:
			enemies[i] = new PowerUp(info.x, info.y);
			break;

		case ENEMY_TYPES::TOWER:
			enemies[i] = new  Enemy_Tower(info.x, info.y);
			break;

		case ENEMY_TYPES::SURFINGTURRET:
			enemies[i] = new  Enemy_SurfingTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::SURFINGTURRET2:
			enemies[i] = new  Enemy_SurfingTurret2(info.x, info.y);
			break;

		case ENEMY_TYPES::VERTICALSURFINGTURRET:
			enemies[i] = new  Enemy_VerticalSurfingTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::STATICTURRET:
			enemies[i] = new  Enemy_StaticTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::STATICTURRET2:
			enemies[i] = new  Enemy_StaticTurret2(info.x, info.y);
			break;

		case ENEMY_TYPES::STATICTURRET3:
			enemies[i] = new  Enemy_StaticTurret3(info.x, info.y);
			break;

		case ENEMY_TYPES::STATICTURRET4:
			enemies[i] = new  Enemy_StaticTurret4(info.x, info.y);
			break;

		case ENEMY_TYPES::BLUETURRET:
			enemies[i] = new  Enemy_BlueTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::BLUEROBOT:
			enemies[i] = new  Enemy_BlueRobot(info.x, info.y);
			break;

		case ENEMY_TYPES::BLUEROBOT2:
			enemies[i] = new  Enemy_BlueRobot2(info.x, info.y);
			break;

		case ENEMY_TYPES::REDMACHINE1:
			enemies[i] = new  Enemy_RedMachine1(info.x, info.y);
			break;

		case ENEMY_TYPES::REDMACHINE2:
			enemies[i] = new  Enemy_RedMachine2(info.x, info.y);
			break;

		case ENEMY_TYPES::SHIPTURRET:
			enemies[i] = new  Enemy_ShipTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::BIGSHIPSTATIC:
			enemies[i] = new  Enemy_BigShipStatic(info.x, info.y);
			break;

		case ENEMY_TYPES::BIGSHIPMOVE:
			enemies[i] = new  Enemy_BigShipMove(info.x, info.y);

		case ENEMY_TYPES::SHIPHORIZONTALCANON:
			enemies[i] = new  Enemy_ShipHorizontalCanon(info.x, info.y);
			break;
		case ENEMY_TYPES::SHIPVERTICALCANONLITTLE:
			enemies[i] = new  Enemy_ShipVerticalCanonLittle(info.x, info.y);
			break;
		case ENEMY_TYPES::SHIPVERTICALCANON:
			enemies[i] = new  Enemy_ShipVerticalCanon(info.x, info.y);
			break;

		case ENEMY_TYPES::SHIPBIGMIDDLETURRET:
			enemies[i] = new  Enemy_ShipBigMiddleTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::SHIPBACKTURRET:
			enemies[i] = new  Enemy_ShipBackTurret(info.x, info.y);
			break;

		case ENEMY_TYPES::EXTRABOMB:
			enemies[i] = new  ExtraBomb(info.x, info.y);
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
			
			if (c1->type == COLLIDER_EXTRA_BOMB) {
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			
			if (c1->type == COLLIDER_ENEMY) {

				if (App->player->powerUps == 0) { damage = 1; }
				if (App->player->powerUps == 1) { damage = 2; }
				if (App->player->powerUps == 2) { damage = 3; }
				if (App->player->powerUps == 3) { damage = 4; }


				//BALLOON
				if (enemies[i]->enemy == 0) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}


				else if(enemies[i]->enemy == 1) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 2) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 3) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 4) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 5) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 6) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 7) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
				else if (enemies[i]->enemy == 8) {
					if (enemies[i]->hitpoints > 0) {
						if (c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_VALNUS_2_LASER) {
							enemies[i]->hitpoints = enemies[i]->hitpoints - (damage / 10);
						}
						else {
							enemies[i]->hitpoints = enemies[i]->hitpoints - damage;
						}
					}
					else {
						if (c2->type == COLLIDER_PLAYER_2_SHOT || c2->type == COLLIDER_VALNUS_2_LASER || c2->type == COLLIDER_ASH_BOMB_2) {
							App->player2->score += enemies[i]->score;
						}
						if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_VALNUS_LASER || c2->type == COLLIDER_ASH_BOMB) {
							App->player->score += enemies[i]->score;
						}
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
			}
		}
	}
}