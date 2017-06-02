#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"

#define MAX_ENEMIES 100

enum ENEMY_TYPES
{
	NO_TYPE,
	BALLOON,
	FLYINGMACHINE,
	FLYINGMACHINE2,
	FLYINGMACHINE4,
	BOMB,
	BOMB2,
	VERTICALBOMB,
	BLUETURRET,
	TOWER,
	SURFINGTURRET,
	SURFINGTURRET2,
	VERTICALSURFINGTURRET,
	UPSURFINGTURRET,
	STATICTURRET,
	STATICTURRET2,
	STATICTURRET3,
	STATICTURRET4,
	BLUEROBOT,
	BLUEROBOT2,
	REDMACHINE1,
	REDMACHINE2,
	SHIPTURRET,
	BIGSHIPSTATIC,
	BIGSHIPMOVE,
	SHIPHORIZONTALCANON,
	SHIPVERTICALCANON,
	SHIPVERTICALCANONLITTLE,
	SHIPBIGMIDDLETURRET,
	SHIPBACKTURRET,
	BIRDBODY,
	LEFTWINGBIRD,
	RIGHTWINGBIRD,
	EXTRABOMB,
	POWER_UP
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);
//	uint audio_explosion;

private:

	void SpawnEnemy(const EnemyInfo& info);

private:
	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
	SDL_Texture* pw_sprites;
	
public: 
	float damage;
	bool bossdefeated = false;
};

#endif // __ModuleEnemies_H__
