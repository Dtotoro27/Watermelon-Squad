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
	SDL_Texture* yuananimation = nullptr;
	SDL_Texture* tetsuanimation = nullptr;
	SDL_Texture* clouds = nullptr;
	SDL_Texture* characterfaces=nullptr;
	SDL_Rect background;
	Animation p1;
	Animation ash_face,marion_face,valnus_face,yuan_face,tetsu_face;
	Animation ash_name, marion_name, valnus_name, yuan_name, tetsu_name;
	Animation ash_anim, marion_anim, valnus_anim, yuan_anim, tetsu_anim;
	int p1_x;
	int characterselected;
	


};

#endif

