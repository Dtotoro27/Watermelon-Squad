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
	bool

public:
	Mix_Music* minemusic = nullptr;
	Mix_Music* seamusic = nullptr;
	Mix_Music* const ModuleAudio::LoadMusic(const char* path);
}

#endif
