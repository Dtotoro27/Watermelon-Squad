#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleMine.h"
#include "ModuleSea.h"

#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio() : Module()
{
}

// Destructor
ModuleAudio::~ModuleAudio()
{
}

// Called before render is available
bool ModuleAudio::Init()
{
	bool ret = true;
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	//Mix_PlayMusic(minemusic, -1);
	

	return ret;
}
	

// Called before q	uitting
bool ModuleAudio::CleanUp()
{
	if (minemusic != NULL) {
		Mix_FreeMusic(minemusic);
		Mix_FreeMusic(seamusic);
	}
	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}

  Mix_Music* const ModuleAudio::LoadMusic(const char* path)
{
	Mix_Music* currentmusic = NULL;
	currentmusic = Mix_LoadMUS(path);

	if (currentmusic == NULL)
	{
		LOG("Could not load music with path: %s. Mix Load Music: %s", path, Mix_GetError());
	}
	Mix_PlayMusic(currentmusic, -1);

	return currentmusic;
}



