#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 1000

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	fPoint position;
	fPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, float speed_x, float speed_y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;
	

public:
	// Player Shoots
	Particle laser1_1;
	Particle laser1_2;
	Particle laser1_3;
	Particle laser2_1;
	Particle laser2_2;
	Particle laser2_3;
	Particle laser3_1;
	Particle laser3_2;
	Particle laser3_3;
	Particle laser4_1;
	Particle laser4_2;
	Particle laser4_3;
	Particle laser1_valnus_1;
	Particle laser1_valnus_2;
	Particle laser1_valnus_3;
	Particle laser2_valnus_1;
	Particle laser2_valnus_2;
	Particle laser2_valnus_3;
	Particle laser3_valnus_1;
	Particle laser3_valnus_2;
	Particle laser3_valnus_3;
	Particle laser4_valnus_1;
	Particle laser4_valnus_2;
	Particle laser4_valnus_3;
	Particle AshShootWave1;
	Particle AshShootWave2;
	Particle ValnusWave1_1;
	Particle ValnusWave1_2;
	Particle ValnusWave2_1;
	Particle ValnusWave2_2;

	// Explosions
	Particle explosion;
	Particle littleexplosion;

	// Damage particle
	Particle damage_balloon;
	Particle damage_bomb;
	Particle damage_turret;
	Particle damage_tower;
	Particle damage_blue_robot;
	Particle damage_red_machine;
	Particle damage_big_ship;
	Particle damage_shipbackturret;
	Particle damage_shipbigmiddleturret;
	Particle damage_horizontalcanon;
	Particle damage_shipturret;
	Particle damage_shipverticalcanonleft;
	Particle damage_shipverticalcanonright;
	Particle damage_bird_body;
	Particle damage_bird_lwing;
	Particle damage_bird_rwing;

	//Boss
	Particle bird_shoot;
	Particle bird_explosion;
	Particle smoke;

	// Enemy Shoots
	Particle enemy_shoot;
	Particle big_enemy_shoot;
	Particle enemy_shoot_born;
	Particle big_enemy_shoot_born;

	//Others
	Particle dead;
	Particle dead_valnus;
	Particle collision;
};

#endif // __MODULEPARTICLES_H__
