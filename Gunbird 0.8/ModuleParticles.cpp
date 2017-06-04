#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	//handouts tienen aqui las animaciones
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	//Damages

	damage_balloon.anim.PushBack({ 684,157,42,53 });

	damage_bomb.anim.PushBack({ 790,177, 16, 31 });

	damage_turret.anim.PushBack({ 814,182,17,25 });

	damage_tower.anim.PushBack({ 837,150,64,100 });

	damage_blue_robot.anim.PushBack({1241,104,74,66});

	damage_red_machine.anim.PushBack({1326,159,25,36});

	damage_big_ship.anim.PushBack({732,159,51,68});

	damage_shipbackturret.anim.PushBack({1284,211,104,57});

	damage_shipbigmiddleturret.anim.PushBack({1137,196,141,86});

	damage_horizontalcanon.anim.PushBack({1142,152,31,16});

	damage_shipverticalcanonleft.anim.PushBack({1203,138,17,32});

	damage_shipverticalcanonright.anim.PushBack({ 1180,138,17,32 });

	damage_shipturret.anim.PushBack({1326,108,31,29});

	damage_bird_body.anim.PushBack({1386,5,86,157});

	damage_bird_lwing.anim.PushBack({ 1486,8,112,75 });

	damage_bird_rwing.anim.PushBack({ 1494,92,112,75 });

	




	//LASER ASH
	laser1_1.anim.PushBack({ 537, 38, 15, 29 });
	laser1_2.anim.PushBack({ 574,38,15,29 });
	laser1_3.anim.PushBack({ 503, 38, 15, 29 });

	laser1_1.anim.loop = laser1_2.anim.loop = laser1_3.anim.loop = true;
	laser1_1.anim.speed = laser1_2.anim.speed = laser1_3.anim.speed = 0.3f;
	laser1_1.life = laser1_2.life = laser1_3.life = 500;

	laser2_1.anim.PushBack({ 532, 77, 25, 37 });
	laser2_2.anim.PushBack({ 498, 77, 25, 37 });
	laser2_3.anim.PushBack({ 569, 77, 25, 37 });
	laser2_1.anim.speed = laser2_2.anim.speed= laser2_3.anim.speed = 0.3f;
	laser2_1.anim.loop = laser2_2.anim.loop = laser2_3.anim.loop = true;
	laser2_1.life = laser2_2.life= laser2_3.life=500;

	laser3_1.anim.PushBack({ 532, 124, 25, 37 });
	laser3_2.anim.PushBack({ 498, 124, 25, 37 });
	laser3_3.anim.PushBack({ 569, 124, 25, 37 });
	laser3_1.anim.speed = laser3_2.anim.speed = laser3_3.anim.speed =0.3f;
	laser3_1.anim.loop = laser3_2.anim.loop = laser3_3.anim.loop = true;
	laser3_1.life = laser3_2.life= laser3_3.life=500;

	laser4_1.anim.PushBack({ 530, 171, 29, 37 });
	laser4_2.anim.PushBack({ 496, 171, 29, 37 });
	laser4_3.anim.PushBack({ 567, 171, 29, 37 });
	laser4_1.anim.speed = laser4_2.anim.speed = laser4_3.anim.speed =0.3f;
	laser4_1.anim.loop = laser4_2.anim.loop= laser4_3.anim.loop= true;
	laser4_1.life = laser4_2.life= laser4_3.life=500;

	AshShootWave1.anim.PushBack({ 488, 272, 18, 22 });
	AshShootWave1.anim.PushBack({ 565, 272, 18, 22 });
	AshShootWave1.anim.PushBack({ 649, 272, 18, 22 });
	AshShootWave1.anim.PushBack({ 732, 272, 18, 22 });
	AshShootWave1.anim.speed = 0.2f;
	AshShootWave1.anim.loop = false;
	AshShootWave1.life = 500;

	AshShootWave2.anim.PushBack({ 474, 302, 32, 26 });
	AshShootWave2.anim.PushBack({ 557, 302, 32, 26 });
	AshShootWave2.anim.PushBack({ 632, 302, 32, 26 });
	AshShootWave2.anim.PushBack({ 718, 302, 32, 26 });
	AshShootWave2.anim.PushBack({ 805, 302, 32, 26 });
	AshShootWave2.anim.speed = 0.2f;
	AshShootWave2.anim.loop = false;
	AshShootWave2.life = 500;

	//LASER VALNUS 

	laser1_valnus_1.anim.PushBack({ 37, 386, 15, 19 });
	laser1_valnus_2.anim.PushBack({ 16,386,15,19 });
	laser1_valnus_3.anim.PushBack({ 55, 386, 15, 19 });

	laser1_valnus_1.anim.loop = laser1_valnus_2.anim.loop = laser1_valnus_3.anim.loop = true;
	laser1_valnus_1.anim.speed = laser1_valnus_2.anim.speed = laser1_valnus_3.anim.speed = 0.3f;
	laser1_valnus_1.life = laser1_valnus_2.life = laser1_valnus_3.life = 500;

	laser2_valnus_1.anim.PushBack({ 109, 386, 25, 28 });
	laser2_valnus_2.anim.PushBack({ 76, 386, 25, 28 });
	laser2_valnus_3.anim.PushBack({ 140, 386, 25, 28 });
	laser2_valnus_1.anim.speed = laser2_valnus_2.anim.speed = laser2_valnus_3.anim.speed = 0.3f;
	laser2_valnus_1.anim.loop = laser2_valnus_2.anim.loop = laser2_valnus_3.anim.loop = true;
	laser2_valnus_1.life = laser2_valnus_2.life = laser2_valnus_3.life = 500;

	laser3_valnus_1.anim.PushBack({ 55, 424, 31, 32 });
	laser3_valnus_2.anim.PushBack({ 17, 424, 31, 32 });
	laser3_valnus_3.anim.PushBack({ 90, 424, 31, 32 });
	laser3_valnus_1.anim.speed = laser3_2.anim.speed = laser3_valnus_3.anim.speed = 0.3f;
	laser3_valnus_1.anim.loop = laser3_valnus_2.anim.loop = laser3_valnus_3.anim.loop = true;
	laser3_valnus_1.life = laser3_valnus_2.life = laser3_valnus_3.life = 500;

	laser4_valnus_1.anim.PushBack({ 17, 462, 45,42 });
	laser4_valnus_2.anim.PushBack({ 66, 462, 45, 42 });
	laser4_valnus_3.anim.PushBack({ 113, 462, 45, 42 });
	laser4_valnus_1.anim.speed = laser4_valnus_2.anim.speed = laser4_valnus_3.anim.speed = 0.3f;
	laser4_valnus_1.anim.loop = laser4_valnus_2.anim.loop = laser4_valnus_3.anim.loop = true;
	laser4_valnus_1.life = laser4_valnus_2.life = laser4_valnus_3.life = 500;

	ValnusWave1_1.anim.PushBack({179,390,52,281});
	ValnusWave1_1.anim.PushBack({284 ,390,52,281 });
	ValnusWave1_1.anim.PushBack({389 ,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 494,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 599,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 704,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 809,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 914,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 1019,390,52,281 });
	ValnusWave1_1.anim.PushBack({ 1124,390,52,281 });
	ValnusWave1_1.anim.PushBack({1229 ,390,52,281 });
	ValnusWave1_1.anim.PushBack({1334 ,390,52,281 });
	ValnusWave1_1.anim.speed = 0.5f;
	ValnusWave1_1.anim.loop = false;

	ValnusWave1_2.anim.PushBack({ 231,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 336,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 441,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 546,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 651,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 756,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 861,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 966,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 1071,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 1176,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 1281,390,52,281 });
	ValnusWave1_2.anim.PushBack({ 1386,390,52,281 });
	ValnusWave1_2.anim.speed = 0.5f;
	ValnusWave1_2.anim.loop = false;

	ValnusWave2_1.anim.PushBack({ 179,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 315,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 451,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 587,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 723,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 859,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 995,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 1131,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 1267,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 1403,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 1539,675,67,287 });
	ValnusWave2_1.anim.PushBack({ 1675,675,67,287 });
	ValnusWave2_1.anim.speed = 0.5f;
	ValnusWave2_1.anim.loop = false;

	ValnusWave2_2.anim.PushBack({ 244,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 379,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 514,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 649,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 784,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 919,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 1054,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 1189,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 1324,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 1459,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 1594,675,67,287 });
	ValnusWave2_2.anim.PushBack({ 1729,675,67,287 });
	ValnusWave2_2.anim.speed = 0.5f;
	ValnusWave2_2.anim.loop = false;


	enemy_shoot.anim.PushBack({ 502, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 517, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 532, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 546, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 561, 235, 6,6 });
	enemy_shoot.anim.speed = 0.3f;
	enemy_shoot.anim.loop = true;
	enemy_shoot.life = 3000;


	big_enemy_shoot.anim.PushBack({501,243,8,8});
	big_enemy_shoot.anim.PushBack({ 501,243,8,8 });
	big_enemy_shoot.anim.PushBack({ 501,243,8,8 });
	big_enemy_shoot.anim.PushBack({ 501,243,8,8 });
	big_enemy_shoot.anim.speed = 0.3f;
	big_enemy_shoot.anim.loop = true;
	big_enemy_shoot.life = 3000;

	big_enemy_shoot_born.anim.PushBack({ 515,254,12,12 });
	big_enemy_shoot_born.life = 10;
	enemy_shoot_born.anim.PushBack({ 501, 256, 8,8 });
	enemy_shoot_born.life = 70;


	dead.anim.PushBack({ 631, 170, 31,26 }); 
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.loop = true;
	dead.life = 500;

	explosion.anim.PushBack({ 22,16, 105, 105 });
	explosion.anim.PushBack({ 126, 16, 105, 105 });
	explosion.anim.PushBack({ 236, 16, 105, 105 });
	explosion.anim.PushBack({ 350, 29, 105, 105 });
	explosion.anim.PushBack({ 26, 130, 105, 105 });
	explosion.anim.PushBack({ 129, 128, 105, 105 });
	explosion.anim.PushBack({ 238, 129, 105, 105 });
	explosion.anim.PushBack({ 352, 134, 105, 105 });
	explosion.anim.PushBack({ 24, 261, 105, 105 });
	explosion.anim.PushBack({ 124, 259, 105, 105 });
	explosion.anim.PushBack({ 231, 258, 105, 105 });
	explosion.anim.PushBack({ 345, 263, 105, 105 });
	explosion.anim.PushBack({});
	explosion.anim.speed = 0.3f;
	explosion.life = 500;
	explosion.anim.loop = false;
	

	littleexplosion.anim.PushBack({ 620,46,48,38 });
	littleexplosion.anim.PushBack({ 669,46,48,38 });
	littleexplosion.anim.PushBack({ 726,45,48,38 });
	littleexplosion.anim.PushBack({ 785,43,48,38 });
	littleexplosion.anim.PushBack({ 848,44,48,38 });
	littleexplosion.anim.PushBack({ 921,45,48,38 });
	littleexplosion.anim.PushBack({ 622,104,48,38 });
	littleexplosion.anim.PushBack({ 689,105,48,38 });
	littleexplosion.anim.PushBack({ 755,107,48,38 });
	littleexplosion.anim.PushBack({ 824,105,48,38 });
	littleexplosion.anim.PushBack({ 883,105,48,38 });
	littleexplosion.anim.PushBack({ 946,102,48,38 });
	littleexplosion.anim.PushBack({ 982,105,48,38 });
	littleexplosion.anim.speed = 0.8f;
	littleexplosion.anim.loop = false;

	dead_valnus.anim.PushBack({632,202,32,38});
	dead_valnus.life = 500;

	collision.anim.PushBack({ 1057,10,31,31 });
	collision.anim.PushBack({ 1094,10,31,31 });
	collision.anim.PushBack({ 1132,13,31,31 });
	collision.anim.PushBack({ 1168,14,31,31 });
	collision.anim.PushBack({ 1209,14,31,31 });
	collision.anim.PushBack({ 1246,15,31,31 });
	collision.anim.PushBack({ 1058,49,31,31 });
	collision.anim.PushBack({ 1094,51,31,31 });
	collision.anim.PushBack({ 1133,52,31,31 });
	collision.anim.PushBack({ 1174,55,31,31 });
	collision.anim.PushBack({ 1211,54,31,31 });
	collision.anim.PushBack({ 1249,54,31,31 });
	collision.anim.PushBack({ 1059,92,31,31 });
	collision.anim.PushBack({ 1097,92,31,31 });
	collision.anim.PushBack({ 1135,92,31,31 });
	collision.anim.PushBack({ 1173,92,31,31 });
	collision.anim.speed = 0.5f;

	bird_explosion.anim.PushBack({10,1121,222,222});
	bird_explosion.anim.PushBack({ 234,1121,222,222 });
	bird_explosion.anim.PushBack({ 458,1121,222,222 });
	bird_explosion.anim.PushBack({ 682,1121,222,222 });
	bird_explosion.anim.PushBack({ 906,1121,222,222 });
	bird_explosion.anim.PushBack({ 1130,1121,222,222 });
	bird_explosion.anim.PushBack({ 1354,1121,222,222 });
	bird_explosion.anim.PushBack({ 1578,1121,222,222 });
	bird_explosion.anim.PushBack({ 1354,1121,222,222 });
	bird_explosion.anim.PushBack({ 1578,1121,222,222 });
	bird_explosion.anim.PushBack({ 1354,1121,222,222 });
	bird_explosion.anim.PushBack({ 1578,1121,222,222 });
	bird_explosion.anim.PushBack({ 1354,1121,222,222 });
	bird_explosion.anim.PushBack({ 1578,1121,222,222 });
	bird_explosion.anim.PushBack({ 1354,1121,222,222 });
	bird_explosion.anim.PushBack({ 1578,1121,222,222 });
	bird_explosion.anim.PushBack({ 1354,1121,222,222 });
	bird_explosion.anim.PushBack({ 1578,1121,222,222 });
	bird_explosion.anim.PushBack({ 10,1345,222,222 });
	bird_explosion.anim.PushBack({ 234,1345,222,222 });
	bird_explosion.anim.PushBack({ 458,1345,222,222 });
	bird_explosion.anim.PushBack({ 682,1345,222,222 });
	bird_explosion.anim.PushBack({ 906,1345,222,222 });
	bird_explosion.anim.PushBack({ 1130,1345,222,222 });
	bird_explosion.anim.PushBack({ 1354,1345,222,222 });
	bird_explosion.anim.PushBack({ 1578,1345,222,222 });
	bird_explosion.anim.speed = 0.3f;

	smoke.anim.PushBack({27,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 27,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 88,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 88,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 151,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 151,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 212,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 212,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 279,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 279,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 359,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 359,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 428,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 428,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 497,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 497,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 568,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 568,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 632,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 632,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 692,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 692,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 761,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 761,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 825,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 825,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 888,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 888,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 954,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 954,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 1023,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.PushBack({ 1023,1745,52,182 });
	smoke.anim.PushBack({});
	smoke.anim.speed = 0.3f;
	smoke.anim.loop = false;

}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");

	graphics = App->textures->Load("assets/particles.png");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}
	App->particles->Disable();
	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, float speed_x, float speed_y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			p->speed.x = speed_x;
			p->speed.y = speed_y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}