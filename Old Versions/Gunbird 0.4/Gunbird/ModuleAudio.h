#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_audio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


#define MAX_AUDIO 50;

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();
	bool LoadMusic(const char* path);
	bool LoadFX(const char* path);

public:
	Mix_Music* music = nullptr;
	Mix_Chunk* fx_sound = nullptr;
};

#endif
