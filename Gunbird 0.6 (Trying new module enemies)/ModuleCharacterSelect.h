#ifndef __ModuleCharacterSelect_H__
#define __ModuleCharacterSelect_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleCharacterSelect : public Module
{
public:
	ModuleCharacterSelect();
	~ModuleCharacterSelect();

	bool Start();
	bool CleanUp();
	update_status Update();

public:
	bool change = true;
	SDL_Texture* characterselecttexture = nullptr;
	SDL_Texture* p1select = nullptr;
	SDL_Texture* characteranimation1 = nullptr;
	SDL_Texture* characteranimation2 = nullptr;
	SDL_Texture* clouds = nullptr;
	SDL_Texture* characterfaces=nullptr;
	SDL_Texture* ash_texture;
	SDL_Texture* marion_texture;
	SDL_Texture* valnus_texture;
	SDL_Texture* yuan_texture;
	SDL_Texture* tetsu_texture;
	SDL_Rect background;
	Animation p1,p2,cloud1,cloud2;
	Animation ash_face,marion_face,valnus_face,yuan_face,tetsu_face;
	Animation ash_name, marion_name, valnus_name, yuan_name,yuan_name_coop, tetsu_name;
	Animation ash_anim, marion_anim, valnus_anim, yuan_anim, tetsu_anim1,tetsu_anim2;
	Animation ash, marion, valnus, yuan, tetsu;
	
	Animation coins_indicator;
	Animation time_indicator;
	SDL_Texture* ui = nullptr;

	int font_time = -1;
	uint timer;

	int p1_x;
	int p2_x;
	int characterselected1 = 2;
	int characterselected2 = 4;
	float cloud1_x;
	float cloud2_x;
	bool coop = false;
	uint change_selection;

	int font_coins = -1;
	int delay3 = 0;
	


};

#endif

