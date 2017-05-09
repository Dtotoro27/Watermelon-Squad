#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

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
	//Mix_Init(MIX_INIT_OGG);
	//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	//if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
	//	LOG("Audio could not initialize. SDL_ERROR: %s", Mix_GetError());
	//	ret = false;
	//}

	return ret;
}


// Called before q	uitting
bool ModuleAudio::CleanUp()
{
	/*Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);*/
	return true;
}

bool ModuleAudio::LoadMusic(music musiclevel) {


	/*switch (musiclevel) {
	case music_level1:
		musicinexecution[musiclevel] = Mix_LoadMUS("assets/Audio/mine.ogg");
		Mix_PlayMusic(musicinexecution[musiclevel], -1);
		break;
	case music_welcome:
		musicinexecution[musiclevel] = Mix_LoadMUS("assets/Audio/characterselection.ogg");
		Mix_PlayMusic(musicinexecution[musiclevel],-1);
		break;
	case music_congrats:
		musicinexecution[musiclevel] = Mix_LoadMUS("assets/Audio/stageclear.ogg");
		Mix_PlayMusic(musicinexecution[musiclevel], -1);
		break;
	}*/

	return true;
}

bool ModuleAudio::UnLoadMusic(music musiclevel) {
	/*switch (musiclevel) {
	case music_level1:
		musicinexecution[musiclevel] = Mix_LoadMUS("assets/Audio/mine.ogg");
		Mix_FreeMusic(musicinexecution[musiclevel]);
		musicinexecution[musiclevel] = NULL;
		break;
	case music_welcome:
		musicinexecution[musiclevel] = Mix_LoadMUS("assets/Audio/characterselection.ogg");
		Mix_FreeMusic(musicinexecution[musiclevel]);
		musicinexecution[musiclevel] = NULL;
		break;
	case music_congrats:
		musicinexecution[musiclevel] = Mix_LoadMUS("assets/Audio/stageclear.ogg");
		Mix_FreeMusic(musicinexecution[musiclevel]);
		musicinexecution[musiclevel] = NULL;
		break;
	}*/

	return true;
}



uint ModuleAudio::LoadFX(const char* path) {

	uint ret = 0;

	/*Mix_Chunk* Audio = Mix_LoadWAV(path);

	if (Audio == nullptr) {
		LOG("Can't load fx");
	}
	else {
		fx_sound[last_fx] = Audio;
		ret = last_fx;
	}
	last_fx++;*/

	//fx_sound = Mix_LoadWAV(path);
	//Mix_PlayChannel(-1, fx_sound, 0);

	//if (fx_sound == NULL) {
	//	LOG("Error loading music: %s", Mix_GetError());
	//	ret = false;
	//}
	//if (Mix_PlayChannel(-1, fx_sound, 0) != 0) {
	//	LOG("Error playing music: %s", Mix_GetError());
	//	ret = false;
	//}

	return ret;
}

bool ModuleAudio::PlayFX(uint fx) {
	//Mix_PlayChannel(0, fx_sound[fx],0);
	return true;
}



