#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

Enemy::Enemy(int x, int y) : position(x, y)
{}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;


}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation4 != nullptr) {
		App->render->Blit(sprites, position.x - 32, position.y + 2, &(animation4->GetCurrentFrame()));
	}
	if (animation11 != nullptr) {
		App->render->Blit(sprites, position.x, position.y + 30, &(animation11->GetCurrentFrame()));
	}
	if (animation7 != nullptr) {
		App->render->Blit(sprites, position.x, position.y - 30, &(animation7->GetCurrentFrame()));
	}
	if (animation3 != nullptr) {
		App->render->Blit(sprites, position.x + 29, position.y + 2, &(animation3->GetCurrentFrame()));
	}
	
	if (animation != nullptr) {
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
	}
	if (animation2 != nullptr) {
		App->render->Blit(sprites, position.x - 2 , position.y -8, &(animation2->GetCurrentFrame()));
	}
	
	if (animation5 != nullptr) {
		App->render->Blit(sprites, position.x +1 , position.y - 7, &(animation5->GetCurrentFrame()));
	}
	if (animation6 != nullptr) {
		App->render->Blit(sprites, position.x + 7, position.y +10, &(animation6->GetCurrentFrame()));
	}
	if (animation8 != nullptr) {
		App->render->Blit(sprites, position.x + 6, position.y + 15, &(animation8->GetCurrentFrame()));
	}
	if (animation9 != nullptr) {
		App->render->Blit(sprites, position.x + 9, position.y + 107, &(animation9->GetCurrentFrame()));
	}
	if (animation10 != nullptr) {
		App->render->Blit(sprites, position.x-2, position.y-4, &(animation10->GetCurrentFrame()));
	}
	if (animation12 != nullptr) {
		App->render->Blit(sprites, position.x - 59, position.y +4, &(animation12->GetCurrentFrame()));
	}
	if (animation13 != nullptr) {
		App->render->Blit(sprites, position.x + 86, position.y + 110, &(animation13->GetCurrentFrame()));
	}

	

	if (collider != nullptr && enemy == 14)
		collider->SetPos(position.x + 100, position.y);

	if (collider != nullptr && enemy == 16)
		collider->SetPos(position.x + 10, position.y);
	


}

void Enemy::OnCollision(Collider* collider)
{
	
}
