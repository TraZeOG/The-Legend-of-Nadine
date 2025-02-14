#include "music.h"


Mix_Music* init_music(char* music_path) {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* music = Mix_LoadMUS(music_path);
    return music;
}

void play_music(Mix_Music* music) {
    Mix_PlayMusic(music, -1);
}

void stop_music(Mix_Music* music) {
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}