#ifndef _ModuleSea_H_
#define _ModuleSea_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleSea : public Module
{
private: 
	int delay;
	float sea_speed;
	float sea_x;
public:
	ModuleSea();
	~ModuleSea();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	bool change = true;
	bool player2 = false;
	SDL_Texture* seatexture = nullptr;
	SDL_Texture* rocktexture = nullptr;
	SDL_Texture* startplayer2texture= nullptr;
	Animation startplayer2animation;
	Animation sea_animation;
	Animation p1, p2;
	Animation rock1;
	Animation rock2;
	Animation bomb_indicator;

	bool pause = false;
	


};

#endif