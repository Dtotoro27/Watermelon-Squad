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
	damage_balloon.anim.PushBack({ 684,157,42,53 });
	damage_balloon.anim.PushBack({ 735,157,42,53 });
	damage_balloon.anim.speed = 1;
	damage_balloon.anim.loop = false;

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

	enemy_shoot.anim.PushBack({ 502, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 517, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 532, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 546, 235, 6,6 });
	enemy_shoot.anim.PushBack({ 561, 235, 6,6 });
	enemy_shoot.anim.speed = 0.3f;
	enemy_shoot.anim.loop = true;

	enemy_shoot.life = 2000;

	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.PushBack({ 631, 170, 31,26 });
	dead.anim.speed = 0.1f;
	dead.anim.loop = true;

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
	explosion.anim.speed = 0.8f;
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
	dead_valnus.anim.speed = 0.1f;
	dead_valnus.anim.loop = true;
	
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