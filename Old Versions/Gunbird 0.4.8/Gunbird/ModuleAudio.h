#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_audio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


#define MAX_AUDIO 50
#define MAX_FX 500

enum music {
	music_welcome,
	music_level1,
	music_congrats
};

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool LoadMusic(music musiclevel);
	bool UnLoadMusic(music musiclevel);

	uint LoadFX(const char* path);
	bool PlayFX(uint fx);

private:
	Mix_Music* musicinexecution[MAX_AUDIO];
	Mix_Chunk* fx_sound[MAX_FX];
	uint ret = 0;
	uint last_fx = 1;
};

#endif

