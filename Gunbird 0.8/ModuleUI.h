#ifndef _Module_UI_
#define _Module_UI_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleUI : public Module
{
private: 
	int delay3 = 0;
	uint timer;
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	//Textures
	SDL_Texture* ui = nullptr;

	//Animations
	Animation life_indicator_ash;
	Animation life_indicator_valnus;
	Animation start_player;
	Animation insert_coin;
	Animation p1, p2;
	Animation bomb_indicator;
	Animation coins_indicator;
	Animation game_over;
	Animation cont;
	Animation time_background;
	
	//Fonts
	int font_score;
	int font_coins;
	int font_time;

	//Pause
	bool destroyed = false;
	iPoint pause_position;
};

#endif // !MODULE_UI
